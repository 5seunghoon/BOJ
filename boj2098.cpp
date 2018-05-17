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

int N;
int powN;
int dist[17][17];
int memo[65537][17];

int dp(int visit, int now) {
	if (visit == powN) return dist[0][now];
	int& ret = memo[visit][now];
	if (ret != -1) return ret;

	int minDist = 20000000;
	int temp;
	for (int i = 0; i < N; i++) {
		if (!(visit & (1 << i) )) { // i노드를 방문하지 않았으면,
			if (dist[i][now] != 0) { // i=>now 가 연결되어 있으면
				temp = dp(visit | (1 << i), i) + dist[i][now];
				if (minDist > temp) {
					minDist = temp;
				}
			}
		}
	}

	return ret = minDist;
}

int main() {
	
	scanf("%d", &N);
	powN = pow(2, N) - 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &dist[i][j]);
		}
	}
	for (int i = 0; i < 65537; i++) {
		for (int j = 0; j < 17; j++) {
			memo[i][j] = -1;
		}
	}

	printf("%d\n", dp(1,0));
	
	return 0;
}