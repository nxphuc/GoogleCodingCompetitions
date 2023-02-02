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

const int MAX = 3e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

int cntTree[4*MAX];
ll sumTree[4*MAX];

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        cntTree[id] += val;
        sumTree[id] += val * pos;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * id + 1, l, m, pos, val);
    else update(2 * id + 2, m+1, r, pos, val);
    cntTree[id] = cntTree[2 * id + 1] + cntTree[2 * id + 2];
    sumTree[id] = sumTree[2 * id + 1] + sumTree[2 * id + 2];
}

pair<int, ll> getSum(int id, int l, int r, int limit) {
    if (l == r) {
        int cnt = min(cntTree[id], limit);
        ll sum = 1LL * cnt * l;
        return mp(cnt, sum);
    }
    if (limit >= cntTree[id])
        return mp(cntTree[id], sumTree[id]);
    int m = (l + r) / 2;
    pair<int, ll> res = getSum(2 * id + 2, m + 1, r, limit);
    limit -= res.first;
    if (limit > 0) {
        pair<int, ll> temp = getSum(2 * id + 1, l, m, limit);
        res.first += temp.first;
        res.second += temp.second;
    }
    return res;
}

ll solve() {
    int n, d, k;
    cin >> d >> n >> k;
    vector<ii> events;
    for (int s, e, h, i = 0; i < n; i++) {
        cin >> h >> s >> e;
        events.ep(s, h);
        events.ep(e+1, -h);
    }
    memset(cntTree, 0, sizeof(cntTree));
    memset(sumTree, 0, sizeof(sumTree));
    sort(events.begin(), events.end());
    int j = 0;
    ll res = 0;
    for (int i = 1; i <= d; i++) {
        while (j < events.size() && events[j].first <= i) {
            update(0, 1, MAX - 1, abs(events[j].second), events[j].second > 0 ? 1 : -1);
            j++;
        }
        pair<int, ll> temp = getSum(0, 1, MAX-1, k);
        res = max(res, temp.second);
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