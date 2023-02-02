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

struct Ant {
    int pos, dir, id;
    Ant(int pos = 0, int dir = 0, int id = 0) : pos(pos), dir(dir), id(id) {}

    bool operator<(const Ant& other) const {
        return pos < other.pos;
    }
};

void solve() {
    int n, l;
    cin >> n >> l;
    vector<ii> events;
    vector<Ant> ants;
    for (int p, d, i = 0; i < n; ++i) {
        cin >> p >> d;
        events.emplace_back(d ? l - p : p, d);
        ants.emplace_back(p, d, i + 1);
    }
    sort(events.begin(), events.end());
    sort(ants.begin(), ants.end());
    vector<ii> res;
    for (int i = 0, l = 0, r = n - 1; i < n; ++i) {
        if (events[i].second == 0)
            res.emplace_back(events[i].first, ants[l++].id);
        else
            res.emplace_back(events[i].first, ants[r--].id);
    }
    sort(res.begin(), res.end());
    for (auto x : res)
        cout << " " << x.second;
    cout << "\n";
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
        cout << "Case #" << cs << ":";
        solve();
    }

    return 0;
}