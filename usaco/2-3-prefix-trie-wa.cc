/*
ID: 31415926
LANG: C++
TASK: prefix
*/

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
    bool dangerous;
    TrieNode *fallback;
    TrieNode *children[26];

    TrieNode()
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

// this should NOT be using Trie...

class Trie
{
    TrieNode *root;
    TrieNode *dummy;

public:

    Trie()
    {
        root = new TrieNode();
        dummy = new TrieNode();

        for (int i = 0; i < 26; ++i)
            dummy->children[i] = root;

        root->fallback = dummy;
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

            TrieNode *&child = current->children[i];

            if (child == NULL)
            {
                child = new TrieNode();
                TrieNode *fallback = current->fallback;

                while (fallback->children[i] == NULL)
                    fallback = fallback->fallback;

                child->fallback = fallback->children[i];
            }

            current = child;
        }

        current->dangerous = true;
    }

    int match(const char *str)
    {
        int ret = 0;
        TrieNode *current = root;

        for (const char *p = str; *p; ++p)
        {
            int i = *p - 'A';

            while (current->children[i] == NULL)
            {
                current = current->fallback;

                if (current == dummy)
                    return ret;
            }

            current = current->children[i];

            if (current->dangerous)
                ret = p - str + 1;
        }

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

    int ch, pos = 0;
    while ((ch = getchar()) != EOF)
        if (isupper(ch))
            seq[pos++] = ch;
    seq[pos++] = '\0';

    printf("%d\n", patterns.match(seq));

    return EXIT_SUCCESS;
}
