/*
ID: 31415926
LANG: C++
TASK: prefix
*/

#include <queue>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct TrieNode
{
    int depth;
    bool dangerous;
    TrieNode *fallback;
    TrieNode *children[26];

    TrieNode(int depth) : depth(depth)
    {
        fallback = NULL;
        dangerous = false;
        memset(children, 0, sizeof(children));
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; ++i)
            if (children[i])
                delete children[i];
    }
};

class Trie
{
    TrieNode *root;
    TrieNode *dummy;

public:

    Trie()
    {
        root = new TrieNode(0);
        dummy = new TrieNode(-1);

        for (int i = 0; i < 26; ++i)
            dummy->children[i] = root;

        root->fallback = dummy;
        dummy->fallback = dummy;
    }

    virtual ~Trie()
    {
        delete root;

        for (int i = 0; i < 26; ++i)
            dummy->children[i] = NULL;

        delete dummy;
    }

    void insert(const char *str)
    {
        TrieNode *current = root;

        for (const char *p = str; *p; ++p)
        {
            int i = *p - 'A';

            if (current->children[i] == NULL)
                current->children[i] = new TrieNode(current->depth + 1);

            current = current->children[i];
        }

        current->dangerous = true;
    }

    void compile()
    {
        queue<TrieNode *> q;

		q.push(this->root);

		while (!q.empty())
		{
			TrieNode *current = q.front(); q.pop();

			for (int i = 0; i < 26; ++i)
			{
				TrieNode *child = current->children[i];

				if (child != NULL)
				{
					TrieNode *fallback = current->fallback;

					while (fallback->children[i] == NULL)
						fallback = fallback->fallback;

					child->fallback = fallback->children[i];

					if (child->fallback->dangerous)
						child->dangerous = true;

					q.push(child);
				}
			}
		}
    }

    int match(const char *str) const
    {
        TrieNode *current = root;
        int ret = 0, len = strlen(str);

        bool *matched = new bool[len + 1];
        memset(matched, 0, (len + 1) * sizeof(bool));
        matched[0] = true;

        for (const char *p = str; *p; ++p)
        {
            int i = *p - 'A';

            while (current->children[i] == NULL)
            {
                current = current->fallback;

                if (current == dummy)
                    goto lovely;
            }

            current = current->children[i];

            if (current->dangerous)
            {
                int j = p - str + 1;

                if (matched[j - current->depth])
                {
                    ret = j;
                    matched[j] = true;
                }
            }
        }

lovely:

        delete [] matched;

        return ret;
    }
};

Trie patterns;
char buf[32], seq[222222];

int main()
{
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    while (scanf("%s", buf))
    {
        if (buf[0] == '.')
            break;
        patterns.insert(buf);
    }

    patterns.compile();

    int ch, pos = 0;
    while ((ch = getchar()) != EOF)
        if (isupper(ch))
            seq[pos++] = ch;
    seq[pos++] = '\0';

    printf("%d\n", patterns.match(seq));

    return EXIT_SUCCESS;
}
