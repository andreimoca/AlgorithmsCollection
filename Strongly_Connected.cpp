// https://www.infoarena.ro/problema/infasuratoare
// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;

string const& task("ctc");
ifstream fin(task + ".in");
ofstream fout(task + ".out");

int const N(1e5 + 5);

int n, m;
bitset<N> viz;
vector<vector<int>> g, gt, ctc;
stack<int> st;

inline void DFS(int const& x) {
    viz[x] = 1;
    for (int const& y : g[x])
        if (!viz[y])
            DFS(y);
    st.emplace(x);
}

inline void DFST(int const& x) {
    viz[x] = 1;
    ctc[ctc.size() - 1].emplace_back(x);
    for (int const& y : gt[x])
        if (!viz[y])
            DFST(y);
}

main() {

    fin >> n >> m;
    g.resize(n + 1);
    gt.resize(n + 1);
    while (m--) {
        int x, y;
        fin >> x >> y;
        g[x].emplace_back(y);
        gt[y].emplace_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if (!viz[i])
            DFS(i);
    viz.reset();
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        if (!viz[x]) {
            ctc.emplace_back();
            DFST(x);
        }
    }
    fout << ctc.size() << '\n';
    for (vector<int> const& comp : ctc) {
        for (int const& nod : comp)
            fout << nod << ' ';
        fout << '\n';
    }

    return 0;
}
