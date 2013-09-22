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

struct TreeNode
{
    bool dangerous;
    TreeNode *fallback;
    TreeNode *children[26];

    TreeNode()
    {
        fallback = NULL;
        dangerous = false;
        memset(children, 0, sizeof(children));
    }

    ~TreeNode()
    {
        for (int i = 0; i < 26; ++i)
            if (children[i])
                delete children[i];
    }
};

class Tree
{
    TreeNode *root;
    TreeNode *dummy;

public:

    Tree()
    {
        root = new TreeNode();
        dummy = new TreeNode();

        for (int i = 0; i < 26; ++i)
            dummy->children[i] = root;

        root->fallback = dummy;
    }

    virtual ~Tree()
    {
        delete root;

        for (int i = 0; i < 26; ++i)
            dummy->children[i] = NULL;

        delete dummy;
    }

    void insert(const char *str)
    {
        TreeNode *current = root;

        for (const char *p = str; *p; ++p)
        {
            int i = *p - 'A';

            TreeNode *&child = current->children[i];

            if (child == NULL)
            {
                child = new TreeNode();
                TreeNode *fallback = current->fallback;

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
        TreeNode *current = root;

        for (const char *p = str; *p; ++p)
        {
            int i = *p - 'A';

            current = current->children[i];

            if (current == NULL)
                return ret;

            if (current->dangerous)
            {
                ret = p - str + 1;
                current = root;
            }
        }

        return ret;
    }
};

Tree patterns;
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
