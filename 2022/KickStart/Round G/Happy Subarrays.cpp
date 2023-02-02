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
    cin >> n;
    vector<int> a(n + 2);
    vector<ll> s(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        s[i] = s[i - 1] + a[i];
    }

    ll res = 0;
    stack<int> st;
    a[n + 1] = -INF;
    st.emplace(0);

    int j;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[i] < a[st.top()]) {
            j = st.top();
            st.pop();
            res += s[i - 1] - s[j] - 1LL * a[j] * (i - j - 1);
        }
        st.push(i);
    }
    while (!st.empty()) {
        j = st.top();
        st.pop();
        res += s[n] - s[j] - 1LL * a[j] * (n - j);
    }
    return res;
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
        cout << "Case #" << cs << ": " << solve() << "\n";
    }

    return 0;
}