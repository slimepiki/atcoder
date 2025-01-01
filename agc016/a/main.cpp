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
    x = t.first();     \
    y = t.second();
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

    char a;

    int ans = IINF;
    int tmp, r, nr;
    string t[2];
    bool good;

    bool ck[26]{};

    rep(i,s.size()){
        ck[s[i]-'a'] = true;
    }

    rep(i, 26) {//a~z
        a = 'a' + i;
        t[0] = s;
        tmp = 0;
        r = 0;
        nr = 1;
        if(!ck[i])continue;

        while (true) {//mainloop
            good = true;
            //cout << t[r]<< endl;
            rep(i, t[r].size()) {//iscomplete
                if (t[r][i] != a) {
                    good = false;
                    break;
                }
            }
            if (good) {
                break;
            } else {
                t[nr] = "";

                rep(j, t[r].size() - 1) {//greedy
                    if (t[r][j] == a || t[r][j+1] == a)
                        t[nr] += a;
                    else
                        t[nr] += t[r][j];
                }
                tmp++;
            }
            r = (r%2 + 1)%2;
            nr = (r + 1)%2;
            //debug(r,nr);
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}