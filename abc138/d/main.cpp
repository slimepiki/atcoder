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

#define ii pair<int, int>
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
#define repit(it, a) for (auto it = a.begin(); it != a.end(); it++)

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

#define printa1d(a, W)                   \
    {                                    \
        rep(i, W) {                      \
            cout << a[i];                \
            if (i != W - 1) cout << ' '; \
        }                                \
        cout << endl;                    \
    }

#define printa2d(a, H, W)                 \
    {rep(i, H){rep(j, W){cout << a[i][j]; \
    if (j != W - 1) cout << ' ';          \
    }                                     \
    cout << endl;                         \
    }                                     \
    }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> eg(N, vector<int>());
    int a, b;
    rep(i, N - 1) {
        cin >> a >> b;
        a--;
        b--;
        eg[a].push_back(b);
        eg[b].push_back(a);
    }

    int p[N]{};

    rep(i, Q) {
        cin >> a >> b;
        a--;
        p[a] += b;
    }

    stack<ii> st;
    st.push(make_pair(0, 0));

    int ans[N]{};
    rep(i, N) ans[i] = -1;

    while (!st.empty()) {
        ii xp = st.top();
        st.pop();
        a = xp.first;
        b = xp.second;
        ans[a] = b + p[a];
        repit(it, eg[a]) {
            if (ans[*it] == -1) {
                st.push(make_pair(*it, ans[a]));
            }
        }
    }
    rep(i, N) {
        if (i != 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}