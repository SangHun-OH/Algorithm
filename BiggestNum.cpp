#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#pragma warning (disable:4996)

int main() {

	int k, n, i, flag;
	char str[100001];
	char str2[100], str3[100];

	while (1) {
		cin >> n >> k;
		cin >> str;
		if (n < 0 || n>100000 || k > n || k > 10) {
			cout << "�Է¹��� ���Դϴ�." << endl;
		}
		if (strlen(str) != n) {
			cout << "�Էµ� n�� ���� ���� �ʽ��ϴ�." << endl;
		}
		else break;
	}
	for (i = 0; i < k; i++) {
		str2[i] = str3[i] = 0;
	}
	for (i = 0; i <= n - k; i++) {
		strncpy(str2, str + i, k);
		str2[k] = 0;
		if (strcmp(str2, str3) == 1) {
			strcpy(str3, str2);
		}
	}
	flag = 0;
	for (i = 0; i < k; i++) {
		if (str3[i] != '0') {
			flag = 1;
		}
		if (flag) cout << str3[i];
	}

	return 0;
}

//2016125039 ������ ����4