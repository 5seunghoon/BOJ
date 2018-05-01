#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector> 
#include <queue> 
#include <map>
#include <fstream> 
#include <string> 
#include <algorithm>
#include <functional>
 
using namespace std;

int N;
vector<long long> arr;

bool compare(long long a, long long b) {
	return abs(a) < abs(b);
}

int main() {
	int temp, minA = 100001, minB = 100001;
	long long min = 2100000000;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);


	for (int i = 0; i < N - 1; i++) {
		if (abs(arr[i] + arr[i + 1]) < min) {
			min = abs(arr[i] + arr[i + 1]);
			minA = arr[i];
			minB = arr[i + 1];
		}
	}

	if(minA < minB) printf("%d %d", minA, minB);
	else printf("%d %d", minB, minA);

	return 0;
}