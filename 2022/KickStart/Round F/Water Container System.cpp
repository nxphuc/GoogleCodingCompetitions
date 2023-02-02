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
    int n, q;
    
    cin >> n >> q;
    vector<vector<int>> graph(n);
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        --u, --v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    for (int x, i = 0; i < q; i++) cin >> x;
    queue<int> qu;
    vector<int> lv(n, -1);
    qu.push(0);
    lv[0] = 0;
    vector<int> cnt(n, 0);
    cnt[0] = 1;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int v : graph[u]) {
            if (lv[v] == -1) {
                lv[v] = lv[u] + 1;
                cnt[lv[v]] += 1;
                qu.push(v);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (q >= cnt[i]) {
            res += cnt[i];
            q -= cnt[i];
        }
        else
            break;
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