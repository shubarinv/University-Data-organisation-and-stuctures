
#include <iostream>
#include <climits>

using namespace std;
const int V = 6;
int tmp[V], tmp1 = 0;
char city[7] = "ABCDEF";

void clearBuff() { ///< @brief Чистит буфер
	cin.clear();    // Restore input stream to working state
	cin.ignore(1000, '\n');    // Get rid of any garbage that user might have entered}
}

int minDistance(const int dist[],
                const bool sptSet[]) {

	// инициализация мин значения
	int min = INT_MAX, min_index=-1;

	for (int v = 0; v < V; v++)
		if (!sptSet[v] &&
		    dist[v] <= min)
			min = dist[v], min_index = v;
	if(min_index==-1)
		throw invalid_argument("Что-то пошло не так при задании мин значения");
	return min_index;
}

// Функция выводит вершины которые состаляют кратчайший путь
void printPath(int parent[], int j) {
	// если parent[j] является источником(первый город(A))
	if (parent[j] == -1)
		return;
	printPath(parent, parent[j]);
	tmp1++;
	tmp[tmp1] = j;
	cout << city[j] << " ";
}

// Выводит минимальное растояние и минимальный путь
void printSolution(int dist[],
                   int parent[]) {
	cout << endl << "=========" << endl;
	cout << "A->B=" << dist[1] << endl;
	if(dist[1]==INT_MAX)
		throw invalid_argument("Нет дорог которые могли бы соединить A и B");

	cout << "A ";
	printPath(parent, 1);
	cout << endl << "=========" << endl;
}

int *dijkstra(int graph[V][V], int src) {

	//содержит кратчайшие путь от A до V
	int dist[V];

	// sptSet[i] will true if vertex
	// i is included / in shortest
	// path tree or shortest distance
	// from src to i is finalized
	bool sptSet[V];

	// Parent array to store
	// shortest path tree
	int parent[V];

	// Initialize all distances as
	// INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++) {
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex
	// from itself is always 0
	dist[src] = 0;

	// Find shortest path
	// for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance
		// vertex from the set of
		// vertices not yet processed.
		// u is always equal to src
		// in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex
		// as processed
		sptSet[u] = true;

		// Update dist value of the
		// adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] &&
			    dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	//Вывод расстояния и пути
	printSolution(dist, parent);
	return tmp;
}

//главная функция
int main() {
	setlocale(LC_ALL, "Rus");
	bool isTranspTrain = false;
	int start, highways[V][V] = {
			{0, 0,  0, 0, 0,  0},
			{0, 0,  0, 0, 0,  0},
			{9, 0,  0, 0, 20, 0},
			{5, 20, 0, 0, 7,  0},
			{0, 5,  8, 7, 0,  0},
			{0, 0,  0, 0, 0,  0}};
	int railroads[V][V] = {
			{0, 0,  0, 0, 0, 0},
			{0, 0,  0, 0, 0, 0},
			{4, 0,  0, 0, 2, 0},
			{6, 15, 0, 0, 7, 0},
			{0, 10, 9, 7, 0, 0},
			{0, 0,  0, 0, 0, 0}};
	start = 1;
	cout << "_____Введите A и B для обычных дорог____" << endl;
	for (int i = 2; i < V; ++i) {
		cout << "Введите расстояние от A до " << city[i];
		cin >> highways[0][i];
		clearBuff();
		highways[i][0]= highways[0][i];
	}
	for (int i = 2; i < V; ++i) {
		cout << "Введите расстояние от B до " << city[i];
		cin >> highways[1][i];
		clearBuff();
		highways[i][1]= highways[1][i];
	}

	cout << endl << "_____Введите A и B для ЖД____" << endl;
	for (int i = 2; i < V; ++i) {
		cout << "Введите расстояние от A до " << city[i];
		cin >> railroads[0][i];
		clearBuff();
		railroads[i][0] = railroads[0][i];
	}
	for (int i = 2; i < V; ++i) {
		cout << "Введите расстояние от B до " << city[i];
		cin >> railroads[1][i];
		clearBuff();
		railroads[i][1] = railroads[1][i];
	}

	int mix[V][V];
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (highways[i][j] < railroads[i][j] && highways[i][j] != 0)
				mix[i][j] = highways[i][j];
			else if (highways[i][j] > railroads[i][j] && railroads[i][j] != 0)
				mix[i][j] = railroads[i][j];
			else mix[i][j] = highways[i][j];
		}
	}

	for (auto & i : mix) {
		for (int j : i) {
			cout << "\t" << j;
		}
		cout << endl;
	}

	dijkstra(mix, start - 1);
	for (int i = 0; i < V; ++i) {
		if (tmp[i] == 1)
			break;
		if (mix[tmp[i]][tmp[i + 1]] == railroads[tmp[i]][tmp[i + 1]]) {
			if (!isTranspTrain) {
				cout << "В городе " << city[tmp[i]] << " пересадка на ЖД" << endl;
				isTranspTrain = true;
			}
		} else {
			if (isTranspTrain) {
				cout << "В городе " << city[tmp[i]] << " пересадка на машину" << endl;
				isTranspTrain = false;
			}
		}
	}
	return 0;
}