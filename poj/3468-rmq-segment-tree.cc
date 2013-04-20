#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;

const size_t N = 100000;

struct node_t {
    int l, r; ll sum, inc;
    node_t() {
        l = r = 0; sum = inc = 0ll;
    }
};

struct tree_t
{
    node_t node[10 + N << 2];

    void init(size_t ro, int l, int r)
    {
        node[ro].l = l;
        node[ro].r = r;
        node[ro].sum = 0ll;
        node[ro].inc = 0ll;

        if (l == r) return;

        int m = (l + r) >> 1;
        size_t c = ro << 1;

        init(c, l, m);
        init(c + 1, m + 1, r);
    }

    void add(size_t ro, int l, int r, ll val)
    {
        if (node[ro].l == l && node[ro].r == r) {
            node[ro].inc += val;
            return;
        }

        node[ro].sum += val * (r - l + 1);

        int m = (node[ro].l + node[ro].r) >> 1;
        size_t c = ro << 1;

        if (r <= m)
            add(c, l, r, val);
        else if (l > m)
            add(c + 1, l, r, val);
        else {
            add(c, l, m, val);
            add(c + 1, m + 1, r, val);
        }
    }

    ll calc(size_t ro, int l, int r)
    {
        if (node[ro].l == l && node[ro].r == r)
            return node[ro].sum + node[ro].inc * (r - l + 1);

        ll result = node[ro].inc * (r - l + 1);
        int m = (node[ro].l + node[ro].r) >> 1;
        size_t c = ro << 1;

        if (r <= m)
            result += calc(c, l, r);
        else if (l > m)
            result += calc(c + 1, l, r);
        else {
            result += calc(c, l, m);
            result += calc(c + 1, m + 1, r);
        }

        return result;
    }
};

tree_t tree;

int main(int argc, char *argv[])
{
    size_t n, q; char buf[100];
    while (scanf("%u %u", &n, &q) != EOF) {
        tree.init(1, 1, n);
        for (int i = 1; i <= n; ++i) {
            int a; scanf("%d", &a);
            tree.add(1, i, i, a);
        }
        for (size_t i = 0; i < q; ++i) {
            int u, v, w;
            scanf("%s %d %d", buf, &u, &v);
            if (*buf == 'Q') {
                printf("%lld\n", tree.calc(1, u, v));
            } else /* if (c == 'C') */ {
                scanf("%d", &w);
                tree.add(1, u, v, w);
            }
        }
    }
    return EXIT_SUCCESS;
}
