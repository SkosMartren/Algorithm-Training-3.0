#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

/* https://ru.algorithmica.org/cs/shortest-paths/bfs/ :
Основную идею алгоритма можно понимать как процесс «поджигания» графа: 
на нулевом шаге мы поджигаем вершину s [стартовую вершину, от которой ищем минимальное расстояние], 
а на каждом следующем шаге огонь с каждой уже горящей вершины перекидывается на всех её соседей, в конечном счете поджигая весь граф. 

Если моделировать этот процесс, то за каждую итерацию алгоритма будет происходить расширение «кольца огня» в ширину на единицу. 
Номер шага, на котором вершина v начинает гореть, в точности равен длине её минимального пути из вершины s.
*/

int N; // N – количество вершин в графе

const int UNDEF = -1; /* UNDEF == локальная бесконечность, так как изначально неизвестны расстояния от VertexBegin до остальных вершин.
                       В случае, если VertexBegin и вершина v находятся в разных компонентах связности, расстояние 
                       между ними в len будет равно -1 – это можно заметить, например, в «пример 2»*/

int VertexBegin, VertexEnd; // "Далее задаются номера двух вершин – начальной и конечной."

void BFS(const vector <vector<int>>& graph, vector<int>& len) {

    queue<int> BurningVertexes; // Queue -- содержит вершины из текущего кольца огня и, может быть, последующего 
    BurningVertexes.push(VertexBegin); // "на нулевом шаге мы поджигаем вершину s [стартовую вершину, от которой ищем минимальное расстояние]"
  
    while (!BurningVertexes.empty()) {

        const int Current = BurningVertexes.front(); 
        BurningVertexes.pop(); // у всех контейнерных адаптеров удаление происходит через pop: https://en.cppreference.com/w/cpp/container

        for (int next : graph[Current]) { // next -- сосед вершины Current, на нее перекинется огонь с Current, если ранее она не была посещена 
            if (len[next] == UNDEF) { // == Вершина next ни разу не посещена
              
              len[next] = len[Current] + 1;  
              if (next == VertexEnd) { return; } // Номер шага, на котором вершина v начинает гореть, в точности равен длине её минимального пути из вершины s.
              BurningVertexes.push(next);
                
            }
        }

    }
}

int main() {

    cin >> N;

    // перевод графа из вида матрицы смежности в список смежности
    vector < vector <int>> graph(N); // graph[i] -- список вершин в которые идут ребра из i вершины

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);

            }
        }
    }
    
    cin >> VertexBegin >> VertexEnd; 
    VertexBegin--; VertexEnd--; // номера двух вершин положительны, номеруются от 1 до N, для того чтобы работать с ними в vector необходимо декрементировать их

    vector<int> len(N, UNDEF); //  == length == len[i] --> расстояние от вершины VertexBegin до вершины i + 1
    len[VertexBegin] = 0; // расстояние от стартовой вершины до стартовой вершины, очевидно, равно 0
    
    BFS(graph, len);

    cout << len[VertexEnd];
}
