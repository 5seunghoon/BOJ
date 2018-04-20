#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX_ 2100000000

#include <iostream> 
#include <vector> 
#include <queue> 
#include <map>
#include <fstream> 
#include <string> 
#include <algorithm>
#include <functional>

using namespace std;
int V, E, K;
vector<pair<int, int>> adj[20002];
int dist[20002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool isVisit[20002];

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	int from, to, weight;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		adj[from].push_back(pair<int, int>(weight, to));
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INT_MAX_;
	}
	dist[K] = 0;
	pq.push(make_pair(0, K));
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost) continue;
		if (dist[now] == cost && isVisit[now] == true) continue;
		isVisit[now] = true;
		for (pair<int, int> next : adj[now]) {
			if (dist[next.second] > next.first + cost) {
				pq.push(make_pair(next.first + cost, next.second));
				dist[next.second] = next.first + cost;
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] >= INT_MAX_) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}