#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char S[1001];
int sa[1001], pos[1001], temp[1001], lcp[1001];
int delta, N;

bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += delta;
	j += delta;
	if (i < N && j < N) return pos[i] < pos[j];
	else return i > j;
}

int main() {
	scanf("%s", S);
	N = strlen(S);

	//pos[x] = S[x:-1]의 순번
	//temp[x] = x순번의 그룹번호
	//sa[x] = x순번의 suffix의 S에서의 index
	for (int i = 0; i < N; i++) {
		pos[i] = S[i] - 'a';
		sa[i] = i;
	}
	delta = 1;
	while (true) {
		memset(temp, 0, sizeof(temp));
		sort(sa, sa + N, cmp);
		for (int i = 0; i < N - 1; i++) {
			temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
		}
		for (int i = 0; i < N; i++) {
			pos[sa[i]] = temp[i];
		}
		if (temp[N - 1] == N - 1) break;
		delta *= 2;
	}

	int sameCount = 0;
	for (int i = 0; i < N; i++) {
		if (sameCount > 0) sameCount--;
		if (sameCount < 0) sameCount = 0;
		if (pos[i] == 0) continue;
		int j = sa[pos[i] - 1];
		while (true) {
			if ((i + sameCount) > N || (j + sameCount) > N) break;
			if (S[i + sameCount] == S[j + sameCount]) sameCount++;
			else break;
		}
		lcp[pos[i]] = sameCount;
	}

	int sum = 0;
	for (int a : lcp) {
		sum += a;
	}
	int all = N * (N + 1) / 2;
	printf("%d", all - sum);

	return 0;
}