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

int getind(int x, int y, int z, int n) {
    
     return x%2 * n * n + y * n + z; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    char* m= nullptr;
    try {
        m = new char[2 * N * N];
    }catch(const std::bad_alloc& e){
        return 1;
    }
    rep(i, N * N) { cin >> m[getind(0, i / N, i % N, N)]; }

    rep(i, 1, N / 2 + 1) {
        rep(y, 1, N + 1) {
            rep(x, 1, N + 1) {
                if (y >= i && y <= N + 1 - i && x >= i && x <= N + 1 - i)
                    m[getind(i, y - 1, N + 1 - x - 1, N)] =
                        m[getind(i-1, x - 1, y - 1, N)];
                else
                    m[getind(i, y - 1, N + 1 - x - 1, N)] =
                        m[getind(i-1, y - 1, N + 1 - x - 1, N)];
            }
        }
    }

    rep(x, N) {
        rep(y, N) { cout << m[getind(N / 2, x, y, N)]; }
        cout << endl;
    }

    delete[] m;

    return 0;
}