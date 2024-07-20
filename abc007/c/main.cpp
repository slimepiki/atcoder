using namespace std;
using ll = long long;
using ull = unsigned long long;

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static int R, C, sy, sx, gy, gx;

    cin >> R >> C >> sy >> sx >> gy >> gx;

    queue<pair<int, pair<int, int>>> qu;

    pair<int, pair<int, int>> syx;
    int s, x, y;

    vector<vector<char>> m(R, vector<char>(C, '#'));

    for (int i = 0;i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> m[i][j];
        }
    }

    qu.push(pair(0, pair(sy - 1, sx - 1)));

    while (!qu.empty()) {
        syx = qu.front();
        qu.pop();
        s = syx.first;
        y = syx.second.first;
        x = syx.second.second;
        if (y == gy - 1 && x == gx - 1) {
            break;
        }
        if (m[y][x] == '#') continue;

        if (m[y - 1][x] == '.') qu.push(pair(s + 1, pair(y - 1, x)));
        if (m[y + 1][x] == '.') qu.push(pair(s + 1, pair(y + 1, x)));
        if (m[y][x - 1] == '.') qu.push(pair(s + 1, pair(y, x - 1)));
        if (m[y][x + 1] == '.') qu.push(pair(s + 1, pair(y, x + 1)));
        m[y][x] = '#';
    }

    cout << s << endl;

    return 0;
}