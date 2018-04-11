//https://kks227.blog.me/221028710658
//https://stackoverflow.com/questions/17761704/suffix-array-algorithm

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
int sa[MAX], temp[MAX], pos[MAX], N, delta, lcp[MAX];
char S[MAX];
//pos[x] : S[x:-1]의 그룹 번호
//sa[x] : suffix들을 정렬했을때, x번째 suffix의 index
//temp[x] : suffix들을 정렬했을때, x번째 suffix의 그룹번호
//delta : delta*2의 자릿수만 비교할 것이다

bool cmp(int i, int j) {
	//pos[i]와 pos[j]를 delta 자릿수만큼 비교한다.
	//여기서 pos[i]는 S[i:-1]의 그룹 번호이다.
	//(S[i:-1]의 그룹 번호 < S[j:-1]의 그룹번호) 라면, 
	//S[i:-1]보다 S[j:-1]가 더 큰 suffix라는 의미이다.
	//이렇게 비교한 결과를 sa에 반영한다.
	//즉 sa[i]가 sa[j]보다 앞으로 간다면, S[i:-1]이 S[j:-1]보다 작은 숫자라는 뜻이다.
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += delta;
	j += delta;
	return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

int main() {
	scanf("%s", S);
	N = strlen(S);

	for (int i = 0; i < N; i++) {
		sa[i] = i;
		pos[i] = S[i] - 'a';
		temp[i] = 0;
	}//처음에는, 모든 suffix들의 그룹번호가 같고(temp가 모두 0),
	 //S[x:-1]의 그룹 번호는 S[x]의 문자 그 자체와 같고(예를 들어 a는 b보다 빠르니 a는 1그룹 b는 2그룹)
	 //정렬을 하지 않은 상태이니 x번째 suffix의 index는 x와 같다(sa[i] = i)

	for (delta = 1; ; delta *= 2) { //delta는 2배씩 증가
		sort(sa, sa + N, cmp); //sa를 pos를 기준으로 정렬

		for (int i = 1; i < N; i++) {
			temp[i] = temp[i - 1] + cmp(sa[i - 1], sa[i]);
		}//그룹 번호 갱신
		for (int i = 0; i < N; i++) {
			pos[sa[i]] = temp[i];
		}//pos 갱신

		if (temp[N - 1] == N - 1) break;
		memset(temp, 0, sizeof(temp));
	}

	for (int i = 0; i < N; i++) printf("%d ", sa[i] + 1);
	printf("\n");
	//여기까지 suffix array
	//lcp를 구할 차례
	//이제 pos[sa[i]]==i임.
	//왜냐하면, pos(x) = x라는 index의 순번 이고, (순번 = 정렬했을 때의 순번)
	//sa(y) = y번째 순번의 index 이므로
	//pos(sa(i)) = i순번의 index의 순번 = i임.
	//pos(x) 와 sa(x)는 역변환 관계
	int sameCount = 0;
	for (int i = 0; i < N; i++) {
		if (sameCount > 0) sameCount--;
		if (sameCount < 0) sameCount = 0;
		if (pos[i] == 0) continue;
		int firstIndex = i;
		int nextIndex = sa[pos[firstIndex] - 1];
		//nextIndex는 suffix를 정렬했을때, 
		//firstIndex로 시작하는 suffix보다 한단계 더 큰 suffix의 index이다.
		while (true) {
			if (((firstIndex + sameCount) >= N) || ((nextIndex + sameCount) >= N)) break;
			if (S[firstIndex + sameCount] == S[nextIndex + sameCount]) sameCount++;
			else break;
		}
		lcp[pos[i]] = sameCount;
	}
	printf("x ");
	for (int i = 1; i < N; i++) printf("%d ", lcp[i]);

	return 0;
}