#include <cstdio>
#include <cstring>

using namespace std;

const int N = 30;

int n;
char verb[8], prep[8];
int world[N][N], posx[N], posy[N];

inline void init()
{
    memset(world, -1, sizeof(world));

    for (int i = 0; i < N; ++i)
        world[i][0] = i, posx[i] = i, posy[i] = 0;
}

inline void move_block(int sx, int sy, int dx, int dy)
{
    int a = world[sx][sy];

    world[sx][sy] = -1;
    world[dx][dy] = a;

    posx[a] = dx;
    posy[a] = dy;
}

inline void return_blocks(int px, int py)
{
    for (int i = py; world[px][i] != -1; ++i)
        move_block(px, i, world[px][i], 0);
}

inline void put_pile_to(int sx, int sy, int dx, int dy)
{
    for (int i = 0; world[sx][sy+i] != -1; ++i)
        move_block(sx, sy + i, dx, dy + i);
}

inline int find_top(int x)
{
    int i = -1;
    for (i = 0; world[x][i] != -1; ++i);
    return i;
}

void move_onto(int a, int b)
{
    return_blocks(posx[a], posy[a] + 1);
    return_blocks(posx[b], posy[b] + 1);
    move_block(posx[a], posy[a], posx[b], posy[b] + 1);
}

void move_over(int a, int b)
{
    return_blocks(posx[a], posy[a] + 1);
    move_block(posx[a], posy[a], posx[b], find_top(posx[b]));
}

void pile_onto(int a, int b)
{
    return_blocks(posx[b], posy[b] + 1);
    put_pile_to(posx[a], posy[a], posx[b], posy[b] + 1);
}

void pile_over(int a, int b)
{
    put_pile_to(posx[a], posy[a], posx[b], find_top(posx[b]));
}

int main()
{
    init();
    scanf("%d", &n);
    while (scanf("%s", verb))
    {
        if (strcmp(verb, "quit") == 0)
            break;

        int x, y;
        scanf("%d %s %d", &x, prep, &y);

        if (posx[x] == posx[y])
            continue;

        if (strcmp(verb, "move") == 0)
        {
            if (strcmp(prep, "onto") == 0)
                move_onto(x, y);
            else if (strcmp(prep, "over") == 0)
                move_over(x, y);
        }
        else if (strcmp(verb, "pile") == 0)
        {
            if (strcmp(prep, "onto") == 0)
                pile_onto(x, y);
            else if (strcmp(prep, "over") == 0)
                pile_over(x, y);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d:", i);
        for (int j = 0; world[i][j] != -1; ++j)
            printf(" %d", world[i][j]);
        printf("\n");
    }

    return 0;
}
