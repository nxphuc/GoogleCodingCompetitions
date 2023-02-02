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

double solve() {
    ll res;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    res = accumulate(a.end() - m + 1, a.end(), 0);
    a.resize(n - m + 1);
    int mid = a.size() / 2;
    if (a.size() & 1) {
        return res + a[mid];
    }
    return res + (a[mid] + a[mid - 1]) / 2.0;
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(2);
    cout << fixed;

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << solve() << "\n";
    }

    return 0;
}