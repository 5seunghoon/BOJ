#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <utility>

int nodes[1000001];
int parentNode[1000001];
int leftNode[1000001];
int rightNode[1000001];


void doPost(int i) {
	if (nodes[i] == 0) return;
	doPost(leftNode[i]);
	doPost(rightNode[i]);
	printf("%d\n", i);
}

int main() {
	int x;
	scanf("%d", &x);
	nodes[x] = 1;
	int head = x;
	parentNode[x] = 0;

	while (scanf("%d", &x) != EOF) {
		nodes[x] = 1;
		int prev = head;
		while (true) {
			if (prev > x) {
				if (leftNode[prev] == 0) {
					leftNode[prev] = x;
					parentNode[x] = prev;
					break;
				}
				else {
					prev = leftNode[prev];
				}
			}
			else {
				if (rightNode[prev] == 0) {
					rightNode[prev] = x;
					parentNode[x] = prev;
					break;
				}
				else {
					prev = rightNode[prev];
				}
			}
		}
	}

	doPost(head);

	return 0;
}