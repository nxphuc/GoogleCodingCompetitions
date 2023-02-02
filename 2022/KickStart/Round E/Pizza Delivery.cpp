#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const ll INF = 1e15;
const double PI = acos(-1.0);
const double EPS = 1e-6;

int n, p, m;
ll f[21][11][11][(2 << 10) + 1];
// NEWS
pair<char, int> dir[4];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
map<ii, ii> pts;

void checkMax(ll& a, ll b) {
    a = max(a, b);
}

bool isValid(int x, int n) {
    return 0 <= x && x < n;
}

ll move(ll val, pair<char, int> dir) {
    if (dir.first == '+')
        return val + dir.second;
    if (dir.first == '-')
        return val - dir.second;
    if (dir.first == '*')
        return val * dir.second;
    return floor(1.0 * val / dir.second);
}

void solve() {
    int r, c;
    cin >> n >> p >> m >> r >> c;
    for (int i = 0; i < 4; i++)
        cin >> dir[i].first >> dir[i].second;
    --r; --c;
    pts.clear();
    for (int x, y, c, i = 0; i < p; i++) {
        cin >> x >> y >> c;
        pts[{x - 1, y - 1}] = {c, i};
    }

    int nMask = 1 << p;
    for (int t = 0; t <= m; t++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int mask = 0; mask < nMask; mask++)
                    if (i == r && j == c && mask == 0)
                        f[t][i][j][mask] = 0;
                    else
                        f[t][i][j][mask] = -INF;
    }
    for (int t = 0; t < m; t++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int mask = 0; mask < nMask; mask++) {
                    if (f[t][i][j][mask] == -INF) continue;
                    checkMax(f[t+1][i][j][mask], f[t][i][j][mask]);
                    ll val;
                    for (int x, y, d = 0; d < 4; d++) {
                        x = i + dx[d];
                        y = j + dy[d];
                        if (!isValid(x, n) || !isValid(y, n)) continue;
                        val = move(f[t][i][j][mask], dir[d]);
                        checkMax(f[t + 1][x][y][mask], val);
                        if (pts.find({x, y}) != pts.end()) {
                            auto temp = pts[{x, y}];
                            int newMask = mask | (1 << temp.second);
                            if (newMask != mask)
                                checkMax(f[t + 1][x][y][newMask], val + temp.first);
                        }
                    }
                }
    ll res = -INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            checkMax(res, f[m][i][j][nMask - 1]);
    if (res == -INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << res << "\n";
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}