// https://www.infoarena.ro/problema/arbint
// Moca Andrei - 100p

#include <fstream>
using namespace std;
ifstream fin("arbint.in");
ofstream fout("arbint.out");
int n, m, ai[400002], cer, a, b;
void update(int st, int dr, int node, int poz, int val)
{
    if (st == dr)
    {
        ai[node] = val;
        return;
    }
    int mij = (st + dr) / 2;
    if (poz <= mij)
        update(st, mij, node * 2, poz, val);
    else
        update(mij + 1, dr, node * 2 + 1, poz, val);
    ai[node] = max(ai[node * 2], ai[node * 2 + 1]);
}
int query(int st, int dr, int node, int a, int b)
{
    if (a <= st && b >= dr)
        return ai[node];
    int mij = (st + dr) / 2, r1 = -1, r2 = -1;
    if (a <= mij)
        r1 = query(st, mij, node * 2, a, b);
    if (b >= mij + 1)
        r2 = query(mij + 1, dr, node * 2 + 1, a, b);
    return max(r1, r2);
}
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        fin >> a;
        update(1, n, 1, i, a);
    }
    for (int i = 1; i <= m; i++)
    {
        fin >> cer;
        if (cer == 0)
        {
            fin >> a >> b;
            fout << query(1, n, 1, a, b) << '\n';
        }
        if (cer == 1)
        {
            fin >> a >> b;
            update(1, n, 1, a, b);
        }
    }
    fin.close();
    fout.close();
    return 0;
}
