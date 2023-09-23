// https://www.infoarena.ro/problema/biconex
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
using VI  = vector<int>;
using VVI = vector<VI>;
const string problem("biconex");
ifstream fin(problem + ".in");
ofstream fout(problem + ".out");
VI level, low;
VVI g, comp;
stack<int> st;
int nrc, nod;
inline void DFS(int x, int dad) {
    st.emplace(x);
    for (const int& y : g[x])
        if (!level[y]) {
            level[y] = low[y] = level[x] + 1;
            DFS(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] >= level[x])  {
                comp.emplace_back(vector<int>());
                while (nod != y) {
                    nod = st.top();
                    comp[nrc].emplace_back(nod);
                    st.pop();
                }
                comp[nrc].emplace_back(x);
                ++nrc;
            }
        }
        else if (y != dad)
            low[x] = min(low[x], level[y]);
}
int n, m, x, y;
int main() {
    DAU
    fin >> n >> m;
    g = VVI(n + 1);
    for (int i = 1; i <= m; ++i) {
        fin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    level = low = VI(n + 1);
    level[1] = low[1] = 1;
    DFS(1, 0);
    fout << nrc << '\n';
    for (int i = 0; i < nrc; ++i) {
        for (const int& x : comp[i])
            fout << x << ' ';
        fout << '\n';
    }
    PLEC
}
