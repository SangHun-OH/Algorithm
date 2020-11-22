#include <iostream>
#include <queue>

using namespace std;

int node; 
int edge;
int u, v;



void Graph(queue<int> p)
{
	int x;

	x = p.size();
	int count = 0;
	int arr[100] = {0, };

	for (int j = 0; j < x; j++) {
		arr[p.front()]++;
		p.pop();
	}

	for (int z = 0; z < node; z++) {
		if (arr[z] == 0) {
			count = 1;
		}

	}

	if (count >= 1) {
		cout << "0" << endl;
	}
	else {
		cout << "1" << endl;
	}
}

int main()
{
	queue<int> que;

	cin >> node >> edge;

	for (int i = 0; i < edge; i++) {
		cin >> u >> v;
		que.push(u);
		que.push(v);
	}

	Graph(que);

}