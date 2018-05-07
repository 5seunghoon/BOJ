#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <utility>

using namespace std;
typedef long long int lld;
int N;
int depth;

int main() {
	map<int, lld> nodes;
	lld cnt = 0;
	nodes.insert(pair<int, lld>(0, -1));
	nodes.insert(pair<int, lld>(300001, 0));

	scanf("%d", &N);

	int x;
	scanf("%d", &x);
	nodes.insert(pair<int, lld>(x, 0));
	printf("0\n");

	pair<map<int, lld>::iterator, map<int, lld>::iterator> p;

	int lower, upper;
	lld height;

	for (int i = 1; i < N; i++) {
		scanf("%d", &x);
		p = nodes.equal_range(x);
		lower = (--p.first)->second;
		upper = p.second->second;
		height = max(lower, upper);
		nodes.insert(pair<int, lld>(x, height + 1));
		cnt += height + 1;
		printf("%lld\n", cnt);
	}
	return 0;
}