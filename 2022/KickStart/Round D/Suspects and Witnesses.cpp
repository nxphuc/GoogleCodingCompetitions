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
int n, m, k;
int cnt;
int vis[MAX];

bool canSteal(int u) {
    int mark = u;
    queue<int> q;
    q.emplace(u);
    vis[u] = mark;
    int cnt = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (vis[v] != mark) {
                vis[v] = mark;
                q.emplace(v);
                ++cnt;
                if (cnt > k) return false;
            }
        }
    }
    return true;
}

int solve() {
    cin >> n >> m >> k;
    
    graph.assign(n, vector<int>());
    memset(vis, -1, sizeof vis);

    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        graph[--v].emplace_back(--u);
    }
    int res = n;
    for (int i = 0; i < n; i++) {
        res -= canSteal(i);
    }
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