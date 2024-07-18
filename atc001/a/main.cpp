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

    stack<pair<int, int>> st;
    pair<int, int> xy;
    int H, W;
    int sx, sy, x, y;
    cin >> H >> W;
    bool ans;

    ans = false;

    static vector<vector<char>> m(W, vector<char>(H, '.'));

    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++) {
            cin >> m[i][j];
            if (m[i][j] == 's') {
                sx = i;
                sy = j;
            }
        }

    st.push(pair(sx, sy));

    while (!st.empty()) {
        xy = st.top();
        st.pop();
        x = xy.first;
        y = xy.second;
        if (m[x][y] != '#') {
            m[x][y] = '#';
            if (x < W - 1 && m[x + 1][y] != '#') {
                if (m[x + 1][y] == 'g') {
                    ans = true;
                    break;
                }
                st.push(pair(x + 1, y));
            }
            if (x > 0 && m[x - 1][y] != '#') {
                if (m[x - 1][y] == 'g') {
                    ans = true;
                    break;
                }
                st.push(pair(x - 1, y));
            }
            if ( y > 0 && m[x][y - 1] != '#') {
                if (m[x][y - 1] == 'g') {
                    ans = true;
                    break;
                }
                st.push(pair(x, y - 1));
            }
            if ( y < H - 1 && m[x][y + 1] != '#') {
                if (m[x][y + 1] == 'g') {
                    ans = true;
                    break;
                }
                st.push(pair(x, y + 1));
            }
            m[x][y] = '#';
        }
    }

    if (ans == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}