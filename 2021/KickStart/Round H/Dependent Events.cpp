#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)

const int MAX = 2e5 + 10;
const int LOG = 19;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int BASE = 1e6;
const double PI = acos(-1.0);
const double EPS = 1e-6;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

// min heap
template <class T>
using Heap = priority_queue<T, vector<T>, greater<T>>;

// ceil div
ll cdiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

// floor div
ll fdiv(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T &a, const T &b) {
    return b > a ? a = b, 1 : 0;
}

#ifdef LOCAL_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template<int MOD>
struct ModInt {
    static const int mod = MOD;
    int v;

    explicit operator int() const { return v; }

    ModInt() : v(0) {}

    ModInt(int _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }

    ModInt(long long _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }

#define COMPAREOP(OP) bool constexpr operator OP(ModInt other) const { return v OP other.v; }
    COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

    ModInt& operator+=(const ModInt& other) { 
        if ((v += other.v) >= MOD) v -= MOD; 
        return *this;
    }

    ModInt& operator-=(const ModInt& other) { 
        if ((v -= other.v) < 0) v += MOD; 
        return *this;
    }

    ModInt& operator*=(const ModInt& other) {
        v = int((ll)v * other.v % MOD);
        return *this;
    }

    ModInt &operator/=(const ModInt &other) { return (*this) *= inv(other); }

    friend ModInt pow(ModInt a, ll p) {
        ModInt ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1)
                ans *= a;
        return ans;
    }

    friend ModInt inv(const ModInt& a) {
        assert(a.v != 0);
        return pow(a, MOD-2);
    }

    ModInt operator-() const { return ModInt(-v); }
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) {
        ModInt temp = *this;
        *this += 1;
        return temp;
    }
    ModInt operator--(int) {
        ModInt temp = *this;
        *this -= 1;
        return temp;
    }
    friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

    friend std::ostream& operator << (std::ostream& os, const ModInt& m) { return os << m.v; }
    friend std::istream& operator >> (std::istream& is, ModInt& m) { return is >> m.v; }
};

using modular = ModInt<MOD>;
using ProbPair = pair<modular, modular>;
/**
 * Lowest common ancestor - Template
 * 0-based index
 */

class LCA {
private:
    vector<int> tin, tout;
    vector<vector<int>> par, adj;
    int n, root, counter, lg;

    void dfs(int u, int p) {
        tin[u] = ++counter;

        par[u][0] = p;
        for (int v : adj[u])
            if (v != p)
                dfs(v, u);

        tout[u] = ++counter;
    }
public:
    LCA(int _n, const vector<vector<int>>& _adj, int _root = 0)
            : n(n), root(_root), adj(_adj) {
        lg = ceil(log2(n));
        tin.assign(n, 0);
        tout.assign(n, 0);
        par.assign(n, vector<int>(lg + 1, root));

        dfs(root, root);

        for (int k = 1; k <= lg; k++)
            for (int i = 0; i < n; i++)
                par[i][k] = par[par[i][k - 1]][k - 1];
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tin[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int k = lg; k >= 0; k--)
            if (!isAncestor(par[u][k], v))
                u = par[u][k];
        return par[u][0];
    }
};


int lv[MAX];
int par[LOG][MAX];
ProbPair probs[LOG][MAX];

int jump(int u, int k) {
    for (int i = 0; i < LOG; i++)
        if ((k >> i) & 1)
            u = par[i][u];
    return u;
}

int lca(int u, int v) {
    if (lv[u] < lv[v]) swap(u, v);
    u = jump(u, lv[u] - lv[v]);
    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }

    while (u != v) {
        u = par[0][u];
        v = par[0][v];
    }
    return u;
}

ProbPair combine(const ProbPair& a, const ProbPair& b) {
    return {
        a.F * b.F + (1 - a.F) * b.S,
        a.S * b.F + (1 - a.S) * b.S
    };
}

modular query(int u, int p, int isPOccur) {
    if (u == p) return isPOccur ? 1 : 0;

    vector<ProbPair> probList;
    int h = lv[u] - lv[p];
    for (int i = LOG - 1; i >= 0; i--) {
        if ((h >> i) & 1) {
            probList.ep(probs[i][u]);
            u = par[i][u];
        }
    }
    while (u != p) {
        probList.ep(probs[0][u]);
        u = par[0][u];
    }
    modular res = isPOccur ? probList.back().F : probList.back().S;
    probList.pop_back();
    reverse(all(probList));
    each(x, probList) {
        res = res * x.F + (1 - res) * x.S;
    }
    return res;
}

void solve() {
    int n, q;
    modular k;
    cin >> n >> q >> k;
    k /= BASE;

    lv[0] = 0;
    probs[0][0] = {k, 0};

    modular a, b;
    int p;
    for (int i = 1; i < n; i++) {
        cin >> p >> a >> b;
        --p;
        par[0][i] = p;
        probs[0][i] = { a / BASE, b / BASE};
        lv[i] = lv[p] + 1;
    }
    for (int k = 1; k < LOG; k++)
        for (int i = 0; i < n; i++) {
            par[k][i] = par[k - 1][par[k - 1][i]];
            probs[k][i] = combine(probs[k - 1][par[k - 1][i]], probs[k - 1][i]);
        }
    for (int u, v, i = 0; i < q; i++) {
        cin >> u >> v;
        --u, --v;
        p = lca(u, v);
        modular probP = query(p, 0, true) * k + query(p, 0, false) * (1 - k);
        modular res = probP * query(u, p, true) * query(v, p, true);
        res += (1 - probP) * query(u, p, false) * query(v, p, false);
        cout << res << " ";
    }
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