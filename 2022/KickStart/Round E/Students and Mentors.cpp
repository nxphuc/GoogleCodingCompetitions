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

void solve() {
    int n;
    cin >> n;
    vector<ii> a;
    for (int r, i = 0; i < n; i++) {
        cin >> r;
        a.emplace_back(r, i);
    }
    sort(a.begin(), a.end());
    vector<int> res(n, -1);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[j].first <= 2 * a[i].first) ++j;
        if (j - 1 == i)
            res[a[i].second] = j == 1 ? -1 : a[j - 2].first;
        else
            res[a[i].second] = a[j - 1].first;
    }
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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