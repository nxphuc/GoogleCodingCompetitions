#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define each(a,x) for (auto &a : x)
#define inbound(x,n) (x >= 0 && x < n)

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

// min heap
template <class T>
using Heap = priority_queue<T, vector<T>, greater<T>>;

// ceil div
ll cdiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

// floor div
ll fdiv(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

template <class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T &a, const T &b) {
    return b > a ? a = b, 1 : 0;
}

#ifdef LOCAL_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n;
    string s;

    cin >> n >> s;
    map<int, set<int>> curList;
    vector<int> a(n);
    vector<int> prv(n), nxt(n), mark(n, false);
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    auto isValidPair = [&] (int i, int j) {
        return (inbound(i, n) && inbound(j, n) && (a[i] + 1) % 10 == a[j]);
    };

    for (int i = 0; i < n; i++) {
        prv[i] = i - 1;
        nxt[i] = i + 1;
        if (isValidPair(i, nxt[i]))
            curList[a[i]].insert(i);
    }

    auto replace = [&] (int i, int val) {
        int j = nxt[i];
        nxt[i] = nxt[j];
        if (inbound(nxt[j], n))
            prv[nxt[j]] = i;
        mark[j] = true;
        a[i] = val;
        // debug(prv[i], i);
        // if (inbound(prv[i], n))
            // debug(a[prv[i]], a[i]);
        if (isValidPair(i, nxt[i]))
            curList[a[i]].insert(i);
        if (isValidPair(prv[i], i) && !mark[prv[i]])
            curList[a[prv[i]]].insert(prv[i]);
    };


    bool flag = true;
    while (flag) {
        // debug(curList);
        flag = false;
        for (int i = 0; i < 10; i++) {
            for (auto p : curList[i]) {
                if (mark[p])
                    continue;
                if (!isValidPair(p, nxt[p]) || mark[nxt[p]]) continue;
                flag = true;
                replace(p, (a[p] + 2) % 10);
            }
            curList[i].clear();
        }
    }
    // debug(mark);
    for (int i = 0; i < n; i++)
        if (!mark[i])
            cout << a[i];
    cout << "\n";
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.ou", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        // debug(cs);
        cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}