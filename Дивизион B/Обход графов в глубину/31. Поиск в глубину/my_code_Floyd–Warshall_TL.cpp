#include <iostream> 
#include <vector> 

using namespace std;

int main() {


    // input

    const int VertexBegin = 1; // " Необходимо построить компоненту связности, содержащую первую вершину."

    int N, M;
    cin >> N >> M; // "В первой строке записаны два целых числа N (1 ≤ N ≤ 10^3) и M (0 ≤ M ≤ 5 * 10^5) — количество вершин и ребер в графе."

    vector < vector < bool>> AdjacencyMatrix(1 + N, vector<bool>(1 + N, 0));

    for (int vertex_1, vertex_2; cin >> vertex_1 >> vertex_2;) {

        // "Дан неориентированный граф, возможно, с петлями и кратными ребрами. "
        AdjacencyMatrix[vertex_1][vertex_2] = 1;
        AdjacencyMatrix[vertex_2][vertex_1] = 1;

    }


    // solution

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {

                if ((AdjacencyMatrix[i][k] && AdjacencyMatrix[k][j]) || i == j) { //  i == j -- для учета вершины VertexBegin в компоненте сваязности, т.е. AdjacencyMatrix[VertexBegin][VertexBegin] = true
                    AdjacencyMatrix[i][j] = true;
                }

            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {

        // AdjacencyMatrix[VertexBegin][i] == есть путь от VertexBegin до i == они находятся в одной компонете связности
        if (AdjacencyMatrix[VertexBegin][i]) { ans++; }

    }


    // output

    cout << ans << '\n';

   
    for (int i = 1; i <= N; i++) {

        if (AdjacencyMatrix[VertexBegin][i]) { cout << i << ' '; }

    }
    return 0;
}
