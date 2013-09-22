/*
ID: 31415926
LANG: C++
TASK: preface
*/

#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

// n is from 0 to 9.
string toroman(int n, char ten, char five, char one)
{
    string ret;

    if (n <= 3)
        ret.resize(n, one);
    else if (n == 4)
        ret.resize(2, five), ret[0] = one;
    else if (n <= 8)
        ret.resize(n - 4, one), ret[0] = five;
    else if (n == 9)
        ret.resize(2, ten), ret[0] = one;

    return ret;
}

string toroman(int n)
{
    string ret;

    if (n >= 1000)
        ret += toroman(n / 1000, ' ', ' ', 'M'), n %= 1000;
    if (n >= 100)
        ret += toroman(n / 100, 'M', 'D', 'C'), n %= 100;
    if (n >= 10)
        ret += toroman(n / 10, 'C', 'L', 'X'), n %= 10;
    if (n >= 1)
        ret += toroman(n, 'X', 'V', 'I');

    return ret;
}

int main()
{
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    // test cases
    cerr << toroman(3) << endl;
    cerr << toroman(300) << endl;
    cerr << toroman(268) << endl;
    cerr << toroman(4) << endl;
    cerr << toroman(9) << endl;
    cerr << toroman(40) << endl;
    cerr << toroman(39) << endl;
    cerr << toroman(490) << endl;
    cerr << toroman(99) << endl;
    cerr << toroman(990) << endl;
    cerr << toroman(90) << endl;

    // do the business
    int n, stat[256];

    cin >> n;
    memset(stat, 0, sizeof(stat));

    for (int i = 1; i <= n; ++i)
    {
        string r = toroman(i);

        for (int j = 0; j < r.size(); ++j)
            ++stat[r[j]];
    }

    static const char rc[] = "IVXLCDM";

    for (const char *p = rc; *p; ++p)
        if (stat[*p]) cout << *p << ' ' << stat[*p] << endl;

    return EXIT_SUCCESS;
}
