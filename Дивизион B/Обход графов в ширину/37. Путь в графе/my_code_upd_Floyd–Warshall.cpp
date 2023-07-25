#include <iostream>
#include <vector> 
#include <algorithm>
#include <limits>

using namespace std;

int main() {


    // input

    int CountVertexes; cin >> CountVertexes; // == число N – количество вершин в графе (1 ≤ N ≤ 100)

    vector<vector<int>> AdjacencyMatrix(CountVertexes + 1, vector<int>(CountVertexes + 1));
    vector<vector<int>> Next(CountVertexes + 1, vector<int>(CountVertexes + 1));

    for (int i = 1; i < CountVertexes + 1; i++) {
        for (int j = 1; j < CountVertexes + 1; j++) {

            cin >> AdjacencyMatrix[i][j];

            if (AdjacencyMatrix[i][j]) { Next[i][j] = j; }
            if (i == j) { Next[i][i] = i; } // данный код имеет место быть так как на главной диагонали AdjacencyMatrix стоят нули == у каждой вершины есть петли с нулевым весом

            if ((AdjacencyMatrix[i][j] == 0 && i != j)) { AdjacencyMatrix[i][j] = numeric_limits<int>::max(); }

        }
    }


    // solution

    int VertexBegin, VertexEnd; cin >> VertexBegin >> VertexEnd;

    // 18	presentation-error --> см. тест ниже!
    if (VertexBegin == VertexEnd) { // " Если путь имеет длину 0, то его выводить не нужно, достаточно вывести длину."
        cout << 0;
        return 0;
    }


    for (int k = 1; k < CountVertexes + 1; ++k) {
        for (int i = 1; i < CountVertexes + 1; ++i) {
            for (int j = 1; j < CountVertexes + 1; ++j) {

                if (AdjacencyMatrix[i][k] < numeric_limits<int>::max() &&
                    AdjacencyMatrix[k][j] < numeric_limits<int>::max() &&
                    AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j] < AdjacencyMatrix[i][j]) {

                    AdjacencyMatrix[i][j] = AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j];
                    Next[i][j] = Next[i][k]; // так как путь через вершины {1, ..., k} короче, нежели через вершины {1, ..., k - 1}, то путь должен пролегать через вершину k: i -> ... -> k -> ... -> j

                }

            }
        }
    }


    // output

    //for (int i = 0; i < CountVertexes + 1; ++i) {
    //    for (int j = 0; j < CountVertexes + 1; ++j) {

    //        cout << Next[i][j] << ' ';

    //    }
    //    cout << '\n';
    //}


    if (AdjacencyMatrix[VertexBegin][VertexEnd] == numeric_limits<int>::max()) {
        cout << -1;
    }
    else {

        cout << AdjacencyMatrix[VertexBegin][VertexEnd] << '\n';

        while (VertexBegin != VertexEnd) {
            cout << VertexBegin << ' ';
            VertexBegin = Next[VertexBegin][VertexEnd];

        }

        cout << VertexEnd;
    }

}

// Данный код отработает на тесте:
/*
4
0   8   0   1
0   0   1   0
4   0   0   0
0   2   9   0
3   2
*/
// в то время как my_code_Floyd–Warshall.cpp -- нет
