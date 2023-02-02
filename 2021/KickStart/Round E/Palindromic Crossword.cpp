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

void solve() {
    int n, m;

    cin >> n >> m;
    vector<string> s(n);
    vector<vector<ii>> seg_row(n), seg_col(m);
    queue<ii> q;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.' && s[i][j] != '#')
                q.emplace(i, j);
        }
    }

    for (int prev, i = 0; i < n; i++) {
        prev = -1;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (prev != -1) {
                    seg_row[i].emplace_back(prev, j - 1);
                    prev = -1;
                }
            }
            else if (prev == -1) prev = j;
        }
        if (prev != -1) seg_row[i].emplace_back(prev, m - 1);
    }

    for (int prev, j = 0; j < m; j++) {
        prev = -1;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '#') {
                if (prev != -1) {
                    seg_col[j].emplace_back(prev, i - 1);
                    prev = -1;
                }
            }
            else if (prev == -1) prev = i;
        }
        if (prev != -1) seg_col[j].emplace_back(prev, n - 1);
    }

    int ops, pos, cnt = 0;
    ii cell;
    vector<ii>::iterator it;
    while (!q.empty()) {
        cell = q.front();
        q.pop();

        pos = upper_bound(seg_row[cell.first].begin(), seg_row[cell.first].end(), make_pair(cell.second, m)) - seg_row[cell.first].begin() - 1;
        ops = seg_row[cell.first][pos].second - (cell.second - seg_row[cell.first][pos].first);
        if (s[cell.first][ops] == '.') {
            cnt++;
            s[cell.first][ops] = s[cell.first][cell.second];
            q.emplace(cell.first, ops);
        }

        pos = upper_bound(seg_col[cell.second].begin(), seg_col[cell.second].end(), make_pair(cell.first, n)) - seg_col[cell.second].begin() - 1;
        ops = seg_col[cell.second][pos].second - (cell.first - seg_col[cell.second][pos].first);
        if (s[ops][cell.second] == '.') {
            cnt++;
            s[ops][cell.second] = s[cell.first][cell.second];
            q.emplace(ops, cell.second);
        }
    }

    cout << cnt << "\n";
    for (string x : s) cout << x << "\n";
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