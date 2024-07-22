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

#define INF INT_MAX

#include <bits/stdc++.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    static int H, W, ans;

    queue<ii> q;

    ii hw;
    char c;

    cin >> H >> W;
    initsvvi(cm, H, W, INF);

    rep(i, H) {
        rep(j, W) {
            cin >> c;
            if (c == '#') cm[i][j] = 0;
            q.push(ii(i, j));
        }
    }

    while (!q.empty()) {
        hw = q.front();
        q.pop();
        int h,w;
        iiget(hw, h, w);

        if (h > 0 && (cm[h][w] < cm[h - 1][w] - 1)) {
            cm[h - 1][w] = cm[h][w] + 1;
            q.push(ii(h - 1, w));
        }
        if (w > 0 && (cm[h][w] < cm[h][w - 1] - 1)) {
            cm[h][w - 1] = cm[h][w] + 1;
            q.push(ii(h, w-1));
        }
        if (h < H - 1 && (cm[h][w] < cm[h + 1][w] - 1)) {
            cm[h + 1][w] = cm[h][w] + 1;
            q.push(ii(h + 1, w));
        }
        if (w < W - 1 && (cm[h][w] < cm[h][w + 1] - 1)) {
            cm[h][w + 1] = cm[h][w] + 1;
            q.push(ii(h, w + 1));
        }
    }
    ans = 0;

    rep(i, H) {
        rep(j, W) {
            ans = max(ans, cm[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}