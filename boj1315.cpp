#define FLAT(INPUT) ((INPUT) >= 1001 ? 1000 : (INPUT))

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

int memo[1001][1001];
int N = 100;
vector<tuple<int, int, int>> quest;
vector<int> canPnt;

bool isClear[101];


bool comp(tuple<int, int, int> a, tuple<int, int, int> b) {
	auto[ax, ay, az] = a;
	auto[bx, by, bz] = b;

	if (ax < bx) return true;
	else if (ax == bx) {
		if (ay < by) return true;
		else if (ay == by) return az < bz;
		else return false;
	}
	else return false;
}

int solve(int _str, int _int) {
	//cout << _str << ", " << _int << endl;
	int & ret = memo[_str][_int];
	if (ret != -1) return ret;
	if (_str < 1 || _int < 1) return 0;

	int canSuc = 0;
	int canPnt = 0;
	vector<int> *isVisit = new vector<int>();

	for (int i = 0; i < N; i++) {
		auto &&[st, in, pn] = quest[i];
		if (_str >= st || _int >= in) {
			if (!isClear[i]) {
				isClear[i] = true;
				isVisit->push_back(i);
				canPnt += pn;
			}
			canSuc++;
		}
	}

	ret = canSuc;

	for (int i = 0; i <= canPnt; i++) {
		ret = max(ret, solve(FLAT((_str + i)), FLAT((_int + (canPnt - i)))));
	}

	for (int &s : *isVisit) {
		isClear[s] = false;
	}

	return ret;	
}

int main() {
	scanf("%d", &N);

	int a, b, c;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);
		quest.push_back(make_tuple(a, b, c));
		isClear[i] = false;
	}

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			memo[i][j] = -1;
		}
	}

	//sort(quest.begin(), quest.end(), comp);

	int result = solve(1, 1);

	printf("%d\n", result);

	return 0;
}