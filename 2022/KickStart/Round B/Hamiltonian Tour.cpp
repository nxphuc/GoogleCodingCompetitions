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

const int MAX = 410;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-6;

char path[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string dir = "ESWN";

void setPath(int x, int y) {
    x *= 2;
    y *= 2;
    for (int d = 0; d < 4; d++) {
        path[x][y] = dir[d];
        x += dx[d];
        y += dy[d];
    }
}

void mergePath(int ux, int uy, int vx, int vy) {
    if (ux == vx) {
        ux *= 2;
        if (uy > vy) swap(uy, vy);
        uy *= 2;
        vy *= 2;
        path[ux][uy + 1] = 'E';
        path[ux + 1][vy] = 'W';
    }
    else {
        uy *= 2;
        if (ux > vx) swap(ux, vx);
        ux *= 2;
        vx *= 2;
        path[ux + 1][uy + 1] = 'S';
        path[vx][uy] = 'N';
    }
}

void bfs(vector<string>& mat, int r, int c, int x, int y) {
    queue<ii> q;
    q.emplace(x, y);
    setPath(x, y);
    mat[x][y] = '@';
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();
        for (int vx, vy, d = 0; d < 4; d++) {
            vx = ux + dx[d];
            vy = uy + dy[d];
            if (0 > vx || vx >= r || 0 > vy || vy >= c || mat[vx][vy] != '*')
                continue;
            mat[vx][vy] = '@';
            setPath(vx, vy);
            mergePath(ux, uy, vx, vy);
            q.emplace(vx, vy);
        }
    }
}

bool isConnected(vector<string>& mat, int r, int c) {
    int first = true;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == '*') {
                if (first) {
                    bfs(mat, r, c, i, j);
                    first = false;
                }
                else return false;
            }
        }
    return true;
}

string trace() {
    string res = "";
    int u = 0, v = 0;
    int d;
    do {
        res += path[u][v];
        d = dir.find(path[u][v]);
        u += dx[d];
        v += dy[d];
    } while (u != 0 || v != 0);
    return res;
}

string solve() {
    int r, c;
    cin >> r >> c;
    vector<string> mat(r);
    for (string& row : mat) cin >> row;
    memset(path, ' ', sizeof path);
    if (!isConnected(mat, r, c))
        return "IMPOSSIBLE";
    return trace();
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