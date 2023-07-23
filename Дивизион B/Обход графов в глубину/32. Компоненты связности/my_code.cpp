#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//"количество компонент связности."
int IdxConnectivityComponents = 0; // == ICC

unordered_map<int, vector<int>> ICC_To_Vertices;


void DFS(const vector<vector<int>>& Graph, vector<bool>& Visited, int BeginVertex) {


	Visited[BeginVertex] = true;
	ICC_To_Vertices[IdxConnectivityComponents].push_back(BeginVertex);

	for (int vertex : Graph[BeginVertex]) {

		if (Visited[vertex] == false) { DFS(Graph, Visited, vertex); }

	}
}


int main() {


	// input
	int N, M; // "N (1 ≤ N ≤ 10^3) и M (0 ≤ M ≤ 5 * 10^5) — количество вершин и ребер в графе."
	cin >> N >> M;

	vector<vector<int>> Graph(N + 1);

	for (int vertex_1, vertex_2; cin >> vertex_1 >> vertex_2;) {

		Graph[vertex_1].push_back(vertex_2);
		Graph[vertex_2].push_back(vertex_1);

	}


	// solution	
	vector<bool> Visited(N + 1, false);

	for (int i = 1; i < N + 1; ++i) {

		if (Visited[i] == false) {
			++IdxConnectivityComponents;
			DFS(Graph, Visited, i);
		}

	}


	// output
	cout << IdxConnectivityComponents << '\n';

	for (; IdxConnectivityComponents != 0; --IdxConnectivityComponents) {

		cout << ICC_To_Vertices[IdxConnectivityComponents].size() << '\n';

		for (int vertex : ICC_To_Vertices[IdxConnectivityComponents]) {
			cout << vertex << ' ';
		}

		cout << '\n';
	}
}
