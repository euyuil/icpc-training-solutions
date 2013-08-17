#include <deque>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T, typename C = less<T> >
class monotonous_queue
{
    typedef deque<T> deque_type;
    typedef typename deque_type::iterator deque_iterator;
    typedef typename deque_type::const_iterator deque_const_iterator;

private:
    C compare;
    deque_type data;

public:

    inline bool empty() const { return data.empty(); }
    inline size_t size() const { return data.size(); }
    inline T &top() { return data.front(); }
    inline const T &top() const { return data.front(); }

    inline void push(T v)
    {
        while (!empty() && compare(data.back(), v))
            data.pop_back();
        data.push_back(v);
    }

    inline void pop(T v) {
        if (data.front() == v)
            data.pop_front();
    }

    inline void dump(const char format[]) const
    {
        deque_const_iterator it = data.begin();
        for ( ; it != data.end(); ++it)
            fprintf(stderr, format, *it);
        fprintf(stderr, "\n");
    }
};

const size_t N = 1234567;

size_t n, m; // input size, window size
int arr[N], max_values[N], min_values[N];
monotonous_queue<int, less<int> > max_queue;
monotonous_queue<int, greater<int> > min_queue;

int main()
{
    size_t i, j;

    scanf("%d%d", &n, &m);

    for (i = 0; i < n; ++i)
        scanf("%d", arr + i);

    for (i = 0, j = 0; j < n; )
    {
        max_queue.push(arr[j]);
        min_queue.push(arr[j]);

        ++j;

        if (j - i == m)
        {
            // max_queue.dump("%d ");
            // min_queue.dump("%d ");

            max_values[i] = max_queue.top();
            min_values[i] = min_queue.top();

            max_queue.pop(arr[i]);
            min_queue.pop(arr[i]);

            ++i;
        }
    }

    printf("%d", *min_values);
    for (j = 1; j < i; ++j)
        printf(" %d", min_values[j]);
    printf("\n");

    printf("%d", *max_values);
    for (j = 1; j < i; ++j)
        printf(" %d", max_values[j]);
    printf("\n");

    return EXIT_SUCCESS;
}
