#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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

/**
 *  Basic Segment Tree - Template
 *
 *  Tested:
 *  - https://codeforces.com/contest/61/problem/E
 *  - https://codeforces.com/contest/380/problem/C
 *  - https://codeforces.com/contest/474/problem/F
 *  - All Segment Tree problems in course Big-O Competitive Programming - Level 3
 */

template<
    class T,                      // data type
    T (*op) (const T&, const T&), // operator to combine 2 child nodes
    T (*e) ()                     // identity element
>
class SegmentTree{
private:
    vector<T> seg;
    int n, log, size;

    void update(int id, int l, int r, int p, T v) {
        if (l == r) {
            seg[id] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (m >= p)
            update(2 * id + 1, l, m, p, v);
        else
            update(2 * id + 2, m + 1, r, p, v);
        seg[id] = op(seg[2 * id + 1], seg[2 * id + 2]);
    }

    T query(int id, int l, int r, int u, int v) {
        if (v < l || u > r)
            return e();
        if (u <= l && r <= v)
            return seg[id];
        int m = (l + r) >> 1;
        return op(query(2 * id + 1, l, m, u, v), query(2 * id + 2, m + 1, r, u, v));
    }

    void build(const vector<T>& v, int id, int l, int r) {
        if (l == r) {
            seg[id] = v[l];
            return;
        }
        int m = (l + r) >> 1;
        build(v, 2 * id + 1, l, m);
        build(v, 2 * id + 2, m + 1, r);
        seg[id] = op(seg[2 * id + 1], seg[2 * id + 2]);
    };
public:
    explicit SegmentTree(int n = 0) : SegmentTree(vector<T>(n, e())) {}

    explicit SegmentTree(const vector<T>& v) : n(v.size()) {
        log = ceil(log2(n));
        size = 1 << log;
        seg = vector<T>(2 * size);
        build(v, 0, 0, n - 1);
    }

    void update(int pos, T val) {
        update(0, 0, n - 1, pos, val);
    }

    T query(int from, int to) {
        return query(0, 0, n - 1, from, to);
    }
};

template<
    class T,                      // data type
    T (*op) (const T&, const T&), // operator to combine 2 child nodes
    T (*e) ()                     // identity element
>
class HLD : private SegmentTree<T, op, e> {
private:
    vector<int> nxt, sz, in, par,dep;
    vector<vector<int>> adj;
    int n, num;

    void dfsSize(int u, int p = -1, int d = 0) {
        sz[u] = 1;
        par[u] = p;
        dep[u] = d;

        for (int& v : adj[u]) {
            if (v == p) continue;
            dfsSize(v, u, d+1);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]])
                swap(v, adj[u][0]);
        }
    }

    void dfsHLD(int u, int p = -1) {
        in[u] = num++;
        for (int v : adj[u]) {
            if (v == p) continue;
            nxt[v] = (v == adj[u][0] ? nxt[u] : v);
            dfsHLD(v, u);
        }
    }
public:
    explicit HLD(int n = 0) :
        SegmentTree<T, op, e>(n), nxt(n), sz(n), in(n), par(n), dep(n), adj(n) {}

    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    inline int parent(int u) {
        return par[u];
    }

    void build(int root = 0) {
        num = 0;
        dfsSize(root, -1, 0);
        nxt[root] = root;
        dfsHLD(root);
    }

    void update(int u, T val) {
        SegmentTree<T, op, e>::update(in[u], val);
    }

    T query(int u, int v) {
        T res = e();
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (nxt[u] == nxt[v]) break;
            res = op(res, SegmentTree<T, op, e>::query(in[nxt[v]], in[v]));
            v = par[nxt[v]];
        }
        return op(res, SegmentTree<T, op, e>::query(in[u], in[v]));
    }
};

struct Ops {
    using T = ll;
    inline static T op(const T& a, const T& b) {
        return __gcd(a, b);
    }

    inline static T e() { return 0; }
};

using SegTree = SegmentTree<Ops::T, Ops::op, Ops::e>;
using HLDSegTree = HLD<Ops::T, Ops::op, Ops::e>;

struct Edge {
    int u, v, l;
    ll a;
    Edge(int u = 0, int v = 0, int l = 0, ll a = 0) 
        : u(u), v(v), l(l), a(a) { }

    bool operator<(const Edge& o) const {
        if (l != o.l) return l < o.l;
        return a > o.a;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    HLDSegTree segTree(n);
    vector<Edge> edges(n - 1);
    for (auto& [u, v, l, a] : edges) {
        cin >> u >> v >> l >> a;
        segTree.addEdge(--u, --v);
    }
    segTree.build();
    for (int c, w, i = 0; i < q; i++) {
        cin >> c >> w;
        edges.emplace_back(i, --c, w, -1);
    }
    sort(edges.begin(), edges.end());
    vector<ll> res(q);
    for (auto& [u, v, l, a] : edges) {
        dbg(u, v, l, a);
        if (a == -1) { // query
            res[u] = segTree.query(0, v);
        }
        else { // update
            if (segTree.parent(u) == v)
                segTree.update(u, a);
            else
                segTree.update(v, a);
        }
    }
    for (auto x : res) cout << x << " ";
    cout << "\n";
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.ou", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        dbg(cs);
        cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}