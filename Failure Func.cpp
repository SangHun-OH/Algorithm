#include <iostream>

using namespace std; 

char le[100];
//char cp[100];
int arr[100];
int noc;

void failure(char* line)
{
	int n = 0;
	int k;
	char cp[100];

	arr[0] = n;                  
	cp[0] = line[0];             

	for (int i = 1; i < noc; i++) {
		int num = 0;
		k = i;
		for (int j = i; j < n + i + 1; j++) {

			if (line[j - n] == cp[j - i]) {
				num++;
			}
		} 
		if (num == n + 1) {
			n++;
			cp[n] = line[n];
			arr[k] = n;
		}
		else if (num < n + 1 && cp[n-1] != line[i]) {
			arr[k] = 0;
		}
		else {
			arr[k] = n;
		}
	}
}

int main()
{
	cin >> noc;
	cin >> le;

	failure(le);

	for (int i = 0; i < noc; i++) {
		cout << arr[i] << " ";
	}
}
