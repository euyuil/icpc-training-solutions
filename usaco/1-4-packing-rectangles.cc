/*
ID: 31415926
LANG: C++
TASK: packrec
*/

#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int rects[4][2];
int minArea = INT_MAX;
map<int, int> minRects;

int getWidth(int rect, int orient)
{
    return rects[rect][orient & 1];
}

int getHeight(int rect, int orient)
{
    return rects[rect][(orient & 1) ^ 1];
}

bool discovered(int wid, int hei)
{
    int area = wid * hei;
    if (area < minArea)
    {
        minArea = area;
        minRects.clear();
        minRects[min(wid, hei)] = max(wid, hei);
        fprintf(stderr, "new min area discovered %d = %d x %d.\n",
                         area, min(wid, hei), max(wid, hei));
        return true;
    }
    else if (area == minArea)
    {
        minRects[min(wid, hei)] = max(wid, hei);
        // fprintf(stderr, "same min area discovered %d = %d x %d.\n",
        //                  area, min(wid, hei), max(wid, hei));
    }
    return false;
}

int rectOrder[4], orientOrder[4];
bool nsUsed[4] = {false};

void search(int dep, int wid, int hei)
{
    if (dep >= 4)
    {
        if (getWidth (rectOrder[0], orientOrder[0]) <=
            getWidth (rectOrder[1], orientOrder[1]) &&
            getHeight(rectOrder[1], orientOrder[1]) <=
            getHeight(rectOrder[2], orientOrder[2]))
        {
            int width  = max(getWidth (rectOrder[1], orientOrder[1]) +
                             getWidth (rectOrder[2], orientOrder[2]),
                             getWidth (rectOrder[0], orientOrder[0]) +
                             getWidth (rectOrder[3], orientOrder[3]));

            int height = max(getHeight(rectOrder[0], orientOrder[0]) +
                             getHeight(rectOrder[1], orientOrder[1]),
                             getHeight(rectOrder[2], orientOrder[2]) +
                             getHeight(rectOrder[3], orientOrder[3]));

            if (discovered(width, height))
            {
                fprintf(stderr, "\tit was discovered in special search.\n");
            }
        }

        if (discovered(wid, hei))
        {
            fprintf(stderr, "\tit was discovered in normal search.\n");
        }
    }
    else
    {
        for (int rect = 0; rect < 4; ++rect)
        {
            if (nsUsed[rect])
                continue;

            nsUsed[rect] = true;
            rectOrder[dep] = rect;

            for (int orient = 0; orient <= 1; ++orient)
            {
                int width = getWidth(rect, orient);
                int height = getHeight(rect, orient);

                orientOrder[dep] = orient;

                // putting it on the right
                search(dep + 1, wid + width, max(hei, height));

                // putting it at the bottom
                search(dep + 1, max(wid, width), hei + height);
            }

            nsUsed[rect] = false;
        }
    }
}

int main()
{
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);

    for (int i = 0; i < 8; ++i)
        scanf("%d", (int *)rects + i);

    search(0, 0, 0);

    printf("%d\n", minArea);

    for (map<int, int>::iterator it  = minRects.begin();
                                 it != minRects.end(); ++it)
    {
        printf("%d %d\n", it->first, it->second);
    }

    return EXIT_SUCCESS;
}
