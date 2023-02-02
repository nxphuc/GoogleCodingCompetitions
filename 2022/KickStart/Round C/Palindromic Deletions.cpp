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

const int MAX = 402;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

template<int MOD>
struct ModInt {
    static const int mod = MOD;
    static const int UNDEFINED = -1;
    int v;

    explicit operator int() const { return v; }

    ModInt() : v(0) {}

    ModInt(int _v) {
        if (_v == UNDEFINED) v = _v;
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

modular f[MAX][MAX][MAX];
modular fact[MAX];
string s;

modular dp(int l, int r, int k) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (l > r) return 0;
    auto& res = f[l][r][k];
    if (res != modular::UNDEFINED) return res;
    res = 0;
    if (s[l - 1] == s[r - 1])
        res = dp(l + 1, r - 1, k - (l == r ? 1 : 2));
    res = res + dp(l, r - 1, k) + dp(l + 1, r, k) - dp(l + 1, r - 1, k);
    return res;
}

modular solve() {
    int n;
    cin >> n >> s;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                f[i][j][k] = modular::UNDEFINED;
    modular res = 0;
    for (int k = 0; k < n; k++) {
        auto temp = dp(1, n, k);
        res = res + fact[k] * fact[n - k] * temp;
    }
    return res * inv(fact[n]);
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.ou", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i - 1] * i;

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << solve() << "\n";
    }

    return 0;
}