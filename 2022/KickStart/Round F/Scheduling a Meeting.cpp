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

template<typename T>
class FenwickTree {
public:
    vector<T> fen;
    int n;

    FenwickTree(int n) : n(n) {
        fen.resize(n + 1);
    }

    void modify(int pos, T val) {
        while (pos <= n) {
            fen[pos] += val;
            pos += pos & -pos;
        }
    }

    void modify(int l, int r, T val) {
        this->modify(l, val);
        this->modify(r + 1, -val);
        this->modify(l, val * (l - 1));
        this->modify(r + 1, -val * r);
    }

    T get(int pos) {
        T res{};
        while (pos > 0) {
            res += fen[pos];
            pos -= pos & -pos;
        }
        return res;
    }

    T get(int l, int r) {
        return this->get(r) - this->get(l - 1);
    }
};


int solve() {
    int n, k, x, d, m;
    cin >> n >> k >> x >> d >> m;
    vector<ii> startTime, endTime;
    for (int p, l, r, i = 0; i < m; i++) {
        cin >> p >> l >> r;
        startTime.emplace_back(l, p);
        endTime.emplace_back(r, p);
    }
    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());
    vector<int> cnt(n + 1, 0);
    FenwickTree<int> ftCount(MAX), ftSum(MAX);
    ftCount.modify(1, n);
    ftSum.modify(1, 0);
    cnt[0] = n;
    int startIdx = 0, endIdx = 0;
    int res = m;
    for (int i = 0; i + x <= d; i++) {
        while (startIdx < startTime.size() && startTime[startIdx].first < i + x) {
            int id = startTime[startIdx].second;
            ftCount.modify(cnt[id] + 1, -1);
            ftSum.modify(cnt[id] + 1, -cnt[id]);
            ++cnt[id];
            ftCount.modify(cnt[id] + 1, 1);
            ftSum.modify(cnt[id] + 1, cnt[id]);
            ++startIdx;
        }
        while (endIdx < endTime.size() && endTime[endIdx].first <= i) {
            int id = endTime[endIdx].second;
            ftCount.modify(cnt[id] + 1, -1);
            ftSum.modify(cnt[id] + 1, -cnt[id]);
            --cnt[id];
            ftCount.modify(cnt[id] + 1, 1);
            ftSum.modify(cnt[id] + 1, cnt[id]);
            ++endIdx;
        }
        int lo = 0, hi = m + 1;
        int mi, pos = hi;
        while (lo <= hi) {
            mi = (lo + hi) / 2;
            if (ftCount.get(mi + 1) >= k) {
                pos = mi;
                hi = mi - 1;
            }
            else
                lo = mi + 1;
        }
        int temoCount = ftCount.get(pos + 1);
        int tempSum = ftSum.get(pos + 1);
        if (temoCount > k)
            tempSum -= (temoCount - k) * pos;
        res = min(res, tempSum);
    }
    return res;
}

int main() {
#ifdef LOCAL_JUDGE
    // freopen("test.in", "rt", stdin);
    freopen("ts1_input.txt", "rt", stdin);
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