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

int solve() {
    int n;
    cin >> n;
    map<int, set<int> > charPos;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> dp(n, vector<int>(m, INF));
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (charPos.find(b[i]) == charPos.end())
            charPos[b[i]] = set<int>();
        charPos[b[i]].insert(i);
        if (b[i] == a[0])
            dp[0][i] = 0;
    }
    int nextChar, leftPos, rightPos;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] >= INF) continue;
            nextChar = a[i + 1];
            auto& st = charPos[nextChar];
            auto it = st.lower_bound(j);
            if (it != st.end()) {
                rightPos = *it;
                dp[i + 1][rightPos] = min(dp[i + 1][rightPos], dp[i][j] + rightPos - j);
            }
            if (it != st.begin()) {
                leftPos = *(--it);
                dp[i + 1][leftPos] = min(dp[i + 1][leftPos], dp[i][j] + j - leftPos);
            }
        }
    }
    int res = INF;
    for (int i = 0; i < m; i++)
        res = min(res, dp[n - 1][i]);
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