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

const int MAX = 1e7 + 200;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LIMIT = 100'000'000'000'000;
const double PI = acos(-1.0);
const double EPS = 1e-6;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

ll solve() {
    ll n;
    cin >> n;
    int s = sqrt(n);
    vector<ll> smallers;
    ll greater;
    for (greater = s + 1; !isPrime(greater); ++greater) {}
    for (int x = s; smallers.size() < 2; --x) {
        if (isPrime(x))
            smallers.emplace_back(x);
    }
    greater *= smallers[0];
    if (greater <= n) return greater;
    return smallers[0] * smallers[1];
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