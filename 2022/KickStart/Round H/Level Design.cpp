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

struct DSU {
private:
    vector<int> p, sz;
    int n;
public:
    DSU(int n = 0) : n(n) {
        p.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int u) {
        return p[u] = u == p[u] ? u : get(p[u]);
    }

    void unionize(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return;
        if (sz[u] < sz[v])
            swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }

    bool same(int u, int v) {
        return get(u) == get(v);
    }

    int size(int u) {
        return sz[get(u)];
    }

    bool isRoot(int u) {
        return u == get(u);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) {
        cin >> x;
        --x;
    }
    DSU dsu(n);
    for (int i = 0; i < n; i++)
        dsu.unionize(i, p[i]);
    vector<int> f(n + 5, INF);
    f[0] = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
        if (dsu.isRoot(i))
            cnt[dsu.size(i)]++;
    
    for (auto [x, y] : cnt) {
        vector<int> fNew(n + 5, INF);
        for (int i = 0; i < x; i++) {
            deque<int> dq;
            for (int j = 0; ; j++) {
                if (i + x * j > n) break;
                while (!dq.empty() && f[i + x * j] - j < f[i + x * dq.back()] - dq.back())
                    dq.pop_back();
                dq.push_back(j);

                while (!dq.empty() && dq.front() < j - y) dq.pop_front();
                fNew[i + x * j] =  f[i + x * dq.front()] - dq.front() + j;
            }
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; ; j++) {
                if (i + x * j > n) break;
                f[i + x * j] = fNew[i + x * j];
            }
        }
    }
    vector<int> f2 = f;
    for (int i = n - 1; i >= 0; i--)
        f2[i] = min(f2[i], f2[i + 1]);
    for (int i = 1; i <= n; i++)
        if (cnt.count(i) > 0)
            cout << "0 ";
        else
            cout << min(f[i] - 1, f2[i]) << " ";
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