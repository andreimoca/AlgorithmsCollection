// https://www.infoarena.ro/problema/ciclueuler
// Moca Andrei - 100p

#include <bits/stdc++.h>

#define GARDA fin.close(); fout.close(); exit(0);

using namespace std;

string const& task("ciclueuler");
ifstream fin(task + ".in");
ofstream fout(task + ".out");

int const N(1e5 + 5), M(5e5 + 5);

int n, m, a[M], b[M], p[N];
bool used[M];
vector<int> euler, g[N];
stack<int> st;

inline void Euler(int const& start = 1) {
    st.emplace(start);
    while (!st.empty()) {
        int x = st.top(), baga = 0;

        while (p[x] < static_cast<int>(g[x].size())) {
            int e = g[x][p[x]++];
            if (used[e])
                continue;

            used[e] = true;
            baga = a[e];
            if (x == baga)
                baga = b[e];
            break;
        }

        if (baga)
            st.emplace(baga);
        else {
            st.pop();
            euler.emplace_back(x);
        }
    }
    euler.pop_back();
}

signed main() {

    fin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        fin >> a[i] >> b[i];
        g[a[i]].emplace_back(i);
        g[b[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; ++i)
        if (g[i].size() & 1) {
            fout << -1;
            GARDA
        }

    Euler();

    for (int const& x : euler)
        fout << x << ' ';


	GARDA
}
