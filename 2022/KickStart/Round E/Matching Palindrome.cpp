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

vector<int> manacher(string s) {
    int n = s.length();
    vector<int> p(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = i > r ? 0 : min(p[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        p[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return p;
}

string solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    string t(2*n + 1, '#');
    for (int i = 0; i < n; i++) {
        t[2 * i + 1] = s[i];
    }
    vector<int> p = manacher(t);
    int res = n;
    for (int i = p.size() - 1; i > 0; i--) {
        if (p[i] != p.size() - i - 1) continue;
        int preLen = i - p[i];
        if (preLen > 0 && p[preLen / 2] == preLen / 2)
            res = min(res, preLen / 2);
    }
    return s.substr(0, res);
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