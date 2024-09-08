using namespace std;
using ll = long long;
using ull = unsigned long long;

#include <bits/stdc++.h>

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef __LOCAL
#define debug(...)                                                      \
    cerr << "\033[33m(line:" << __LINE__ << ") " << "[" << #__VA_ARGS__ \
         << "]:",                                                       \
        debug_out(__VA_ARGS__);                                         \
    cerr << "\033[m";
#else
#define debug(...)  //   :)
#endif
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
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
#define vvi vector<vi>
#define vvvi vector<vvvi>
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>

#define vc vector<char>
#define vvc vector<vc>
#define vvvc vector<vvc>

#define IINF 0x3f3f3f3f - 10

template <typename T>
inline bool chmin(T& a, const T& b) {
    bool compare = a > b;
    if (a > b) a = b;
    return compare;
}
template <typename T>
inline bool chmax(T& a, const T& b) {
    bool compare = a < b;
    if (a < b) a = b;
    return compare;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int H, W, Q, r, c;

    cin >> H >> W >> Q;

    vector<set<int>> gr(H), gc(W);

    rep(i, H) rep(j, W) {
        gr[i].insert(j);
        gc[j].insert(i);
    }
    ll ans = H * W;
    auto erase = [&](int i, int j) {
        debug(i,j);
        gr[i].erase(j);
        gc[j].erase(i);
        ans--;
    };

    while (cin >> r >> c) {
        r--, c--;

        if (gr[r].count(c)) {
            erase(r, c);
            continue;
        }

        {
            auto it = gc[c].lower_bound(r);
            if (it != begin(gc[c])) erase(*prev(it), c);
        }

        {
            auto it = gc[c].lower_bound(r);
            if (it != end(gc[c])) erase(*it, c);
        }

                {
            auto it = gr[r].lower_bound(c);
            if (it != begin(gr[r])) erase(r, *prev(it));
        }

                {
            auto it = gr[r].lower_bound(c);
            if (it != end(gr[r])) erase(r, *it);
        }
    }

    cout << ans << endl;

    return 0;
}