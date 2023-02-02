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

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    int dist() const {
        return x*x + y*y;
    }

    bool operator<(const Point& o) const {
        return dist() < o.dist();
    }
};

inline int sqr(int x) { return x*x; }

ii solve() {
    int rh, rs, n, m;
    cin >> rs >> rh;
    cin >> n;
    vector<Point> red;
    Point p;
    for (int i = 0; i < n; i++) {
        cin >> p.x >> p.y;
        if (p.dist() <= sqr(rh + rs))
            red.push_back(p);
    }
    cin >> m;
    vector<Point> yel;
    for (int i = 0; i < m; i++) {
        cin >> p.x >> p.y;
        if (p.dist() <= sqr(rh + rs))
            yel.push_back(p);
    }
    sort(red.begin(), red.end());
    sort(yel.begin(), yel.end());

    if (red.size() == 0)
        return { 0, yel.size() };
    if (yel.size() == 0)
        return { red.size(), 0 };
    int scoreRed = 0, scoreYel = 0;
    for (auto p : red)
        if (p.dist() <= yel.begin()->dist())
            scoreRed++;
        else
            break;
    for (auto p : yel)
        if (p.dist() <= red.begin()->dist())
            scoreYel++;
        else
            break;
    return { scoreRed, scoreYel };
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
        auto res = solve();
        cout << res.first << " " << res.second << "\n";
    }

    return 0;
}