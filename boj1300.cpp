#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int K, N;

int main() {
	scanf("%d", &N);
	scanf("%d", &K);

	int start, end, mid, cnt;
	start = 1;
	end = K;
	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
		if (cnt < K) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	printf("%d", start);
	
	return 0;
}