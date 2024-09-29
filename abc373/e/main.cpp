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

#define pllll pair<ll, ll>
#define vpllll vector<pllll>

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

    ll N, M, K;
    cin >> N >> M >> K;

    ll nokori = K;
    vpllll na;
    ll ans[N];
    ll yoyu;

    ll a;
    rep(i, N) {
        cin >> a;
        na.push_back(make_pair(i, a));
        nokori -= a;
        ans[i] = -1;
    }

    sort(na.begin(), na.end(),
         [](pllll& x, pllll& y) { return x.second < y.second; });

    // 票数を考えない場合のM未満になる人の最低票数
    ll kasou = na[N - M].second + 1;
    debug(kasou)
    // kasouでの票の余裕
    yoyu = 0;
    rep(i, N - M) { 
        debug(kasou - na[i].second);
        yoyu += kasou - na[i].second; }
    debug(yoyu);
    rep(i, N) {
        ll hito = na[i].first, hyo = na[i].second;
        ll cy = yoyu;
        ll place = 0;

        if (i >= N - M) {
            cy = yoyu + (na[i].second - kasou) * i;
            place = i -1;
        }
        else {
            cy = yoyu - hyo;
            place = N - M - 1;
        }
        if (kasou - hyo > nokori)
            continue;
        else {
            ll j = 0;
            while (true) {
                if (cy + j * place >= nokori) {
                    debug(hito, hyo, cy);
                    if (i >= N - M) {
                        ans[hito] = j;

                    } else {
                        ans[hito] = kasou - hyo + j;
                    }
                    break;
                }
                j++;
            }
        }
    }

    rep(i, N) {
        cout << ans[i];
        if (i != N - 1) cout << ' ';
    }
    cout << endl;
    return 0;
}