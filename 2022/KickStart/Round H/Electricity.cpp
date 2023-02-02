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

vector<vector<int>> graph;
int n;
vector<int> f, a;

int dfs(int u) {
    if (f[u] != -1) return f[u];
    f[u] = 1;
    for (auto v : graph[u])
        f[u] += dfs(v);
    return f[u];
}

int solve() {
    cin >> n;
    f.assign(n, -1);
    graph.assign(n, vector<int>());
    a.assign(n, 0);
    for (auto& x : a) cin >> x;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        --u, --v;
        if (a[u] > a[v])
            graph[u].emplace_back(v);
        if (a[v] > a[u])
            graph[v].emplace_back(u);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dfs(i));

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