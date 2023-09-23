// https://www.infoarena.ro/problema/bellmanford
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
const string problem("bellmanford");
ifstream fin(problem + ".in");
ofstream fout(problem + ".out");
using VI  = vector<int>;
using PII = pair<int, int>;
using VP  = vector<PII>;
using VVP = vector<VP>;
VVP g;
VI d, vis;
queue<int> q;
int n, m, x, y, w;
int main() {
    DAU
    fin >> n >> m;
    g = VVP(n + 1);
    for (int i = 1; i <= m; ++i) {
        fin >> x >> y >> w;
        g[x].emplace_back(y, w);
    }
    d = VI(n + 1, 1e9);
    vis = VI(n + 1);
    d[1] = 0;
    q.emplace(1);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (vis[x]++ == n) {
            fout << "Ciclu negativ!";
            PLEC
        }
        for (const PII& P : g[x]) {
            tie(y, w) = P;
            if (d[y] > d[x] + w)
                d[y] = d[x] + w, q.emplace(y);
        }
    }
    for (int i = 2; i <= n; ++i)
        fout << d[i] << ' ';
    PLEC
}
