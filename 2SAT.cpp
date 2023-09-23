// https://www.infoarena.ro/problema/2sat
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define EXIT fin.close(); fout.close(); exit(0);
using namespace std;
const string task("2sat");
ifstream fin(task + ".in");
ofstream fout(task + ".out");
using VB  = vector<bool>;
using VI  = vector<int>;
using VVI = vector<VI>;
int n, m, x, y, ox, oy;
VVI g, gt;
VB vis, res;
stack<int> topo;
inline void Modif(int& x) {
    if (x < 0)
        x = -x + n;
}
inline int Opus(const int& x) {
    if (x <= n)
        return x + n;
    return x - n;
}
inline void DFS1(const int& x) {
    vis[x] = true;
    for (const int& y : g[x])
        if (!vis[y])
            DFS1(y);
    topo.emplace(x);
}
inline void DFS2(const int& x) {
    if (res[x]) {
        fout << -1;
        EXIT
    }
    vis[x] = res[Opus(x)] = true;
    for (const int& y : gt[x])
        if (!vis[y])
            DFS2(y);
}
int main() {
    fin >> n >> m;
    g = gt = VVI(2 * n + 1);
    while (m--) {
        fin >> x >> y;
        Modif(x), ox = Opus(x);
        Modif(y), oy = Opus(y);
        g[ox].emplace_back(y);
        g[oy].emplace_back(x);
        gt[y].emplace_back(ox);
        gt[x].emplace_back(oy);
    }
    vis = res = VB(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i)
        if (!vis[i])
            DFS1(i);
    fill(vis.begin(), vis.end(), false);
    while (!topo.empty()) {
        x = topo.top();
        topo.pop();
        if (!vis[x] && !vis[Opus(x)])
            DFS2(x);
    }
    for (int i = 1; i <= n; ++i)
        fout << res[i] << ' ';
    EXIT
}
