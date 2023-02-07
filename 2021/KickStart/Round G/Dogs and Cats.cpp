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

string solve() {
    int n, d;
    ll c, m;
    cin >> n >> d >> c >> m;
    string s;
    cin >> s;
    int nDogs = count(s.begin(), s.end(), 'D');
    for (char ch : s) {
        if (nDogs == 0) break;
        if (ch == 'D') {
            if (--d < 0)
                return "NO";
            nDogs--;
            c += m;
        }
        else if (--c < 0)
            return "NO";
    }
    return nDogs == 0 ? "YES" : "NO";
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