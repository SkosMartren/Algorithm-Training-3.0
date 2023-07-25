https://contest.yandex.ru/contest/45468/problems/37/

```objectives
#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

int N;
const int UNDEF = -1;
int BeginVertice, EndVertice;

// содержит ребра в виде пары {i + 1, PathScorched[i] + 1} -- не все ребра графа там лежат!
vector<int> PathScorched; // PathScorched : i + 1 --> PathScorched[i] + 1 == есть ребро между вершинами PathScorched[i] + 1 и i + 1 сдвиг на "+ 1" обсусловлен изначальным сдвигом исходных вершин
				  // примечательно то, что всегда PathScorched[BeginVertice] = -1 -- обусловлено тем, что SetFireVertice не может быть равным BeginVertice ввиду "Len[BeginVertice] = 0;" и "if (Len[SetFireVertice] == UNDEF) {"

void BFS(const vector<vector<int>>& Graph, vector<int>& Len) {

	queue<int> BurningVertices;
	BurningVertices.push(BeginVertice); 

	while (!BurningVertices.empty()) {

		const int Flaming = BurningVertices.front(); // поджегся сейчас
		BurningVertices.pop();

		for (const int SetFireVertice : Graph[Flaming]) {

			if (Len[SetFireVertice] == UNDEF) {
				
				Len[SetFireVertice] = Len[Flaming] + 1;
				PathScorched[SetFireVertice] = Flaming;
				//PathScorched[Flaming] = SetFireVertice; // error!
				if (SetFireVertice == EndVertice) { return; }
				
				BurningVertices.push(SetFireVertice);
			}

		}
	}

}

int main() {

	cin >> N;
	PathScorched.resize(N, UNDEF);
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
		for (int i = EndVertice; i != -1; i = PathScorched[i]) { cout << i + 1 << ' '; }
		cout << '\n';
		
		for (int i = 0; i < N; ++i) {cout << i + 1 << " set on fire by " << PathScorched[i] + 1 << '\n';}
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

__________

<img src="https://github.com/SkosMartren/useful-materials/blob/main/37_path_in_graph_example.png" width="800" height="500"/>

 <p align="center">  Содержимое двумерного массива Next для "Пример" из условия  </p> 

|    	| j 	|   0   	|   1   	|   2   	|    3   	|   4   	|    5   	|    6   	|   7   	|    8   	|    9   	|   10   	|
|:--:	|:-:	|:-----:	|:-----:	|:-----:	|:------:	|:-----:	|:------:	|:------:	|:-----:	|:------:	|:------:	|:------:	|
|  i 	|   	|       	|       	|       	|        	|       	|        	|        	|       	|        	|        	|        	|
|  0 	|   	| **0** 	| **0** 	| **0** 	|  **0** 	| **0** 	|  **0** 	|  **0** 	| **0** 	|  **0** 	|  **0** 	|  **0** 	|
|  1 	|   	| **0** 	| **1** 	| **2** 	|  **2** 	| **2** 	|  **2** 	|  **2** 	| **2** 	|  **2** 	|  **2** 	|  **2** 	|
|  2 	|   	| **0** 	| **1** 	| **2** 	|  **5** 	| **4** 	|  **5** 	|  **7** 	| **7** 	|  **5** 	|  **5** 	|  **5** 	|
|  3 	|   	| **0** 	| **5** 	| **5** 	|  **3** 	| **5** 	|  **5** 	|  **5** 	| **5** 	|  **9** 	|  **9** 	|  **5** 	|
|  4 	|   	| **0** 	| **2** 	| **2** 	|  **2** 	| **4** 	|  **2** 	|  **7** 	| **7** 	|  **2** 	|  **2** 	|  **2** 	|
|  5 	|   	| **0** 	| **2** 	| **2** 	|  **3** 	| **2** 	|  **5** 	| **10** 	| **2** 	|  **3** 	|  **3** 	| **10** 	|
|  6 	|   	| **0** 	| **7** 	| **7** 	| **10** 	| **7** 	| **10** 	|  **6** 	| **7** 	| **10** 	| **10** 	| **10** 	|
|  7 	|   	| **0** 	| **2** 	| **2** 	|  **2** 	| **4** 	|  **2** 	|  **6** 	| **7** 	|  **2** 	|  **2** 	|  **6** 	|
|  8 	|   	| **0** 	| **9** 	| **9** 	|  **9** 	| **9** 	|  **9** 	|  **9** 	| **9** 	|  **8** 	|  **9** 	|  **9** 	|
|  9 	|   	| **0** 	| **3** 	| **3** 	|  **3** 	| **3** 	|  **3** 	|  **3** 	| **3** 	|  **8** 	|  **9** 	|  **3** 	|
| 10 	|   	| **0** 	| **5** 	| **5** 	|  **5** 	| **5** 	|  **5** 	|  **6** 	| **6** 	|  **5** 	|  **5** 	| **10** 	|
