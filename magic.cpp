// 840. Magic Squares In Grid
#include <bits/stdc++.h>
using namespace std;

bool isMS(vector<vector<int>> &a, int r, int c)
{
    bool pre[10] = {false};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x = a[r + i][c + j];
            if (x < 1 || x > 9)
                return false;
            if (pre[x])
                return false;
            pre[x] = true;
        }
    }

    int d1 = a[r][c] + a[r + 1][c + 1] + a[r + 2][c + 2];
    int d2 = a[r + 2][c] + a[r + 1][c + 1] + a[r][c + 2];

    if (d1 != d2)
        return false;
    int r1 = a[r][c] + a[r][c + 1] + a[r][c + 2];
    int r2 = a[r + 1][c] + a[r + 1][c + 1] + a[r + 1][c + 2];
    int r3 = a[r + 2][c] + a[r + 2][c + 1] + a[r + 2][c + 2];

    if (r1 != d1 || r2 != d1 || r3 != d1)
        return false;

    int c1 = a[r][c] + a[r + 1][c] + a[r + 2][c];
    int c2 = a[r][c + 1] + a[r + 1][c + 1] + a[r + 2][c + 1];
    int c3 = a[r][c + 2] + a[r + 1][c + 2] + a[r + 2][c + 2];

    if (c1 != d1 || c2 != d1 || c3 != d1)
        return false;

    return true;
}

int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    if ((r < 3) || (c < 3))
        return 0;

    int ans = 0;
    for (int i = 0; i < r - 2; i++)
    {
        for (int j = 0; j < c - 2; j++)
        {
            if (isMS(grid, i, j))
                ans++;
        }
    }

    return ans;
}

int main()
{
}
