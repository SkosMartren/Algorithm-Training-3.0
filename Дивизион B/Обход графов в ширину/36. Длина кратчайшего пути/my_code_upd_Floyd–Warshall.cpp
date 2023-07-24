#include <iostream>
#include <vector> 
#include <algorithm>
#include <limits>

using namespace std;

int main() {

    // input

    int N; cin >> N; // число N – количество вершин в графе (1 ≤ N ≤ 100)

    vector<vector<int>> AdjacencyMatrix(N + 1, vector<int>(N + 1));

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {

            cin >> AdjacencyMatrix[i][j];

            if ((AdjacencyMatrix[i][j] == 0 && i != j)) {
                AdjacencyMatrix[i][j] = numeric_limits<int>::max();
            }

        }
    }

    // solution



    int VertexBegin, VertexEnd; cin >> VertexBegin >> VertexEnd;

    for (int k = 1; k < N + 1; ++k) {
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {

                if (AdjacencyMatrix[i][k] < numeric_limits<int>::max() && AdjacencyMatrix[k][j] < numeric_limits<int>::max()) {
                    AdjacencyMatrix[i][j] = min(AdjacencyMatrix[i][j], AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j]);
                }

            }
        }

        //cout << "\nfor k = " << k + 1 <<"\n";

        //for (int i = 0; i < N + 1; ++i) {
        //    for (int j = 0; j < N + 1; ++j) {

        //        cout << AdjacencyMatrix[i][j] << ' ';

        //    }
        //    cout << '\n';
        //}

    }

    // output
    cout << ((AdjacencyMatrix[VertexBegin][VertexEnd] == numeric_limits<int>::max()) ? -1 : AdjacencyMatrix[VertexBegin][VertexEnd]);

}
