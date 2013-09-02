#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// Notice that elements of a hash table could be negative!

class Solution {

private:

    int tablesize;
    int allodsize;
    int *hashtable;
    bool *hashexists;
    bool *hashremoved;

    inline int find(int x) {
        int pos = x % tablesize;
        while (pos < 0) pos += tablesize;
        for (int i = 0; i < tablesize; ++i) {
            int j = i + pos;
            if (!hashexists[j]) return -1;
            if (!hashremoved[j] && hashtable[j] == x) return j;
        }
        return -1;
    }

    inline void insert(int x) {
        int pos = x % tablesize;
        while (pos < 0) pos += tablesize;
        for (int i = 0; i < tablesize; ++i) {
            int j = i + pos;
            if (!hashexists[j]) {
                hashexists[j] = true;
                hashtable[j] = x;
                return;
            }
        }
    }

    inline void remove(int i) {
        hashremoved[i] = true;
    }

    inline void allo(int size) {
        if (allodsize < size) {
            free();
            allodsize = size;
            hashtable = new int[size];
            hashexists = new bool[size];
            hashremoved = new bool[size];
        }
        tablesize = size;
        memset(hashexists, false, sizeof(bool) * size);
        memset(hashremoved, false, sizeof(bool) * size);
    }

    inline void init() {
        tablesize = allodsize = 0;
        hashtable = NULL;
        hashexists = NULL;
        hashremoved = NULL;
    }

    inline void free() {
        if (hashtable != NULL) delete [] hashtable;
        if (hashexists != NULL) delete [] hashexists;
        if (hashremoved != NULL) delete [] hashremoved;
        init();
    }

public:

    Solution() {
        init();
        allo(1001);
    }

    virtual ~Solution() {
        free();
    }

    int longestConsecutive(vector<int> &num) {

        allo(2 * num.size() + 7);

        for (int i = 0; i < num.size(); ++i)
            if (find(num[i]) < 0) // avoid duplication
                insert(num[i]);

        int ans = 0;
        for (int i = 0; i < num.size(); ++i) {
            int x = num[i];
            int xpos = find(x);
            if (xpos < 0) continue;
            remove(xpos);

            int left = 0, right = 0, sum;

            for (int y = x - 1; ; --y, ++left) {
                int ypos = find(y);
                if (ypos < 0) break;
                remove(ypos);
            }

            for (int y = x + 1; ; ++y, ++right) {
                int ypos = find(y);
                if (ypos < 0) break;
                remove(ypos);
            }

            sum = left + right + 1;
            ans = max(ans, sum);
        }

        return ans;
    }
};
