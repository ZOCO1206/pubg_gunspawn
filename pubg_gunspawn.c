#include <stdio.h>
int main()
{
    int i, j, row, col, t, moves;
    long long int g, grid[100][50], coins[50];
    for (i = 0; i < 100; i++)
    {
        grid[i][0] = 1;
        for (j = 1; j <= i && j < 50; j++)
        {
            if (i == j)
                grid[i][j] = 1;
            else
                grid[i][j] = grid[i - 1][j - 1] + grid[i - 1][j];
        }
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %lld", &row, &col, &g);
        moves = 0;
        while (g > 0)
        {
            row = col;
            while (row < 100 && grid[row][col] <= g)
                row++;
            row--;
            g = g - grid[row][col];
            coins[moves] = grid[row][col];
            moves++;
            col--;
        }
        printf("%d\n", moves);
        for (i = 0; i < moves; i++)
            printf("%lld ", coins[i]);
        printf("\n");
    }
    return 0;
}
