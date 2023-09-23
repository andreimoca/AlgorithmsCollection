// https://www.infoarena.ro/problema/trie
// Moca Andrei - 100p

#include <bits/stdc++.h>

#define GARDA fin.close(); fout.close(); exit(0);

using namespace std;

string const& task("trie");
ifstream fin(task + ".in");
ofstream fout(task + ".out");

int const SIGMA(26);

class Trie {
private:

    int cntsons, freq;
    Trie *sons[SIGMA];

    inline void Insert(string const& s, int const& pos = 0) {
        int x = s[pos] - 'a';
        if (!sons[x]) {
            ++cntsons;
            sons[x] = new Trie;
        }
        if (pos == static_cast<int>(s.size()) - 1)
            ++sons[x] -> freq;
        else sons[x] -> Insert(s, pos + 1);
    }

    inline void Erase(string const& s, int const& pos = 0) {
        int x = s[pos] - 'a';
        if (pos == static_cast<int>(s.size()) - 1)
            --sons[x] -> freq;
        else sons[x] -> Erase(s, pos + 1);
        if (sons[x] -> cntsons == 0 && sons[x] -> freq == 0) {
            delete sons[x];
            sons[x] = 0;
            --cntsons;
        }
    }

    inline int Count(string const& s, int const& pos = 0) {
        int x = s[pos] - 'a';
        if (!sons[x])
            return 0;
        if (pos == static_cast<int>(s.size()) - 1)
            return sons[x] -> freq;
        return sons[x] -> Count(s, pos + 1);
    }

    inline int LP(string const& s, int const& pos = 0) {
        int x = s[pos] - 'a';
        if (sons[x] && pos < static_cast<int>(s.size()))
            return sons[x] -> LP(s, pos + 1);
        return pos;
    }

public:

    Trie() : cntsons(0), freq(0) {
        memset(sons, 0, sizeof(sons));
    }
    inline void Compute(int const& op, string const& s) {
        if (op == 0) Insert(s);
        if (op == 1) Erase(s);
        if (op == 2) fout << Count(s) << '\n';
        if (op == 3) fout << LP(s) << '\n';
    }
};

signed main() {

    Trie *T = new Trie;
    int op;
    string s;
    while (fin >> op >> s)
        T -> Compute(op, s);

	GARDA
}
