// https://www.infoarena.ro/problema/scmax
// Moca Andrei - 100p

#include <bits/stdc++.h>
using namespace std;
void DAU(const string &task = "") {
    if (!task.empty())
        freopen((task + ".in").c_str(), "r", stdin),
        freopen((task + ".out").c_str(), "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void PLEC() {
    exit(0);
}
const int N(1e5 + 5);
int n, v[N], sclm[N], t[N], st, dr, mid, curr, k, last;
inline void Afis(const int& pos) {
    if (!pos)
        return;
    Afis(t[pos]);
    cout << v[pos] << ' ';
}
signed main() {
    DAU("scmax");
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        st = 1, dr = k, curr = k + 1;
        while (st <= dr) {
            mid = (st + dr) / 2;
            if (v[sclm[mid]] >= v[i])
                curr = mid, dr = mid - 1;
            else st = mid + 1;
        }
        if (curr == k + 1)
            ++k, last = i;
        sclm[curr] = i;
        t[i] = sclm[curr - 1];
    }
    cout << k << '\n';
    Afis(last);
    PLEC();
}
