#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back

const int MAX = 510;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

vector<iii> edges;
int b[MAX][MAX];
int parent[2*MAX], level[2*MAX];
int n;

int findSet(int u) {
    return parent[u] = parent[u] == u ? u : findSet(parent[u]);
}

bool unionSet(int u, int v) {
    int pu = findSet(u);
    int pv = findSet(v);

    if (pu == pv) return false;
    if (level[pu] > level[pv]) {
        parent[pv] = pu;
    }
    else if (level[pu] < level[pv]) {
        parent[pu] = pv;
    }
    else {
        level[pu]++;
        parent[pv] = pu;
    }
    return true;
}

ll solve() {
    cin >> n;

    edges.clear();
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp == -1) {
                edges.push_back(make_pair(-1, make_pair(i, j+n)));
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
            res += b[i][j];
        }
    }
    for (int i = 0; i < 2*n; i++)
        cin >> temp;

    for (auto& e : edges) {
        e.first = b[e.second.first][e.second.second - n];
    }

    sort(edges.begin(), edges.end(), greater<iii>());

    for (int i = 0; i < 2*n; i++) {
        parent[i] = i;
        level[i] = 0;
    }

    for (auto e : edges) {
        if (unionSet(e.second.first, e.second.second)) {
            res -= e.first;
        }
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