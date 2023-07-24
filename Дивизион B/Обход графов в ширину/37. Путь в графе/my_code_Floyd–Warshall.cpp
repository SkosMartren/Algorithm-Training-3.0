#include <iostream>
#include <vector> 
#include <algorithm>

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
            if (i == j) { Next[i][i] = i; }

            if ((AdjacencyMatrix[i][j] == 0 && i != j)) {AdjacencyMatrix[i][j] = CountVertexes;}
          
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

                if (AdjacencyMatrix[i][k] < CountVertexes && 
                    AdjacencyMatrix[k][j] < CountVertexes && 
                    AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j] < AdjacencyMatrix[i][j]) {

                    AdjacencyMatrix[i][j] = AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j];
                    Next[i][j] = Next[i][k];

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


    if (AdjacencyMatrix[VertexBegin][VertexEnd] == CountVertexes) {
        cout << -1;
    }
    else {

        cout << AdjacencyMatrix[VertexBegin][VertexEnd]  << '\n';

        while (VertexBegin != VertexEnd){
            cout << VertexBegin << ' ';
            VertexBegin = Next[VertexBegin][VertexEnd];
            
        }

        cout << VertexEnd;
    }

}
