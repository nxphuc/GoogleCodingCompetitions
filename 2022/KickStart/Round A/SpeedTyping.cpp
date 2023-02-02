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

void solve() {
    string s, t;
    cin >> s >> t;
    int pos, lastmatch = -1;
    for (char c : s) {
        int pos = t.find(c, lastmatch + 1);
        if (pos == string::npos) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        lastmatch = pos;
    }
    cout << t.length() - s.length() << "\n";
    return;
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