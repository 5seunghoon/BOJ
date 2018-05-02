#define _CRT_SECURE_NO_WARNINGS
#define MYMAX2(A,B) (((A)>(B))?(A):(B)) 
#define MYMAX3(A,B,C) ( MYMAX2( (MYMAX2((A),(B))) , (C)) )
#define MYMIN2(A,B) (((A)<(B))?(A):(B)) 
#define MYMIN3(A,B,C) ( MYMIN2( (MYMIN2((A),(B))) , (C)) )
#define INT_MAX_MY 2100000000;
#include <string.h>
#include <iostream>

using namespace std;


int memoMax[2][3];
int memoMin[2][3];
int arr[3];
int N;


int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		memoMax[1][0] = MYMAX2(memoMax[0][0], memoMax[0][1]) + arr[0];
		memoMax[1][1] = MYMAX3(memoMax[0][0], memoMax[0][1], memoMax[0][2]) + arr[1];
		memoMax[1][2] = MYMAX2(memoMax[0][1], memoMax[0][2]) + arr[2];

		memoMin[1][0] = MYMIN2(memoMin[0][0], memoMin[0][1]) + arr[0];
		memoMin[1][1] = MYMIN3(memoMin[0][0], memoMin[0][1], memoMin[0][2]) + arr[1];
		memoMin[1][2] = MYMIN2(memoMin[0][1], memoMin[0][2]) + arr[2];


		for (int j = 0; j < 3; j++) {
			memoMax[0][j] = memoMax[1][j];
			memoMin[0][j] = memoMin[1][j];
		}

	}

	cout << MYMAX3(memoMax[1][0], memoMax[1][1], memoMax[1][2]) << " ";
	cout << MYMIN3(memoMin[1][0], memoMin[1][1], memoMin[1][2]);


	return 0;
}