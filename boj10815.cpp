#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int card[500001];
int srch[500001];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &srch[i]);
	}

	sort(card, card + N);

	int start, end, pivot;

	for (int i = 0; i < M; i++) {
		start = 0;
		end = N;
		while (true) {
			if (end - start <= 0) {
				printf("0 ");
				break;
			}
			pivot = (start + end) / 2;
			if (card[pivot] == srch[i]) {
				printf("1 ");
				break;
			}
			else if (card[pivot] > srch[i]) {
				end = pivot;
			}
			else {
				start = pivot + 1;
			}

		}
	}
	return 0;
}