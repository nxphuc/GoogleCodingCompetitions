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
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;
const double GAMMA = 0.57721566490153286060651209008240243104215933593992;

inline double fastCalculate(double n) {
    return log(n) + GAMMA + 1.0 / (2 * n) - 1.0 / (12 * n * n) + 1.0 / (120 * n * n * n * n);
}

double solve() {
    ll n;
    cin >> n;
    if (n > 10)
        return fastCalculate(n);
    vector<double> f(n + 1);
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + 1.0 / i;
    return f[n];
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(12);
    cout << fixed;

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << solve() << "\n";
    }

    return 0;
}