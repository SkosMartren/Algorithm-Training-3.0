#include <iostream>
#include <vector>

using namespace std;

int K = 0; // "K — количество вершин в компоненте связности. "



void DFS(
	const vector<vector<int>>& Graph,
	vector<bool>& Visited,
	int BeginVertex = 1 // "Необходимо построить компоненту связности, содержащую первую вершину."
) {

	++K;
	Visited[BeginVertex] = true;
	for (int vertex : Graph[BeginVertex]) {

		if (Visited[vertex] == false) { DFS(Graph, Visited, vertex); }

	}
}


int main() {

	int N, M; // "N (1 ≤ N ≤ 10^3) и M (0 ≤ M ≤ 5 * 10^5) — количество вершин и ребер в графе."
	cin >> N >> M;

	vector<vector<int>> Graph(N + 1);

	for (int vertex_1, vertex_2; cin >> vertex_1 >> vertex_2;) {

		Graph[vertex_1].push_back(vertex_2);
		Graph[vertex_2].push_back(vertex_1);

	}

	vector<bool> Visited(N + 1, false);

	DFS(Graph, Visited);

	cout << K << '\n';

	for (int i = 1; i < N + 1; ++i) {

		if (Visited[i]) {
			cout << i << ' ';
		}
	}
}
