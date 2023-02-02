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
    string s;
    cin >> s;
    int rm = 0;
    for (char ch : s)
        rm += ch - '0';

    rm %= 9;
    if (rm) rm = 9 - rm;
    int pos = s.length();
    for (int i = s.length() - 1; i >= 0; i--)
        if (s[i] - '0' > rm && (i > 0 || rm > 0))
            pos = i;

    s.insert(pos, 1, char(rm + '0'));
    cout << s << "\n";
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