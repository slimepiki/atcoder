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
#define repit(it, a) for (auto it = a.begin(); it != a.end(); it++)

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

string makeNumStr(int x) {
    string ret;
    int cp = x;
    if (x <= 0) return "YABAI";
    while (x < 100000) {
        x *= 10;
        ret += '0';
    }
    return ret + to_string(cp);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<ii>> vm(N, vector<ii>());
    int y, p;
    rep(i, M) {
        cin >> p >> y;
        debug(i, p, y);
        vm[p - 1].push_back(make_pair(i, y));
    }

    rep(i, N) {
        sort(vm[i].begin(), vm[i].end(),
             [](ii x, ii y) { return x.second < y.second; });
    }

    string ban[M]{};
    rep(i, N) {
        rep(j, vm[i].size()) {
            debug(i, j, vm[i][j].first, vm[i][j].second);
            ban[vm[i][j].first] = makeNumStr(i + 1) + makeNumStr(j + 1);
        }
    }

    rep(i, M) cout << ban[i] << endl;
    return 0;
}