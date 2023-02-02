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
const double INF = 1e15;
const double PI = acos(-1.0);
const double EPS = 1e-9;

int cmp(double x, double y) {
    return (x < y - EPS) ? -1 : (x > y + EPS);
}

// 2d point and vector
struct Point {
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    int cmp(const Point& q) const {
        if (x != q.x) return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }

    #define op(x) bool operator x (const Point& q) const { return cmp(q) x 0; }
    op(>) op(<) op(==) op(>=) op(<=) op(!=)
    #undef op

    Point operator+(const Point& q) const {
        return Point(x + q.x, y + q.y);
    }

    Point operator-(const Point& q) const {
        return Point(x - q.x, y - q.y);
    }

    Point operator*(double k) const {
        return Point(x*k, y*k);
    }

    Point operator/(double k) const {
        return Point(x/k, y/k);
    }

    // dot product
    double dot(const Point& q) const {
        return x*q.x + y*q.y;
    }

    // cross product
    double cross(const Point& q) const {
        return x*q.y - y*q.x; 
    }

    double norm() {
        return x * x + y * y;
    }

    double len() {
        return sqrt(norm());
    }

    Point rotate(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x*sina + y*cosa);
    }
};

istream& operator >> (istream& is, Point& p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream& os, Point& p) {
    return os << p.x << ' ' << p.y;
}

// counter-clockwise
int ccw(Point a, Point b, Point c) {
    return cmp((b - a).cross(c - a), 0);
}

double area(Point a, Point b, Point c) {
    return fabs((b-a).cross(c-a)) / 2;
}

double solve() {
    double res = INF;

    int n;
    cin >> n;

    vector<Point> pts(n);
    Point p;
    for (int i = 0; i < n; i++)
        cin >> pts[i];
    cin >> p;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ccw(pts[i], pts[j], p) == 0) {
                if ((pts[i] - p).len() + (pts[j] - p).len() > (pts[i] - pts[j]).len())
                    continue;
                double minCCW = INF, minCW = INF;
                for (int temp, k = 0; k < n; k++) {
                    temp = ccw(pts[i], pts[j], pts[k]);
                    if (temp == 1)
                        minCCW = min(minCCW, (pts[i] - pts[k]).len() + (pts[j] - pts[k]).len());
                    if (temp == -1)
                        minCW = min(minCW, (pts[i] - pts[k]).len() + (pts[j] - pts[k]).len());;
                }
                if (minCCW - INF < EPS && minCW - INF < EPS)
                    res = min(res, minCCW + minCW);
            }
            else {
                for (int k = 0; k < n; k++) {
                    if (ccw(pts[i], pts[j], pts[k]) == 0) continue;
                    if (ccw(p, pts[i], pts[k]) == 0) continue;
                    if (ccw(p, pts[j], pts[k]) == 0) continue;
                    double ijp = area(p, pts[i], pts[j]);
                    double ikp = area(p, pts[i], pts[k]);
                    double jkp = area(p, pts[j], pts[k]);
                    if (abs(area(pts[i], pts[j], pts[k]) - (ijp + ikp + jkp)) <= EPS) {
                        res = min(res, (pts[i] - pts[j]).len() + (pts[j] - pts[k]).len() + (pts[k] - pts[i]).len());
                    }
                }
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
        double res = solve();
        cout << "Case #" << cs << ": ";
        if (!cmp(res, INF))
            cout << "IMPOSSIBLE\n";
        else
            cout << fixed << setprecision(10) << res << "\n";
    }

    return 0;
}