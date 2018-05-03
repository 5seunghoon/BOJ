#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int orgArr[100001];
int arr[100001];
int N, M;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &orgArr[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &arr[i]);
	}

	sort(orgArr, orgArr + N);

	int data, pivot;
	for (int i = 0; i < M; i++) {
		data = arr[i];
		int start = 0, end = N;
		while (true) {
			pivot = (end + start) / 2;
			if (orgArr[pivot] == data) {
				printf("1\n");
				break;
			}
			else if (orgArr[pivot] < data) {
				start = pivot + 1;
			}
			else {
				end = pivot - 1;
			}
			if (end - start < 0) {
				printf("0\n");
				break;
			}
		}
	}

	return 0;
}