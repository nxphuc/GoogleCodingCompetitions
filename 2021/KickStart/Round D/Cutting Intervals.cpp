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

auto solve() {
    map<ll, int> cnt;
    int n;
    ll c;
    cin >> n >> c;
    ll l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        cnt[l+1]++;
        cnt[r]--;
    }
    ll prev = 0;
    int tot = 0;
    priority_queue<pair<int, ll>> pq;
    for (auto kvp : cnt) {
        debug(kvp, tot);
        if (prev)
            pq.emplace(tot, kvp.first - prev);
        tot += kvp.second;
        prev = kvp.first;
    }
    ll res = n;
    while (c > 0 && !pq.empty()) {
        auto tmp = pq.top();
        debug(tmp, c);
        pq.pop();
        ll nCut = min(c, tmp.second);
        res += nCut * tmp.first;
        c -= nCut;
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