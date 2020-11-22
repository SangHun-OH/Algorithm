#include <iostream>


using namespace std;


int ne, me;
int xe, ye; 


void Graph(int n, int m, int x, int y)
{
	int u, v;

	int num;

	int arr2[100][100] = { 0, };
	int arr[100] = { 0, };

	int minedge = 0;

	for (int i = 0; i < m; i++) 
	{
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}
		arr2[u][v]++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr2[i][j] == 1) {
				arr[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			arr2[j][i] = arr2[i][j];
		}
	}

	num = x;

	for (int i = num; i < n; i++) {
		if (arr2[num][i] == 1) {
			num = i;
			minedge++;
		}
		if (num == y) {
			cout << minedge;
		}
		else if (minedge > n - 1 || arr[num] == 0) {
			minedge += 100;
		}

	}
	if (minedge >= 100) {
		cout << "0";
	}
}

int main()
{

	cin >> ne >> me;

	cin >> xe >> ye;

	Graph(ne, me, xe, ye);

}