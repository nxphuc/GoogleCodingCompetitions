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

const int MAX = 61;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

double f[MAX][MAX][MAX];
int path[MAX][MAX][MAX];

void solve() {
    double w, e;
    memset(f, 0, sizeof f);
    memset(path, -1, sizeof path);

    cin >> w >> e;
    f[1][0][0] = f[0][1][0] = f[0][0][1] = (w + e) / 3.0;
    path[1][0][0] = 0;
    path[0][1][0] = 1;
    path[0][0][1] = 2;
    double res = -1;
    int si, sj, sk;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; i + j < MAX; j++)
            for (int k = 0; i + j + k < MAX; k++) {
                if (i + j + k < 2) continue;
                f[i][j][k] = -1;
                int prevDays = i + j + k - 1;
                if (i > 0 && f[i][j][k] < f[i - 1][j][k] + w * j / prevDays + e * k / prevDays) {
                    f[i][j][k] = f[i - 1][j][k] + w * j / prevDays + e * k / prevDays;
                    path[i][j][k] = 0;
                }
                if (j > 0 && f[i][j][k] < f[i][j - 1][k] + w * k / prevDays + e * i / prevDays) {
                    f[i][j][k] = f[i][j - 1][k] + w * k / prevDays + e * i / prevDays;
                    path[i][j][k] = 1;
                }
                if (k > 0 && f[i][j][k] < f[i][j][k - 1] + w * i / prevDays + e * j / prevDays) {
                    f[i][j][k] = f[i][j][k - 1] + w * i / prevDays + e * j / prevDays;
                    path[i][j][k] = 2;
                }
                if (i + j + k == MAX - 1 && res < f[i][j][k]) {
                    res = f[i][j][k];
                    si = i;
                    sj = j;
                    sk = k;
                }
            }
    string s;
    string pattern = "RPS";
    while (si > 0 || sj > 0 || sk > 0) {
        s += pattern[path[si][sj][sk]];
        if (path[si][sj][sk] == 0)
            --si;
        else if (path[si][sj][sk] == 1)
            --sj;
        else
            --sk;
    }
    reverse(s.begin(), s.end());
    
    cout << s << "\n";
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, x;
    cin >> t;
    cin >> x;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}