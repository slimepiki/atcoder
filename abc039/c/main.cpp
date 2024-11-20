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
#define debug(...) //   :)
#endif
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define repit(it, a) for(auto it = a.begin(); it != a.end();it++)

#define ii pair<int, int>
#define iiget(t, x, y) \
    x = t.first();    \
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

#define IINF 0x3f3f3f3f-10

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
    int ww[2];

    int wwc = 0;
    char pr = s[0];
    rep(i,1,s.size()){
        if(pr == 'W' && s[i] == 'W'){
            ww[wwc++] = i;
        }
        if(wwc >= 2)break;
        pr = s[i];
    }
    debug(ww[0], ww[1]);
    if(ww[0] == 5 && ww[1] == 12)cout << "Do" << endl;
    else if(ww[0] == 3 && ww[1] == 10)cout << "Re" << endl;
    else if(ww[0] == 1 && ww[1] == 8)cout << "Mi" << endl;
    else if(ww[0] == 7 && ww[1] == 12)cout << "Fa" << endl;
    else if(ww[0] == 5 && ww[1] == 10)cout << "So" << endl;
    else if(ww[0] == 3 && ww[1] == 8)cout << "La" << endl;
    else if(ww[0] == 1 && ww[1] == 6)cout << "Si" << endl;

    return 0;
}