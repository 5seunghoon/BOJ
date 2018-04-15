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
#include <utility>
#include <cstring>


using namespace std;

struct triple {
	int NextNode;
	int Cost;
	int DelayTime;
};
struct cmp {
	bool operator ()(triple a, triple b) {
		return a.DelayTime > b.DelayTime;
	}
};

int V, M, E;
int testCase;
int memo[102][10002]; // memo[i][j] = i번째 노드까지 j의 cost로 갈수있는 최소 시간
vector<triple> adj[102];		// to, cost, delayTime

int main() {
	scanf("%d", &testCase);
	while (testCase--) {
		scanf("%d %d %d", &V, &M, &E);

		for (int i = 1; i <= V; i++) adj[i].clear();
		int from, to, cost, delayTime;
		triple tmp;
		for (int i = 1; i <= E; i++) {
			scanf("%d %d %d %d", &from, &to, &cost, &delayTime);
			tmp.NextNode = to;
			tmp.Cost = cost;
			tmp.DelayTime = delayTime;
			adj[from].push_back(tmp);
		}
		memset(memo, -1, sizeof(memo));
		memo[1][0] = 0;

		priority_queue<triple, vector<triple>, cmp> dijkstraQ;
		tmp.NextNode = 1;
		tmp.Cost = 0;
		tmp.DelayTime = 0;
		dijkstraQ.push(tmp);

		triple edge, nextEdge;

		while (!dijkstraQ.empty()) {
			edge = dijkstraQ.top();
			dijkstraQ.pop();
			int now = edge.NextNode;
			if (memo[now][edge.Cost] < edge.DelayTime) continue;
			memo[now][edge.Cost] = edge.DelayTime;
			for (int i = 0; i < adj[now].size(); i++) {
				nextEdge = adj[now][i];
				int newCost = edge.Cost + nextEdge.Cost;
				if (newCost > M) continue;
				int &ret = memo[nextEdge.NextNode][newCost];
				int newTime = edge.DelayTime + nextEdge.DelayTime;
				if (ret == -1 || ret > newTime) {
					ret = newTime;
					tmp.NextNode = nextEdge.NextNode;
					tmp.Cost = newCost;
					tmp.DelayTime = newTime;
					dijkstraQ.push(tmp);
				}
			}
		}

		int minTime = INT_MAX;
		for (int i = 0; i <= M; i++) {
			if (memo[V][i] != -1 && minTime > memo[V][i]) minTime = memo[V][i];
		}
		if (minTime == INT_MAX) printf("Poor KCM\n");
		else printf("%d\n", minTime);

	}
	return 0;
}