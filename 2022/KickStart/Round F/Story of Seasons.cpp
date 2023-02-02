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

struct Seed {
    int q, v;
    ll l;

    Seed(int q, ll l, int v) : q(q), l(l), v(v) {};
};

bool compare(const Seed& a, const Seed& b) {
    return a.l < b.l;
}

ll solve() {
    ll d, x;
    int n;
    cin >> d >> n >> x;

    vector<Seed> seeds;
    int q, v;
    ll l;

    for (int i = 0; i < n; i++) {
        cin >> q >> l >> v;
        if (l > d) continue;
        seeds.emplace_back(q, l, v);
    }
    sort(seeds.begin(), seeds.end(), compare);
    n = seeds.size();
    priority_queue<ii> pq;
    ll res = 0;
    for (int j = 0, i = 0; i < n; i = j) {
        while (j < n && seeds[j].l == seeds[i].l) {
            pq.emplace(seeds[j].v, seeds[j].q);
            j++;
        }
        ll cap = (j == n ? d : seeds[j].l) - seeds[i].l;
        cap *= x;
        while (cap > 0 && !pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if (temp.second > cap) {
                res += cap * temp.first;
                temp.second -= cap;
                pq.push(temp);
                cap = 0;
            }
            else {
                res += 1LL * temp.first * temp.second;
                cap -= temp.second;
            }
        }
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