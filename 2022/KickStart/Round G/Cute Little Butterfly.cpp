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
const ll INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-6;

/**
 *  Basic Segment Tree - Template
 *
 *  Tested:
 *  - https://codeforces.com/contest/61/problem/E
 *  - https://codeforces.com/contest/380/problem/C
 *  - https://codeforces.com/contest/474/problem/F
 *  - All Segment Tree problems in course Big-O Competitive Programming - Level 3
 */

template<
    class T,                      // data type
    T (*op) (const T&, const T&), // operator to combine 2 child nodes
    T (*e) ()                     // identity element
>
class SegmentTree{
private:
    vector<T> seg;
    int n, log, size;

    void update(int id, int l, int r, int p, T v) {
        if (l == r) {
            seg[id] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (m >= p)
            update(2 * id + 1, l, m, p, v);
        else
            update(2 * id + 2, m + 1, r, p, v);
        seg[id] = op(seg[2 * id + 1], seg[2 * id + 2]);
    }

    T query(int id, int l, int r, int u, int v) {
        if (v < l || u > r)
            return e();
        if (u <= l && r <= v)
            return seg[id];
        int m = (l + r) >> 1;
        return op(query(2 * id + 1, l, m, u, v), query(2 * id + 2, m + 1, r, u, v));
    }

    void build(const vector<T>& v, int id, int l, int r) {
        if (l == r) {
            seg[id] = v[l];
            return;
        }
        int m = (l + r) >> 1;
        build(v, 2 * id + 1, l, m);
        build(v, 2 * id + 2, m + 1, r);
        seg[id] = op(seg[2 * id + 1], seg[2 * id + 2]);
    };
public:
    explicit SegmentTree(int n = 0) : SegmentTree(vector<T>(n, e())) {}

    explicit SegmentTree(const vector<T>& v) : n(v.size()) {
        log = ceil(log2(n));
        size = 1 << log;
        seg = vector<T>(2 * size);
        build(v, 0, 0, n - 1);
    }

    void update(int pos, T val) {
        update(0, 0, n - 1, pos, val);
    }

    T query(int from, int to) {
        return query(0, 0, n - 1, from, to);
    }
};

struct Ops {
    using T = ll;
    inline static T op(const T& a, const T& b) {
        return max(a, b);
    }

    inline static T e() { return -INF; }
};

using SegTree = SegmentTree<Ops::T, Ops::op, Ops::e>;

ll solve() {
    int n, e;
    cin >> n >> e;
    vi xCoord;
    map<int, vector<ii>> yMap;
    for (int x, y, c, i = 0; i < n; i++) {
        cin >> x >> y >> c;
        xCoord.emplace_back(x);
        yMap[-y].emplace_back(x, c);
    }
    xCoord.emplace_back(-1e9);
    xCoord.emplace_back(1e9 + 10);
    sort(xCoord.begin(), xCoord.end());
    xCoord.erase(unique(xCoord.begin(), xCoord.end()), xCoord.end());
    int maxX = xCoord.size() + 1;
    for (auto& kvp : yMap) {
        auto& vii = kvp.second;
        for (auto& f : vii) {
            f.first = lower_bound(xCoord.begin(), xCoord.end(), f.first) - xCoord.begin();
        }
        vii.emplace_back(0, 0);
        vii.emplace_back(maxX, 0);
        sort(vii.begin(), vii.end());
    }
    SegTree dpLeft(vector<Ops::T>(maxX + 1, 0));
    SegTree dpRight(vector<Ops::T>(maxX + 1, -e));
    for (auto& kvp : yMap) {
        auto& curLine = kvp.second;
        for (int i = 1; i < curLine.size(); i++) {
            int prevX = curLine[i - 1].first, curX = curLine[i].first, curC = curLine[i].second;
            auto val = dpLeft.query(prevX, curX) + curC;
            dpLeft.update(curX, val);
        }
        for (int i = curLine.size() - 2; i >= 0; i--) {
            int prevX = curLine[i + 1].first, curX = curLine[i].first, curC = curLine[i].second;
            auto val = dpRight.query(curX, prevX) + curC;
            dpRight.update(curX, val);
        }
        auto turnRight = max(dpLeft.query(0, maxX) - e, dpRight.query(maxX, maxX));
        auto turnLeft = max(dpRight.query(0, maxX) - e, dpLeft.query(0, 0));
        dpLeft.update(0, turnLeft);
        dpRight.update(maxX, turnRight);
    }
    return max(dpLeft.query(0, maxX), dpRight.query(0, maxX));
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