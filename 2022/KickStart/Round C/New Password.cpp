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
    int n;
    string s;
    string specials = "#@*&";
    int hasDigit = 0, hasUpper = 0, hasLower = 0, hasSpecial = 0;
    cin >> n >> s;
    for (auto ch : s) {
        hasDigit |= isdigit(ch);
        hasUpper |= isupper(ch);
        hasLower |= islower(ch);
        hasSpecial |= specials.find(ch) != string::npos;
    }
    if (!hasDigit) s += "0";
    if (!hasUpper) s += "A";
    if (!hasLower) s += "a";
    if (!hasSpecial) s += "@";
    while (s.length() < 7) s += "A";
    return s;
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