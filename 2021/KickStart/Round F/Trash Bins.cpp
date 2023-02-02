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

ll solve() {
    int n;
    string s;
    
    cin >> n >> s;
    int last = -1;
    vi dist(n, INF);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            last = i;
        if (last != -1)
            dist[i] = min(dist[i], i - last);
    }
    last = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1')
            last = i;
        if (last != -1)
            dist[i] = min(dist[i], last - i);
    }
    ll tot = 0;
    for (int x : dist)
        tot += x;
    return tot;
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