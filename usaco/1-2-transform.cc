/*
ID: 31415926
LANG: C++
TASK: transform
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class matrix
{
private:
    char *data;
    size_t n;

public:

    matrix(size_t n) : n(n)
    {
        data = new char[n * n];
    }

    matrix(const matrix &m) : n(m.n)
    {
        data = new char[n * n];
        memcpy(data, m.data, n * n);
    }

    virtual ~matrix()
    {
        delete [] data;
    }

public:

    matrix &operator=(const matrix &b)
    {
        n = b.n;
        delete [] data;
        data = new char[n * n];
        memcpy(data, b.data, n * n);
        return *this;
    }

    bool operator==(const matrix &b) const
    {
        if (n != b.n) return false;
        if (memcmp(data, b.data, n * n) != 0) return false;
        return true;
    }

    friend istream &operator>>(istream &ist, matrix &m)
    {
        for (size_t i = 0; i < m.n; ++i)
            for (size_t j = 0; j < m.n; ++j)
                ist >> m.at(i, j);
        return ist;
    }

private:

    char &at(size_t i, size_t j)
    {
        return data[i * n + j];
    }

    const char &at(size_t i, size_t j) const
    {
        return data[i * n + j];
    }

    size_t size() const
    {
        return n;
    }

public:

    matrix rotate90() const
    {
        matrix m(n);
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < n; ++j)
                m.at(j, n - 1 - i) = at(i, j);
        return m;
    }

    matrix reflect() const
    {
        matrix m(n);
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < n; ++j)
                m.at(i, n - 1 - j) = at(i, j);
        return m;
    }
};

int all_rotate(const matrix &a, const matrix &b)
{
    matrix m = a;
    for (int i = 1; i <= 3; ++i)
    {
        m = m.rotate90();
        if (m == b) return i;
    }
    return -1;
}

int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    size_t n;
    cin >> n;

    matrix a(n), b(n), m(n);
    cin >> a >> b;

    int result = all_rotate(a, b);

    if (result < 0)
    {
        m = a.reflect();
        if (m == b)
            result = 4;
        else if (all_rotate(m, b) > 0)
            result = 5;
        else if (a == b)
            result = 6;
        else
            result = 7;
    }

    cout << result << endl;

    return EXIT_SUCCESS;
}
