#include<iostream>

using namespace std;

int main()
{
	int D[46];
	int n;

	while (1) {
		cin >> n;

		if (n <= 45 && n > 0) {
			for (int i = 1; i <= n; i++)
			{
				if (i <= 2)
				{
					D[i] = 1;
					continue;
				}
				if (i == 3)
				{
					D[i] = 2;
					continue;
				}
				D[i] = D[i - 1] + D[i - 3];
			}
			cout << D[n] << endl;
			break;
		}
		else {
			cout << "입력범위 확인 \n";
		}
	}
	return 0;
}

// 2016125039 오상훈
