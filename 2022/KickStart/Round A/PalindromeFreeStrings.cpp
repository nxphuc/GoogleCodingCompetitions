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

const int MAX = 1e5 + 10;
const int MASK = 1 << 6;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

int dp[MAX][MASK];

int isPalin(const string& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int isValid(int mask, int len) {
    if (len < 5) return true;
    string s = bitset<6>(mask).to_string();
    if (isPalin(s.substr(1, 5))) return false;
    if (len >= 6 && isPalin(s)) return false;
    return true;
}

void solve() {
    int n, newMask;
    string s;
    cin >> n >> s;

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    char ch;
    for (int i = 1; i <= n; i++) {
        for (int msk = 0; msk < MASK; msk++) {
            if (!dp[i-1][msk]) continue;
            
            if (s[i - 1] != '?') {
                newMask = ((msk << 1) | (s[i - 1] - '0')) & (MASK - 1);
                if (isValid(newMask, i))
                    dp[i][newMask] = 1;
            }
            else {
                for (int j = 0; j < 2; j++) {
                    newMask = ((msk << 1) | j) & (MASK - 1);
                    if (isValid(newMask, i))
                        dp[i][newMask] = 1;
                }
            }
        }
    }
    for (int msk = 0; msk < MASK; msk++)
        if (dp[n][msk]) {
            cout << "POSSIBLE\n";
            return;
        }
    cout << "IMPOSSIBLE\n";
    return;
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.ou", "wt", stdout);
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
