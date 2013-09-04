#include <string>
#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int i, j;
    for (i = 0, j = 0; i < b.size(); ++i)
    {
        if (b[i] == a[j])
            ++j;
    }
    cout << j + 1 << endl;
    return 0;
}
