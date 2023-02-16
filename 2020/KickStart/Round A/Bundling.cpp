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
#define each(a, x) for (auto &a : x)

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

struct Node {
    int child[26];
    int cnt;

    Node() {
        memset(child, -1, sizeof child);
        cnt = 0;
    }
};

struct Trie {
    vector<Node> nodes;
    Trie() {
        nodes.emplace_back();
    }

    void add(string s) {
        int id, cur = 0;
        for (char ch : s) {
            id = ch - 'A';
            if (nodes[cur].child[id] == -1) {
                nodes[cur].child[id] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].child[id];
            nodes[cur].cnt++;
        }
    }

    ll solve(int k, int i = 0) {
        ll res = nodes[i].cnt / k;
        for (auto& child : nodes[i].child) {
            if (child != -1) {
                res += solve(k, child);
            }
        }
        return res;
    }
};


void solve() {
    Trie trie;
    int n, k;
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie.add(s);
    }
    cout << trie.solve(k) << "\n";
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