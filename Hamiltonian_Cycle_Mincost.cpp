// https://www.infoarena.ro/problema/hamilton
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define DAU  std::ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
using VI  = vector<int>;
using VVI = vector<VI>;
ifstream fin("hamilton.in");
ofstream fout("hamilton.out");
const int Inf = 1e7;
int n, m, cmin = Inf, x, y, cost;
VVI G, w, c;
int main()
{
    DAU
	fin >> n >> m;
	G = VVI(n);
	w = VVI(n, VI(n, Inf));
	for (int i = 1; i <= m; ++i)
	{
		fin >> x >> y >> cost;
		G[x].push_back(y);
		w[x][y] = cost;
	}
	c = VVI(1 << n, VI(n, Inf));
	c[1][0] = 0;
	for (int i = 1; i < (1 << n); ++i)
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				for (int k = 0; k < n; ++k)
					if (!(i & (1 << k)))
						c[i ^ (1 << k)][k] = min(c[i ^ (1 << k)][k], c[i][j] + w[j][k]);
	for (int j = 1; j < n; ++j)
		cmin = min(cmin, c[(1 << n) - 1][j] + w[j][0]);
    if (cmin == Inf)
        fout << "Nu exista solutie";
	else fout << cmin;
    PLEC
}
