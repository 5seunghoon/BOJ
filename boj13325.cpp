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

using namespace std;

int Nodes[4200000];

int N;

int parent(int node) {
	return (int)(node / 2);
}
int left(int node) {
	return node * 2;
}
int right(int node) {
	return node * 2 + 1;
}

int f(int node, int maxLevel) {
	if (node >= maxLevel) return 0;

	int leftsum = f(left(node), maxLevel) + Nodes[left(node)];
	int rightsum = f(right(node), maxLevel) + Nodes[right(node)];

	int m = max(leftsum, rightsum);
	int diff;
	if (leftsum > rightsum) {
		diff = (leftsum - rightsum);
		Nodes[right(node)] += diff;
	}
	else {
		diff = rightsum - leftsum;
		Nodes[left(node)] += diff;
	}
	return m;
}

int main() {
	scanf("%d", &N);

	memset(Nodes, 0, sizeof(int) * 2100000);

	int temp;
	for (int i = 2; i < pow(2, N + 1); i++) {
		scanf("%d", &temp);
		Nodes[i] = temp;
		//Nodes[i] = 1;
	}

	f(1, (int)pow(2, N + 1));

	int result = 0;
	for (int i = 0; i < pow(2, N + 1); i++) {
		result += Nodes[i];
	}
	cout << result << endl;

	return 0;
}
