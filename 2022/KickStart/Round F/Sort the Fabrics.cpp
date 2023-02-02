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

struct Fabric {
    string color;
    int d;
    int id;

    Fabric(string color, int d, int id) : color(color), d(d), id(id) {}

    bool operator==(const Fabric& other) const {
        return color == other.color && d == other.d && id == other.id;
    }
};

bool colorCompare(const Fabric& a, const Fabric& b) {
    if (a.color != b.color)
        return a.color < b.color;
    return a.id < b.id;
}

bool durabilityCompare(const Fabric& a, const Fabric& b) {
    if (a.d != b.d)
        return a.d < b.d;
    return a.id < b.id;
}

int solve() {
    int n;
    cin >> n;
    vector<Fabric> a, b;
    string s;
    int d, id;
    for (int i = 0; i < n; i++) {
        cin >> s >> d >> id;
        a.emplace_back(s, d, id);
        b.emplace_back(s, d, id);
    }
    sort(a.begin(), a.end(), colorCompare);
    sort(b.begin(), b.end(), durabilityCompare);
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += (a[i] == b[i]);
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