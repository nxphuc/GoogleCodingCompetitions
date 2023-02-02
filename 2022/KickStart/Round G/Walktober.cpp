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

int solve() {
    int n, m, p;
    cin >> m >> n >> p;
    --p;
    vector<int> maxSteps(n, 0);
    vector<int> johSteps(n, 0);
    for (int i = 0; i < m; i++) {
        for (int x, j = 0; j < n; j++) {
            cin >> x;
            maxSteps[j] = max(maxSteps[j], x);
            if (i == p) johSteps[j] = x;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res += maxSteps[i] - johSteps[i];
    return res;
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
        cout << "Case #" << cs << ": " << solve() << "\n";
    }

    return 0;
}