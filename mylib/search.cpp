#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rrep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
// 十字探索の方向
constexpr int fdir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

// 8方向探索の方向
constexpr int edir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0},
                            {1, 0},   {-1, 1}, {0, 1},  {1, 1}};

// rep(k, 4) {
//     int x = i + fdir[k][0], y = j + fdir[k][1];
//     if (x >= 0 && x < H && y >= 0 && y < W) {
//     }
// }

// rep(k, 8) {
//     int x = i + edir[k][0], y = j + edir[k][1];
//     if (x >= 0 && x < H && y >= 0 && y < W) {
//     }
// }