#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;
string i;
int main() {
	while (!cin.eof()) {
		getline(cin, i);
		cout << i << endl;
	}
	return 0;
}