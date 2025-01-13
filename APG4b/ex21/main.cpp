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

int f0(int N) { return 1; }

int f1(int N, int M) {
    int s = 0;
    for (int i = 0; i < N; i++) {
        s++;
    }
    for (int i = 0; i < M; i++) {
        s++;
    }
    return s;
}

int f2(int N) {
    int s = 0;
    for (int i = 0; i < N; i++) {
        int t = N;
        int cnt = 0;
        while (t > 0) {
            cnt++;
            t /= 2;
        }
        s += cnt;
    }
    return s;
}

int f3(int N) {
    int s = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s++;
        }
    }
    return s;
}

int f4(int N) {
    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            s += i + j;
        }
    }
    return s;
}

int f5(int N, int M) {
    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            s += i + j;
        }
    }
    return s;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int a0 = -1, a1 = -1, a2 = -1, a3 = -1, a4 = -1, a5 = -1;

    // 計算量が最も大きいもの1つだけコメントアウトする
    a0 = f0(N);
    a1 = f1(N, M);
    a2 = f2(N);
    a3 = f3(N);
    // a4 = f4(N);
    a5 = f5(N, M);

    cout << "f0: " << a0 << endl;
    cout << "f1: " << a1 << endl;
    cout << "f2: " << a2 << endl;
    cout << "f3: " << a3 << endl;
    cout << "f4: " << a4 << endl;
    cout << "f5: " << a5 << endl;

    return 0;
}