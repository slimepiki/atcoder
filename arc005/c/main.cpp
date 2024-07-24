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

#define stackpp(st, x) \
    x = st.top();      \
    st.pop();
#define queuepp(q, x) \
    x = q.front();    \
    q.pop();
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
    static int H, W, sh, sw;

    cin >> H >> W;

    initsvvc(m, H, W, '#');

    bool ans = false;

    vector<queue<ii>> q(2);
    ii hw;
    int h, w;

    rep(i, H) {
        rep(j, W) {
            cin >> m[i][j];
            if (m[i][j] == 's') {
                sh = i;
                sw = j;
            }
        }
    }

    q[0].push(ii(sh, sw));

    rep(i, 5) {
        while (!q[i % 2].empty()) {
            hw = q[i % 2].front();
            q[i % 2].pop();
            iiget(hw, h, w);

            if (m[h][w] == 'v')
                continue;
            else if (m[h][w] == 'g') {
                ans = true;
                cout << "YES" << endl;
                return 0;
            }
            if (i % 2 == 0 && m[h][w] == '#'){
                q[1].push(ii(h, w));
                continue;
            }

            if (h > 0) {
                if (i % 2 == 0) {
                    if (m[h - 1][w] == '#')
                        q[1].push(ii(h - 1, w));
                    else if (m[h - 1][w] != 'v')
                        q[0].push(ii(h - 1, w));
                } else {
                    if (m[h - 1][w] != 'v') q[0].push(ii(h - 1, w));
                }
            }

            if (w > 0) {
                if (i % 2 == 0) {
                    if (m[h][w - 1] == '#')
                        q[1].push(ii(h, w - 1));
                    else if (m[h][w - 1] != 'v')
                        q[0].push(ii(h, w - 1));
                } else {
                    if (m[h][w - 1] != 'v') q[0].push(ii(h, w - 1));
                }
            }

            if (h < H - 1) {
                if (i % 2 == 0) {
                    if (m[h + 1][w] == '#')
                        q[1].push(ii(h + 1, w));
                    else if (m[h + 1][w] != 'v')
                        q[0].push(ii(h + 1, w));
                } else {
                    if (m[h + 1][w] != 'v') q[0].push(ii(h + 1, w));
                }
            }

            if (w < W - 1) {
                if (i % 2 == 0) {
                    if (m[h][w + 1] == '#')
                        q[1].push(ii(h, w + 1));
                    else if (m[h][w + 1] != 'v')
                        q[0].push(ii(h, w + 1));
                } else {
                    if (m[h][w + 1] != 'v') q[0].push(ii(h, w + 1));
                }
            }

            m[h][w] = 'v';
        }
    }

    cout << "NO" << endl;

    return 0;
}