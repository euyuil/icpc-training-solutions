/*
ID: 31415926
LANG: C++
TASK: calfflac
*/

#include <cstdio>
#include <vector>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 22345;

void longest_palindrome(const char *str, int size, int &begin, int &end)
{
    static char arr[N * 2 + 1];
    int arrsize = size * 2 + 1;

    for (int i = 0; i < arrsize; ++i)
        if (i & 1) arr[i] = str[i >> 1];
        else arr[i] = ' ';

    arr[0] = 1; arr[arrsize - 1] = 2;

    static int p[sizeof(arr)];
    memset(p, 0, sizeof(p));

    for (int i = 1; i < arrsize - 1; ++i)
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

    for (int i = 0; i < arrsize; ++i)
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
        }
    }
}

int main()
{
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);

    static char original[N], lowercased[N], processed[N];
    static int processed_to_original[N];

    int n = fread(original, sizeof(char), sizeof(original), stdin);

    transform(original, original + n,
              lowercased, static_cast<int (*)(int)>(tolower));

    original[n] = lowercased[n] = '\0';

    int np = 0;
    for (int i = 0; i < n; ++i)
    {
        if (islower(lowercased[i]))
        {
            processed[np] = lowercased[i];
            processed_to_original[np] = i;
            ++np;
        }
    }

    processed[np] = '\0';

    int begin, end, actual_length, displayed_length;
    longest_palindrome(processed, np, begin, end);
    actual_length = end - begin;
    begin = processed_to_original[begin];
    end = processed_to_original[end - 1] + 1;
    displayed_length = end - begin;

    printf("%d\n", actual_length);
    char *displayed = original + begin;
    displayed[displayed_length] = '\0';
    printf("%s\n", displayed);

    return EXIT_SUCCESS;
}
