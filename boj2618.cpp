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
#include <stdlib.h>
#include <stack>

using namespace std;

int N, W;
vector<pair<int,int>> acci;

int memo[1002][1002];
pair<int, int> root[1002][1002];
//int routeArr[1002];

pair<int, int> mStart;
pair<int, int> mEnd;

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	scanf("%d", &N);
	scanf("%d", &W);

	mStart = pair<int, int>(1, 1);
	mEnd = pair<int, int>(N, N);

	int tmpx, tmpy;
	acci.push_back(make_pair<int, int>(0, 0));
	for (int i = 0; i < W; i++) {
		scanf("%d %d", &tmpx, &tmpy);
		//tmpx = (i * 19 + i * 21 + i * 11) % N;
		//tmpy = (i * 7 + i * 31 + i * 13) % N;
		acci.push_back(make_pair(tmpx, tmpy));
	}

	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= W; j++) {
			memo[i][j] = INT_MAX;
		}
	}

	memo[0][0] = 0;
	memo[0][1] = memo[0][0] + dist(acci[1], mEnd);
	memo[1][0] = memo[0][0] + dist(acci[1], mStart);
	int tmp;
	for (int i = 2; i <= W; i++) {
		tmp = dist(acci[i], acci[i - 1]);
		memo[0][i] = memo[0][i - 1] + tmp;
		root[0][i].first = 0;
		root[0][i].second = i - 1;
		memo[i][0] = memo[i - 1][0] + tmp;
		root[i][0].first = i - 1;
		root[i][0].second = 0;
	}

	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= W; j++) {
			if (i == j) continue;
			if (i > j) {
				if (i - j == 1) {
					for (int k = 0; k <= i - 2 ; k++) {
						pair<int, int> other;
						if (k == 0) other = pair<int, int>(1, 1);
						else other = acci[k];
						int newDist = memo[k][j] + dist(acci[i], other);
						if (memo[i][j] > newDist) {
							memo[i][j] = newDist;
							root[i][j].first = k;
							root[i][j].second = j;
						}
					}
				}
				else {
					pair<int, int> other;
					if (i - 1 == 0) other = pair<int, int>(1, 1);
					else other = acci[i - 1];
					memo[i][j] = memo[i - 1][j] + dist(other, acci[i]);
					root[i][j].first = i - 1;
					root[i][j].second = j;
				}
			}
			else {
				if (j - i == 1) {
					for (int k = 0; k <= j - 2; k++) {
						pair<int, int> other;
						if (k == 0) other = pair<int, int>(N, N);
						else other = acci[k];
						int newDist = memo[i][k] + dist(acci[j], other);
						if (memo[i][j] > newDist) {
							memo[i][j] = newDist;
							root[i][j].first = i;
							root[i][j].second = k;
						}
					}
				}
				else {
					pair<int, int> other;
					if (j - 1 == 0) other = pair<int, int>(N, N);
					else other = acci[j - 1];
					memo[i][j] = memo[i][j - 1] + dist(acci[j], other);
					root[i][j].first = i;
					root[i][j].second = j - 1;
				}
			}
		}
	}

	int result = INT_MAX;
	int x, y;
	for (int i = 0; i <= W; i++) {
		if (result > memo[W][i]) {
			result = memo[W][i];
			x = W;
			y = i;
		}
		if (result > memo[i][W]) {
			result = memo[i][W];
			x = i;
			y = W;
		}
	}

	printf("%d\n", result);
	int prevx, prevy;
	stack<int> route;
	while (true) {
		prevx = root[x][y].first;
		prevy = root[x][y].second;

		if (prevx == x) {
			x = prevx;
			y = prevy;
			route.push(2);
			//cout << 2 << endl;
		}
		else {
			x = prevx;
			y = prevy;
			route.push(1);
			//cout << 1 << endl;
		}

		if (x == 0 && y == 0) {
			break;
		}
	}

	while (!route.empty()) {
		printf("%d\n", route.top());
		route.pop();
	}

	return 0;
}