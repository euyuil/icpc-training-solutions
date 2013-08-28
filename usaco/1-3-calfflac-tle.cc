/*
ID: 31415926
LANG: C++
TASK: calfflac
*/

#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void dump_array(T a, T b)
{
    for ( ; a != b; ++a)
        cerr << *a << ' ';
    cerr << endl;
}

void longest_palindrome(const string &str, int &begin, int &end)
{
    string arr(str.size() * 2 + 1, ' ');
    for (int i = 0; i < arr.size(); ++i)
        if (i & 1) arr[i] = str[i >> 1];
        else arr[i] = ' ';
    arr[0] = 1; arr[arr.size() - 1] = 2;

    vector<int> p(arr.size(), 0);
    for (int i = 1; i < arr.size() - 1; ++i)
    {
        int right_most = 0, the_central = 0, minimum_j = 0;
        if (right_most >= i)
            minimum_j = p[2 * the_central - i];
        for (int j = minimum_j; ; ++j)
        {
            int l = i - j, r = i + j;
            if (arr[l] != arr[r])
            {
                if (r > right_most)
                {
                    right_most = r;
                    the_central = i;
                }
                p[i] = j - 1;
                break;
            }
        }
    }

    int largest = -1;

    for (int i = 0; i < p.size(); ++i)
    {
        int j = i / 2, b, e;
        if (i & 1)
        {
            int x = p[i] / 2;
            b = j - x, e = j + x + 1;
        }
        else
        {
            int x = (p[i] + 1) / 2;
            b = j - x, e = j + x;
        }
        if (largest < e - b)
        {
            largest = e - b;
            begin = b; end = e;
            cerr << i << ' ' << b << ' ' << e << endl;
        }
    }

    cerr << ' ';
    dump_array(arr.begin(), arr.end());
    dump_array(p.begin(), p.end());
}

int main()
{
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);

    string original, lowercased, processed, buf;
    vector<int> processed_to_original;

    while (getline(cin, buf))
    {
        original += buf;
        original += '\n';
    }

    lowercased.resize(original.size());

    transform(original.begin(), original.end(),
              lowercased.begin(), static_cast<int (*)(int)>(tolower));

    for (int i = 0; i < lowercased.size(); ++i)
    {
        if (islower(lowercased[i]))
        {
            processed.push_back(lowercased[i]);
            processed_to_original.push_back(i);
        }
    }

    int begin, end, actual_length, displayed_length;
    longest_palindrome(processed, begin, end);
    actual_length = end - begin;
    begin = processed_to_original[begin];
    end = processed_to_original[end - 1] + 1;
    displayed_length = end - begin;

    cout << actual_length << endl;
    cout << original.substr(begin, displayed_length) << endl;

    return EXIT_SUCCESS;
}
