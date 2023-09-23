// https://www.infoarena.ro/problema/lgput
// Moca Andrei - 100p

#include <bits/stdc++.h>
#define DAU  ios_base::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
const string problem("lgput");
ifstream fin(problem + ".in");
ofstream fout(problem + ".out");
typedef long long i64;
const int MOD(2e9 - 27);
inline i64 Powlog(i64 a, i64 b) {
    i64 res(1);
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
i64 n, p;
int main() {
    DAU
    fin >> n >> p;
    fout << Powlog(n, p);
    PLEC
}
