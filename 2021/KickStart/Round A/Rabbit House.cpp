#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

ll solve() {
    int r, c;

    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c, 0));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    priority_queue<iii> pq;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
            pq.push(make_pair(matrix[i][j], make_pair(i, j)));
        }
    }

    iii temp;
    int val, x, y, nx, ny;
    ll res = 0;
    while (!pq.empty()) {
        temp = pq.top();
        val = temp.first;
        x = temp.second.first;
        y = temp.second.second;
        pq.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (int d = 0; d < 4; d++) {
            nx = x + dx[d];
            ny = y + dy[d];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny]) {
                if (matrix[nx][ny] < matrix[x][y]) {
                    res += matrix[x][y] - 1 - matrix[nx][ny];
                    matrix[nx][ny] = matrix[x][y] - 1;
                }
                pq.push(make_pair(matrix[nx][ny], make_pair(nx, ny)));
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