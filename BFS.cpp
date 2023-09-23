// https://www.infoarena.ro/problema/bfs
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
const string problem("bfs");
ifstream fin(problem + ".in");
ofstream fout(problem + ".out");
using VI  = vector<int>;
using VVI = vector<VI>;
VVI g;
VI d;
queue<int> q;
int n, m, sef, x, y;
int main() {
    DAU
    fin >> n >> m >> sef;
    g = VVI(n + 1);
    for (int i = 1; i <= m; ++i) {
        fin >> x >> y;
        g[x].emplace_back(y);
    }
    d = VI(n + 1, 1e9);
    d[sef] = 0;
    q.emplace(sef);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (const int& y : g[x])
            if (d[y] > d[x] + 1)
                d[y] = d[x] + 1, q.emplace(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 1e9)
            d[i] = -1;
        fout << d[i] << ' ';
    }
    PLEC
}
