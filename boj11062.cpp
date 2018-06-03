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
#include <stdlib.h>
#include <stack>
#include <tuple>

using namespace std;

int testcase;
int N;
int card[1001];
int memo[1001][1001];

// solve(i,j)는 i~j까지의 카드만 남았을 때, ""지금 상황에서"" 내가 먹을 수 있는 최대의 점수
int solve(int start, int end) { 
	int & ret = memo[start][end];
	if (ret != 0) return ret;

	if (start >= end) {
		if ((N - (start + end)) % 2) return ret = card[start];
		else return ret = 0;
	}

	if ((N - (start + end)) % 2){
		ret = max((solve(start + 1, end) + card[start]), (solve(start, end - 1) + card[end]));
	}
	else {
		ret = min((solve(start + 1, end)), (solve(start, end - 1)));
	}


	return ret;
}

int main() {
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &card[i]);
		}
		
		for (int i = 0; i < N; i++) {
			memset(memo[i], 0, sizeof(int) * N);
		}

		printf("%d\n", solve(0, N - 1));
	}

	return 0;
}