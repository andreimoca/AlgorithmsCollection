// https://www.infoarena.ro/problema/dijkstra
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
using PII = pair<int, int>;
using VP  = vector<PII>;
using VVP = vector<VP>;
using VI  = vector<int>;
using VB  = vector<bool>;
int n, m, p, x, y, c;
VVP g;
VI d;
VB viz;
int main()
{
    DAU
    fin >> n >> m;
    g = VVP(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> c;
        g[x].emplace_back(y, c);
    }
    priority_queue<PII> q;
    d = VI(n + 1, 1e9);
    d[1] = 0;
    q.emplace(0, 1);
    viz = VB(n + 1);
    while (!q.empty())
    {
        x = q.top().second;
        q.pop();
        if (!viz[x])
        {
            for (const PII& P : g[x])
            {
                y = P.first;
                c = P.second;
                if (d[y] > d[x] + c)
                    d[y] = d[x] + c, q.emplace(-d[y], y);
            }
            viz[x] = true;
        }
    }
    for (int i = 2; i <= n; ++i)
        if (d[i] == 1e9)
            fout << "0 ";
        else fout << d[i] << ' ';
    PLEC
}
