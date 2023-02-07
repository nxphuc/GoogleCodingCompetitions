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

int findMin(vector<int> pts, vector<ii> segs) {
    sort(pts.begin(), pts.end());
    sort(segs.begin(), segs.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    ll sumLeft = 0, sumRight = 0;
    int cntLeft = 0, cntRight = segs.size();
    int cntIn = 0;
    int cur = -INF - 1;
    priority_queue<int, vector<int>, greater<int>> pqIn;
    for (auto seg: segs)
        sumRight += seg.first;

    int i = 0;
    ll minDist = 2LL * INF * segs.size();
    int minPos;
    for (auto p : pts) {
        while (!pqIn.empty() && pqIn.top() < p) {
            cntLeft++;
            sumLeft += pqIn.top();
            pqIn.pop();
        }
        while (i < segs.size() && segs[i].first <= p) {
            cntIn++;
            pqIn.emplace(segs[i].second);
            cntRight--;
            sumRight -= segs[i].first;
            ++i;
        }

        if (minDist > 1LL * cntLeft * p - sumLeft + sumRight - 1LL * cntRight * p) {
            minDist = 1LL * cntLeft * p - sumLeft + sumRight - 1LL * cntRight * p;
            minPos = p;
        }
        cur = p;
    }
    return minPos;
}

void solve() {
    int n;
    cin >> n;
    vector<int> xs, ys;
    vector<ii> segX, segY;
    for (int x1, y1, x2, y2, i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        xs.emplace_back(x1);
        xs.emplace_back(x2);
        segX.emplace_back(x1, x2);
        ys.emplace_back(y1);
        ys.emplace_back(y2);
        segY.emplace_back(y1, y2);
    }
    cout << findMin(xs, segX) << " " << findMin(ys, segY) << "\n";
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
        cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}