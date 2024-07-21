using namespace std;
using ll = long long;
using ull = unsigned long long;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define ii tuple<int, int>
#define iiget(t, x, y) \
    x = get<0>(t);     \
    y = get<1>(t);
#define iii tuple<int, int, int>
#define iiiget(t, x, y, z) \
    x = get<0>(t);         \
    y = get<1>(t);         \
    z = get<2>(t);
#define vi vector<int>
#define initsvi(a, S, N) static vi a(S, N);
#define vvi vector<vi>
#define initsvvi(a, H, W, N) static vvi a(H, vi(W, N));
#define vll vector<ll>
#define initsvll(a, S, N) static vll a(S, N);

#define vc vector<char>
#define initsvc(a, S, N) static vc a(S, N);
#define vvc vector<vc>
#define initsvvc(a, H, W, N) static vvc a(H, vc(W, N));

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    initsvvc(m, 50, 50, '0');
    static int H, W, ans;
    static int wcount;
    static iii shw;
    static ii hw;
    static int s, h, w;

    cin >> H >> W;

    wcount = 0;
    ans = -1;

    rep(i, H) {
        rep(j, W) {
            cin >> m[i][j];
            if (m[i][j] == '.') wcount++;
        }
    }

    queue<iii> q;
    q.push(iii(0, 0, 0));
    while (!q.empty()) {
        shw = q.front();
        q.pop();
        iiiget(shw, s, h, w);

        if (h == H - 1 && w == W - 1) {
            ans = wcount - s - 1;
            break;
        }
        if (m[h][w] == '#') continue;

        if (h > 0)
            if (m[h - 1][w] == '.') q.push(iii(s + 1, h - 1, w));
        if (w > 0)
            if (m[h][w - 1] == '.') q.push(iii(s + 1, h, w - 1));
        if (h < H - 1)
            if (m[h + 1][w] == '.') q.push(iii(s + 1, h + 1, w));
        if (w < W - 1)
            if (m[h][w + 1] == '.') q.push(iii(s + 1, h, w + 1));
        m[h][w] = '#';
    }

    cout << ans << endl;

    return 0;
}