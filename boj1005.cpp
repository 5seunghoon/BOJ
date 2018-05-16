#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <math.h>
#include <limits.h>

using namespace std;

int testcase, N, K;
int time[1002];
vector<int> adj[1002];
int memo[1002];

int dp(int node) {
	int& ret = memo[node];
	if (ret != -1) return ret;
	int maxTime = 0;
	bool isEmpty = true;
	int temp;
	for (int adjNode : adj[node]) {
		temp = dp(adjNode);
		if (maxTime < temp) {
			maxTime = temp;
			isEmpty = false;
		}
	}
	if (isEmpty) return ret = time[node];
	else return ret = maxTime + time[node];
}

int main() {
	int start, end, target;
	scanf("%d", &testcase);
	while (testcase--) {
		for (int i = 0; i < 1002; i++) {
			adj[i] = vector<int>();
			memo[i] = -1;
			time[i] = -1;
		}

		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &time[i]);
		}
		for (int i = 1; i <= K; i++) {
			scanf("%d %d", &start, &end); // start => end
			adj[end].push_back(start); 
		}
		scanf("%d", &target);
		dp(target);
		printf("%d\n", dp(target));
	}
	return 0;
}