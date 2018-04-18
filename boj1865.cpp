//deque.tistory.com

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> 
#include <vector> 
#include <queue> 
#include <map>
#include <fstream> 
#include <string> 
#include <algorithm>
#include <functional>
#include <limits.h>

using namespace std;

template <typename FIRST, typename SECOND, typename THIRD>
class triple {
public:
	FIRST first;
	SECOND second;
	THIRD third;
	triple(FIRST a, SECOND b, THIRD c) {
		first = a;
		second = b;
		third = c;
	}
};

bool BellmanFord(vector<int> &dist, vector<triple<int, int, int>> &edge, int V, int E, int StartNode) {
	bool hasMinusCycle = false;

	for (int i = 1; i <= V; i++) {
		dist[i] = INT_MAX;
	}
	dist[StartNode] = 0;
	for (int i = 1; i <= V; i++) {
		for (auto nowEdge : edge) {
			int from = nowEdge.first;
			int to = nowEdge.second;
			int weight = nowEdge.third;

			if (dist[from] == INT_MAX) continue;
			if (dist[to] > dist[from] + weight) {
				dist[to] = dist[from] + weight;

				if (i == V) hasMinusCycle = true;
			}
		}
	}
	return hasMinusCycle;
}

int testcase;
int N, M, W;

int main() {
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d %d %d", &N, &M, &W);

		vector<int> dist(N + 1, INT_MAX);
		vector<triple<int, int, int>> edge; //from, to, weight

		int from, to, weight;
		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d", &from, &to, &weight);
			edge.push_back(triple<int, int, int>(from, to, weight));
			edge.push_back(triple<int, int, int>(to, from, weight));
		}
		for (int i = 1; i <= W; i++) {
			scanf("%d %d %d", &from, &to, &weight);
			edge.push_back(triple<int, int, int>(from, to, -weight));
		}

		bool hasMinusCycle = BellmanFord(dist, edge, N, (M + W), 1);

		if (hasMinusCycle) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}