#include <iostream>

using namespace std;

int n, k;
int arr[1000];

int Quicksort(int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (arr[low] <= pivot && low <= right)
		{
			low++;
		}
		while (arr[high] >= pivot && high >= (left+1))
		{
			high--;
		}
		if (low <= high)
		{
			int temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
			left++;
			right--;
		}
	}
	int temp2 = arr[left];
	arr[left] = arr[high];
	arr[high] = temp2;
	
	return high;
}

void Quicksortcase(int left, int right)
{
	if (left <= right)
	{
		int pivot = Quicksort(left, right);
		Quicksortcase(left, pivot - 1);
		Quicksortcase(pivot + 1, right);
	}
}


int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	Quicksortcase(0, n-1);

	cout << arr[k-1] << endl;
}