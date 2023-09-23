// https://www.infoarena.ro/problema/maxflow
// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;

string const& task("maxflow");
ifstream fin(task + ".in");
ofstream fout(task + ".out");

int const N(1e3 + 5), INF(2e9);

int n, m, cap[N][N], dad[N];
vector<int> g[N];
bitset<N> viz;
queue<int> q;

inline bool BF(int const& S = 1, int const& D = n) {
    viz.reset();
    viz[S] = 1;
    q.emplace(S);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == D)
            continue;
        for (int const& y : g[x]) {
            if (viz[y] || cap[x][y] < 1)
                continue;
            viz[y] = 1;
            dad[y] = x;
            q.emplace(y);
        }
    }
    return viz[D];
}

inline int MaxFlow(int const& S = 1, int const& D = n) {
    int maxf = 0;
    while (BF()) {
        for (int const& tata : g[D]) {
            if (!viz[tata] || cap[tata][D] < 1)
                continue;
            dad[D] = tata;
            int curr = INF;
            for (int x = D; x != S; x = dad[x])
                curr = min(curr, cap[dad[x]][x]);
            if (curr < 1)
                continue;
            maxf += curr;
            for (int x = D; x != S; x = dad[x]) {
                cap[dad[x]][x] -= curr;
                cap[x][dad[x]] += curr;
            }
        }
    }
    return maxf;
}

signed main() {

    fin >> n >> m;
    while (m--) {
        int x, y, w;
        fin >> x >> y >> w;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        cap[x][y] = w;
    }
    fout << MaxFlow();

    return 0;
}
