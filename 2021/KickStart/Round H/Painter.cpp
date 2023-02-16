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

map<char, int> colorCode = {
    {'U', 0},
    {'R', 1},
    {'Y', 2},
    {'B', 4},
    {'O', 3},
    {'P', 5},
    {'G', 6},
    {'A', 7}
};

int solve() {
    int n;
    string s;
    int cur = 0;
    int res = 0;
    cin >> n >> s;
    for (char ch : s) {
        int color = colorCode[ch];
        int newColor = (color ^ cur) & color;
        res += __builtin_popcount(newColor);
        cur = color;
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