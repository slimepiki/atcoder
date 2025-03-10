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

    string s;
    cin >> s;

    bool plr = (s[0] == 'L'), lr;
    bool llg = false;

    int ct = 0;
    int lct = 1;

    vector<tuple<int, int, bool>> v;

    rep(i, 1, s.size()) {
        lr = (s[i] == 'L');
        if (plr != lr) {
            if (s[i] == 'R') {
                llg = (lct % 2 == 1);
                //                debug(lct, ct);
                v.push_back(make_tuple(i - ct - 1, ct + lct, llg));
                lct = 0;

            } else {
                ct = 0;
            }
        }
        if (lr) {
            ct++;
        } else
            lct++;

        plr = lr;
    }

    if (lct != 0 || ct != 0) {
        llg = (lct % 2 == 1);
        v.push_back(make_tuple(s.size() - ct - 1, lct + ct, llg));
    }

    int p;

    int ans[s.size()]{};
    rep(i, v.size()) {
        auto item = v[i];
        p = get<0>(item);
        ct = get<1>(item);
        llg = get<2>(item);
        if (ct % 2 == 0) {
            ans[p] = ct / 2;
            ans[p + 1] = ct / 2;
        } else {
            if (llg) {
                ans[p] = ct / 2 + 1;
                ans[p + 1] = ct / 2;
            } else {
                ans[p + 1] = ct / 2 + 1;
                ans[p] = ct / 2;
            }
        }
    }

    rep(i, s.size()) {
        if (i != 0) cout << ' ';
        cout << ans[i];
    }

    cout << endl;
    return 0;
}