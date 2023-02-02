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

string solve() {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    vector<vector<int>> pos(26);
    
    int n = s.length();
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        pos[s[i] - 'a'].push_back(i);
    }

    vector<pair<int, int>> a;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0)
            a.emplace_back(cnt[i], i);
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    if (a[0].first > n / 2)
        return "IMPOSSIBLE";
    int d = a[0].first;
    vector<int> c;
    for (int id = 0, i = 0; i < a.size(); i++) {
        for (int j = 0; j < pos[a[i].second].size(); j++)
            c.emplace_back(pos[a[i].second][j]);
    }
    string t = s;
    for (int i = 0; i < n; i++) {
        // cout << i << " " << c
        t[c[(i+d) % n]] = s[c[i]];
    }
    return t;
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