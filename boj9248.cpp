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
//pos[x] : S[x:-1]�� �׷� ��ȣ
//sa[x] : suffix���� ����������, x��° suffix�� index
//temp[x] : suffix���� ����������, x��° suffix�� �׷��ȣ
//delta : delta*2�� �ڸ����� ���� ���̴�

bool cmp(int i, int j) {
	//pos[i]�� pos[j]�� delta �ڸ�����ŭ ���Ѵ�.
	//���⼭ pos[i]�� S[i:-1]�� �׷� ��ȣ�̴�.
	//(S[i:-1]�� �׷� ��ȣ < S[j:-1]�� �׷��ȣ) ���, 
	//S[i:-1]���� S[j:-1]�� �� ū suffix��� �ǹ��̴�.
	//�̷��� ���� ����� sa�� �ݿ��Ѵ�.
	//�� sa[i]�� sa[j]���� ������ ���ٸ�, S[i:-1]�� S[j:-1]���� ���� ���ڶ�� ���̴�.
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
	}//ó������, ��� suffix���� �׷��ȣ�� ����(temp�� ��� 0),
	 //S[x:-1]�� �׷� ��ȣ�� S[x]�� ���� �� ��ü�� ����(���� ��� a�� b���� ������ a�� 1�׷� b�� 2�׷�)
	 //������ ���� ���� �����̴� x��° suffix�� index�� x�� ����(sa[i] = i)

	for (delta = 1; ; delta *= 2) { //delta�� 2�辿 ����
		sort(sa, sa + N, cmp); //sa�� pos�� �������� ����

		for (int i = 1; i < N; i++) {
			temp[i] = temp[i - 1] + cmp(sa[i - 1], sa[i]);
		}//�׷� ��ȣ ����
		for (int i = 0; i < N; i++) {
			pos[sa[i]] = temp[i];
		}//pos ����

		if (temp[N - 1] == N - 1) break;
		memset(temp, 0, sizeof(temp));
	}

	for (int i = 0; i < N; i++) printf("%d ", sa[i] + 1);
	printf("\n");
	//������� suffix array
	//lcp�� ���� ����
	//���� pos[sa[i]]==i��.
	//�ֳ��ϸ�, pos(x) = x��� index�� ���� �̰�, (���� = �������� ���� ����)
	//sa(y) = y��° ������ index �̹Ƿ�
	//pos(sa(i)) = i������ index�� ���� = i��.
	//pos(x) �� sa(x)�� ����ȯ ����
	int sameCount = 0;
	for (int i = 0; i < N; i++) {
		if (sameCount > 0) sameCount--;
		if (sameCount < 0) sameCount = 0;
		if (pos[i] == 0) continue;
		int firstIndex = i;
		int nextIndex = sa[pos[firstIndex] - 1];
		//nextIndex�� suffix�� ����������, 
		//firstIndex�� �����ϴ� suffix���� �Ѵܰ� �� ū suffix�� index�̴�.
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