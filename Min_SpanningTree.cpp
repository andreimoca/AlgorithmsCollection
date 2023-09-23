// https://www.infoarena.ro/problema/apm
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");
class Edge {
public:
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
    friend ostream& operator << (ostream& os, const Edge& e) {
        os << e.x << ' ' << e.y;
        return os;
    }
    Edge(int a, int b, int c) :
        x(a), y(b), w(c) {}
    void tie(int& a, int& b, int& c) {
        a = x; b = y; c = w;
    }
private:
    int x, y, w;
};
vector<int> t, ind;
vector<Edge> ve;
inline int Find(int x)
{
    if (x == t[x])
        return x;
    return t[x] = Find(t[x]);
}

int n, m, x, y, w, rx, ry, cnt, res;
int main()
{
    DAU
    fin >> n >> m;
    t = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i)
        t[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> w;
        ve.emplace_back(x, y, w);
    }
    sort(ve.begin(), ve.end());
    for (size_t i = 0; i < ve.size() && cnt != n - 1; ++i)
    {
        ve[i].tie(x, y, w);
        rx = Find(x), ry = Find(y);
        if (rx != ry)
        {
            ++cnt;
            res += w;
            t[rx] = ry;
            ind.emplace_back(i);
        }
    }
    fout << res << '\n' << cnt << '\n';
    for (const int& i : ind)
        fout << ve[i] << '\n';
    PLEC
}
