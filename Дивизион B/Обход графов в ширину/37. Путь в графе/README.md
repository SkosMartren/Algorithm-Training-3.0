https://contest.yandex.ru/contest/45468/problems/37/

```objectives
#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

int N;
const int UNDEF = -1;
int BeginVertice, EndVertice;

// содержит ребра в виде пары {i + 1, Path[i] + 1} -- не все ребра графа там лежат!
vector<int> Path; // Path : i + 1 --> Path[i] + 1 == есть ребро между вершинами Path[i] + 1 и i + 1 сдвиг на "+ 1" обсусловлен изначальным сдвигом исходных вершин
				  // примечательно то, что всегда Path[BeginVertice] = -1 -- обусловлено тем, что SetFireVertice не может быть равным BeginVertice ввиду "Len[BeginVertice] = 0;" и "if (Len[SetFireVertice] == UNDEF) {"

void BFS(const vector<vector<int>>& Graph, vector<int>& Len) {

	queue<int> BurningVertices;
	BurningVertices.push(BeginVertice); 

	while (!BurningVertices.empty()) {

		const int Flaming = BurningVertices.front(); // поджегся сейчас
		BurningVertices.pop();

		for (const int SetFireVertice : Graph[Flaming]) {

			if (Len[SetFireVertice] == UNDEF) {
				
				Len[SetFireVertice] = Len[Flaming] + 1;
				Path[SetFireVertice] = Flaming;
				//Path[Flaming] = SetFireVertice; // error!
				if (SetFireVertice == EndVertice) { return; }
				
				BurningVertices.push(SetFireVertice);
			}

		}
	}

}

int main() {

	cin >> N;
	Path.resize(N, UNDEF);
	vector<vector<int>> Graph(N); // Graph[i] -- список вершин в которые идут ребра из i вершины
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			bool ValMatrix; cin >> ValMatrix;

			if (ValMatrix == 1) {
				Graph[i].push_back(j);
				Graph[j].push_back(i);
			}
		}
	}

	
	cin >> BeginVertice >> EndVertice;

	// 18	presentation-error
	if (BeginVertice == EndVertice) { // " Если путь имеет длину 0, то его выводить не нужно, достаточно вывести длину."
		cout << 0; 
		return 0; 
	}

	--BeginVertice; --EndVertice;


	vector<int> Len(N, UNDEF);
	Len[BeginVertice] = 0;

	BFS(Graph, Len);	

	
	if (Len[EndVertice] == -1) {
		cout << Len[EndVertice]; // "Если пути нет, нужно вывести -1."
	}
	else { 		//"Необходимо вывести путь (номера всех вершин в правильном порядке)"
	       		// "Выведите сначала L – длину кратчайшего пути (количество ребер, которые нужно пройти), а потом сам путь. "
		cout << Len[EndVertice] << '\n';
		for (int i = EndVertice; i != -1; i = Path[i]) { cout << i + 1 << ' '; }
		cout << '\n';
		
		for (int i = 0; i < N; ++i) {cout << i + 1 << " set on fire by " << Path[i] + 1 << '\n';}
	}
}
/*
10
0 1 0 0 0 0 0 0 0 0
1 0 0 1 1 0 1 0 0 0
0 0 0 0 1 0 0 0 1 0
0 1 0 0 0 0 1 0 0 0
0 1 1 0 0 0 0 0 0 1
0 0 0 0 0 0 1 0 0 1
0 1 0 1 0 1 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 1 0 0
0 0 0 0 1 1 0 0 0 0
3 4

3
4 2 5 3
1 set on fire by 2
2 set on fire by 5
3 set on fire by 0
4 set on fire by 2
5 set on fire by 3
6 set on fire by 0
7 set on fire by 0
8 set on fire by 9
9 set on fire by 3
10 set on fire by 5
*/


```
