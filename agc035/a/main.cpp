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

    int N;
    cin >> N;

    unordered_map<int, int> a;
    int x;
    rep(i, N) {
        cin >> x;
        if (a.count(x) == 0) {
            a[x] = 1;
        } else {
            a[x]++;
        }
        if (a.size() >= 4) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    vector<int> v;
    for (auto it = a.begin(); it != a.end(); it++) {
        debug(it->second);
        v.push_back(it->first);
    }
    sort(v.begin(),v.end());
    debug(a.size());
    if (a.size() == 1) {
        debug(a[v[0]]);
        if(v[0] == 0){
            cout << "Yes" << endl;
        }else cout << "No" << endl;
    } else if (a.size() == 2) {
        debug(a[v[0]],a[v[1]]);
        if(a[v[0]] == N/3 && a[v[1]] == N*2/3){
            cout << "Yes" << endl;
        }else cout << "No" << endl;
    } else if (a.size() == 3) {
        debug(a[v[0]],a[v[1]],a[v[2]]);
        if(a[v[0]] == a[v[1]]&&a[v[1]] == a[v[2]]){
            bitset<32> a = v[0],b = v[1],c = v[2];

            if((a^b^c).any()){
                cout << "No" << endl;
            }else cout << "Yes" << endl;
        }else cout << "No" << endl;
    }

    return 0;
}