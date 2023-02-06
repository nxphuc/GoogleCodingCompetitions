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

#ifdef LOCAL_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void add(map<ll, ll>& problems, ll l, ll r) {
    if (l > r) return;
    problems.emplace(l, r);
}

void remove(map<ll, ll>& problems, map<ll, ll>::iterator it, ll x) {
    ll l = it->first;
    ll r = it->second;
    problems.erase(it);
    add(problems, l, x - 1);
    add(problems, x + 1, r);
}

void solve() {
    map<ll, ll> problems;
    int n, m;
    cin >> n >> m;
    ll x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        add(problems, x, y);
    }
    map<ll, ll>::iterator lft, rht;
    for (int i = 0; i < m; i++) {
        cin >> x;
        lft = problems.upper_bound(x);
        if (lft == problems.begin()) {
            cout << lft->first << " ";
            remove(problems, lft, lft->first);
            continue;
        }

        rht = lft--;

        if (lft->second >= x) {
            cout << x << " ";
            remove(problems, lft, x);
            continue;
        }

        if (rht == problems.end() || x - lft->second <= rht->first - x) {
            cout << lft->second << " ";
            remove(problems, lft, lft->second);
        }
        else {
            cout << rht->first << " ";
            remove(problems, rht, rht->first);
        }
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