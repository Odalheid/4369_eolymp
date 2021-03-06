#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	vector <vector <int>> adj_list(vertices);
	for (int j = 0; j < edges; ++j) {
		int a, b; cin >> a >> b;
		adj_list[a - 1].push_back(b - 1);
		adj_list[b - 1].push_back(a - 1);
	}
	int burn_vertices_num;
	cin >> burn_vertices_num;
	queue<int> q;
	vector<int> dist(vertices, -1);
	for (int j = 0; j < burn_vertices_num; ++j) {
		int burn_vertex;
		cin >> burn_vertex;
		--burn_vertex;
		q.push(burn_vertex);
		dist[burn_vertex] = 0;
	}
	while (q.size() != 0) {
		int v = q.front();
		for (int j = 0; j < adj_list[v].size(); ++j) {
			int to = adj_list[v][j];
			if (dist[to] == -1) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
		q.pop();
	}
	int max_dist = -1;
	int max_vertex = -1;
	for (int j = 0; j < dist.size(); ++j) {
		if (dist[j] > max_dist) {
			max_dist = dist[j];
			max_vertex = j;
		}
	}
	cout << max_dist << endl << max_vertex + 1;
    return 0;
}

