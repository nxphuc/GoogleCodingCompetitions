/*
Author: Nguyen Xuan Phuc
Created: 19/09/2021 00:55:28
*/

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

const int MAX = 16;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

ull f[1 << MAX];
ll sum[1 << MAX];
int l[MAX], r[MAX], a[MAX];
vi graph[MAX];

ull solve() {
    int n, m;
    ull k;
    cin >> n >> m >> k;

    int nMask = 1 << n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> a[i];
        graph[i].clear();
    }

    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for (int mask = 0; mask < nMask; mask++) {
        sum[mask] = 0;
        f[mask] = 0;
        for (int i = 0; i < n; i++)
            sum[mask] += a[i] * ((mask >> i) & 1);
    }

    for (int i = 0; i < n; i++)
        f[1 << i] = 1;

    for (int mask = 0; mask < nMask; mask++) {
        if (sum[mask] > k) continue;
        int visited = 0;
        for (int u = 0; u < n; u++)
            if ((mask >> u) & 1) {
                for (int v : graph[u]) {
                    if ((mask >> v) & 1) continue;
                    if ((visited >> v) & 1) continue;
                    if (l[v] <= sum[mask] && sum[mask] <= r[v]) {
                        f[mask | (1 << v)] += f[mask];
                        visited |= (1 << v);
                    }
                }
            }
    }
    ull res = 0;
    for (int i = 0; i < nMask; i++)
        if (sum[i] == k)
            res += f[i];
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