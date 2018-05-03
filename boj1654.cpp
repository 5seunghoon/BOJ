#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

typedef long long lld;

int K, N;
lld line[10001];
lld lineMax;

int main() {
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%lld", &line[i]);
		if (lineMax < line[i]) lineMax = line[i];
	}

	lld start = 1;
	lld end = lineMax + 1;
	lld pivot = (end + start) / 2;

	while (true) {
		int count = 0;
		if (end - start <= 1) {
			break;
		}
		for (int i = 0; i < K; i++) {
			count += (line[i] / pivot);
		}
		if (count < N) {
			end = pivot;
			pivot = (end + start) / 2;
		}
		else {
			start = pivot;
			pivot = (end + start) / 2;
		}
	}
	printf("%lld", pivot);

	return 0;
}