// https://www.infoarena.ro/problema/infasuratoare
// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;

string const& task("infasuratoare");
ifstream fin(task + ".in");
ofstream fout(task + ".out");

const int N(12e4 + 5);

struct Point {
    double x, y;
};
Point v[N];
int st[N], first(1), n, k;

double Det(Point const& a, Point const& b, Point const& c) {
    return ((a.x * b.y + a.y * c.x + b.x * c.y) - (b.y * c.x + a.y * b.x + a.x * c.y));
}

struct cmp {
    bool operator () (Point const& a, Point const& b) const {
        return Det(v[1], a, b) > 0;
    }
};

signed main() {

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i].x >> v[i].y;
        if (v[i].y < v[first].y || (v[i].y == v[first].y && v[i].x < v[first].x))
            first = i;
    }
    swap(v[1], v[first]);
    sort(v + 2, v + n + 1, cmp());
    st[++k] = 1, st[++k] = 2;
    for (int i = 3; i <= n; ++i) {
        while (k > 1 && Det(v[st[k - 1]], v[st[k]], v[i]) <= 0)
            --k;
        st[++k] = i;
    }
    fout << k << '\n';
    fout << fixed << setprecision(6);
    for (int i = 1; i <= k; ++i)
        fout << v[st[i]].x << ' ' << v[st[i]].y << '\n';

    return 0;
}
