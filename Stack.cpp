#include <iostream>
#include <stack>
#include <stdio.h>
#include <algorithm>


using namespace std;


struct Coords {
    int x, y;
    int rx,ry;
    Coords(int x1 = 0, int y1 = 0) : x(x1), y(y1), rx(1), ry(0) {}
};

bool comp(const Coords& A, const Coords& B) {
    if (1LL * A.ry * B.rx != 1LL * A.rx * B.ry)
        return 1LL * A.ry * B.rx < 1LL * A.rx * B.ry;
}

long long int ccw(const Coords& A, const Coords& B, const Coords& C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

Coords points[100002];
int n, m;
void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Coords(x, y);
    }
}
int main() {
    input();
    sort(points, points + m, comp);

    for (int i = 1; i < m; i++) {
        points[i].rx = points[i].x - points[0].x;
        points[i].ry = points[i].y - points[0].y;
    }

    sort(points + 1, points + m, comp);

    stack<int> stack;
    stack.push(0);
    stack.push(1);

    int next = 2;

    while (next < m) {
        while (stack.size() >= 2) {
            int first, second;
            second = stack.top();
            stack.pop();
            first = stack.top();

            if (ccw(points[first], points[second], points[next]) > 0) {
                stack.push(second);
                break;
            }
        }

        stack.push(next++);
    }

    printf("%d %d", stack.size(), m - stack.size());
    return 0;
}

// 2016125039 ø¿ªÛ»∆
/*
100 6
1 1
2 3
1 5
5 5
4 3
5 1
*/