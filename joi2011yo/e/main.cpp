using namespace std;
using ll = long long;
using ull = unsigned long long;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define ii tuple<int, int>
#define iii tuple<int,int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static vector<vector<char>> m(1000, vector<char>(1000));
    static vector<vector<char>> ckm(1000, vector<char>(1000));
    static int H, W, N, sh, sw, ans;

    static pair<int, pair<int, int>> shw;
    static pair<int, int> hw;
    static int s, h, w;

    cin >> H >> W >> N;

    rep(i, H) {
        rep(j, W) {
            cin >> m[i][j];
            if (m[i][j] == 'S') {
                sh = i;
                sw = j;
            }
        }
    }

    ans = 0;

    rep(i, 1, N + 1) {
        queue<pair<int, pair<int, int>>> q;
        copy(m.begin(), m.end(), ckm.begin());

        q.push(pair(0, pair(sh, sw)));
        while (!q.empty()) {
            shw = q.front();
            q.pop();
            s = shw.first;
            hw = shw.second;
            h = hw.first;
            w = hw.second;

            if (ckm[h][w] == 'X')
                continue;
            else if (ckm[h][w] == i + '0') {
                ans += s;
                sh = h;
                sw = w;
                break;
            }

            if (h < H - 1) {
                if (ckm[h + 1][w] != 'X') q.push(pair(s + 1, pair(h + 1, w)));
            }
            if (w < W - 1) {
                if (ckm[h][w + 1] != 'X') q.push(pair(s + 1, pair(h, w + 1)));
            }
            if (h > 0) {
                if (ckm[h - 1][w] != 'X') q.push(pair(s + 1, pair(h - 1, w)));
            }
            if (w > 0) {
                if (ckm[h][w - 1] != 'X') q.push(pair(s + 1, pair(h, w - 1)));
            }
            ckm[h][w] = 'X';
        }
    }

    cout << ans << endl;

    return 0;
}