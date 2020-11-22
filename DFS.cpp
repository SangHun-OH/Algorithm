#include <iostream>
#include <algorithm>

using namespace std;

int adj[202][202];
int visit[202];
int DFS(int n){
    if(n == 201) return 1;
    if(visit[n]) return 0;
    visit[n] = 1;

    for(int i = 0; i <= 201; i++){
        if(adj[n][i]){
            int ret = DFS(i);
            if(ret){
                adj[n][i]--;
                adj[i][n]++;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int a, b, n;
    while(true){
        cin >> a >> b >> n;
        if((1 <= a && a <= 100 ) && (1 <= b && b <= 100) && (1 <= n && n <= a * b))
            break;
        else
            cout << "입력된 수가 범위를 벗어났습니다. (1 <= a, b <= 100, 1 <= n <= a * b)를 만족해야합니다" << endl;
    }
    for(int i = 0; i < n; i++){
        int x, y;
        while(true){
            cin >> x >> y;

            if((1 <= x && x <= a) && (1 <= y && y <= b))
                break;
            else
                cout << "입력된 수가 범위를 벗어났습니다. (1 <= i <= " << a << ", 1 <= j <= " << b << ")를 만족해야합니다." << endl;
        }

        adj[x][100 + y] = 1;
    }
    for(int i = 1; i <= 100; i++){
        adj[0][i] = 1;
    }
    for(int i = 101; i <= 200; i++){
        adj[i][201] = 1;
    }
    int result = 0;
    while(DFS(0)){
        result++;
        fill(visit, visit + 202, 0);
    }
    cout << result;
}