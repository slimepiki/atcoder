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

float calcd(int a, int b, int c, int d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

float calcd(pair<int, int> x, pair<int, int> y) {
    return calcd(x.first, x.second, y.first, y.second);
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, S, T;
    cin >> N >> S >> T;

    vector<pair<pair<int, int>, pair<int, int>>> sen;
    int a, b, c, d;
    vector<int> p;
    double write = 0;
    rep(i, N) {
        cin >> a >> b >> c >> d;
        write += calcd(a, b, c, d);
        sen.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
        p.push_back(i);
    }

    double mov = 1e10;
    do {
        double temp = 0;
        rep(j, 1 << N) {
            temp = 0;
            pair<int, int> pr = make_pair(0, 0);

            rep(i, N) {
                auto now = sen[p[i]];

                auto now1 = now.first;
                auto now2 = now.second;
                if (j & 1 << i) {
                    now1 = now.second;
                    now2 = now.first;
                }

                temp += calcd(pr, now1);
                pr = now2;
            }
        chmin(mov, temp);
        }
    } while (next_permutation(p.begin(), p.end()));

    debug(write / T, mov / S);
    cout<< setprecision(20) << write / T + mov / S << endl;

    return 0;
}