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
const int MOD = 2e9 + 11;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
map<pair<ll, ll>, ll> cache;

inline int getBalance(char ch) {
    return ch == '(' ? 1 : (ch == ')' ? -1 : 0);
}

ll merge(ll a, ll b, char op) {
    if (op == '+')
        return (a + b) % MOD;
    if (op == '*')
        return (a * b) % MOD;
    if (cache.find({a, b}) == cache.end())
        cache[{a, b}] = rng() % MOD;
    return cache[{a, b}];
}

ll eval(int l, int r) {
    if (s[l] == '(') {
        int balance = 1;
        int i = l + 1;
        while (balance > 0) balance += getBalance(s[i++]);
        ll lft = eval(l + 1, i - 2);
        if (i >= r) return lft;

        ll rht = eval(i + 1, r);
        return merge(lft, rht, s[i]);
    }
    ll lft = 0;
    while (l <= r && isdigit(s[l])) {
        lft = (lft * 10 + s[l] - '0') % MOD;
        l++;
    }
    if (l > r) return lft;
    ll rht = eval(l + 1, r);
    return merge(lft, rht, s[l]);
}

void solve() {
    cache.clear();
    int n;
    cin >> n;
    map<ll, int> mem;
    for (int i = 0; i < n; i++) {
        cin >> s;
        dbg(s);
        ll val = eval(0, s.length() - 1);
        if (mem.count(val) == 0)
            mem[val] = mem.size() + 1;
        cout << mem[val] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.ou", "wt", stdout);
    freopen("test.err", "wt", stderr);
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