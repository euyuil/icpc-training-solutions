#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000111;

int id[N];

int main()
{
    int i = 2, m = 2;
    char c;
    id[1] = 1;
    while (cin >> c)
    {
        switch (c)
        {
        case 'l':
            id[i++] = m++;
            break;
        case 'r':
            if (i > 1)
            {
                cout << id[i - 1] << endl;
                id[i - 1] = m++;
            }
            else
            {
                cout << m++ << endl;
            }
            break;
        default:
            goto the_end;
        }
    }
the_end:
    for (i -= 2; i >= 1; --i)
        cout << id[i] << endl;
    return 0;
}
