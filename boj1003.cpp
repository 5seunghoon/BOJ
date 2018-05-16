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

int n, testcase;
int zero[42];
int one[42];


int main() {
	memset(zero, 0, sizeof(int) * 41);
	memset(one, 0, sizeof(int) * 41);
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d", &n);

		zero[0] = 1;
		zero[1] = 0;
		for (int i = 2; i <= n; i++) {
			zero[i] = zero[i - 1] + zero[i - 2];
		}

		one[0] = 0;
		one[1] = 1;
		for (int i = 2; i <= n; i++) {
			one[i] = one[i - 1] + one[i - 2];
		}
		printf("%d %d\n", zero[n], one[n]);
	}

	return 0;
}