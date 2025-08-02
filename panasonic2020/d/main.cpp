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
#define debug(...)                                                                                       \
    cerr << "\033[33m(line:" << __LINE__ << ") " << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); \
    cerr << "\033[m";
#else
#define debug(...)  //   :)
#endif
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
#define vvi vector<vi>
#define vvvi vector<vvvi>
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>

#define vc vector<char>
#define vvc vector<vc>
#define vvvc vector<vvc>

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
#define repit(it, a) for (auto it = a.begin(); it != a.end(); it++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    ll ct = pow(N, N);
    ll temp;
    string s;
    int l, bf;

    vector<string> code[2];
    code[1].push_back("1");

    rep(i, N) s += "a";
    rep(i, s.size()) {
        int r = i % 2;
        int nr = (i + 1) % 2;

        code[r].clear();
        repit(it, code[nr]) {
            char mx = '0';
            rep(j, it->size()) { chmax(mx, (*it)[j]); }
            rep(j, mx - '0' + 1) { code[r].push_back(((char)(j + '1')) + (*it)); }
        }
    }

    vector<string> ans;

    repit(it, code[N % 2]) {
        int tbl[N + 5]{};
        string s;
        char curr = 'a';
        rep(i, it->size()) {
            if (tbl[(*it)[i] - '1'] != 0) {
                s += tbl[(*it)[i] - '1'];
            } else {
                tbl[(*it)[i] - '1'] = curr;
                s += curr;
                ++curr;
            }
        }
        ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) { cout << ans[i] << endl; }
    return 0;
}