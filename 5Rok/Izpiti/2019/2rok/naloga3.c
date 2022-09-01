#include <stdio.h>
#include <stdlib.h>

int m, n;
char *solution;
int options[4][2] = {
    0, -1,
    -1, 0,
    0, 1,
    1, 0};

int fun(char maze[m][n][4], int visited[m][n], int row, int col, int winRow, int winCol, int length)
{
    visited[row][col] = 1;
    if (row == winRow && col == winCol)
    {
        solution = calloc(length, sizeof(*solution));
        return 1;
    }
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + options[i][0];
        int newCol = col + options[i][1];
        if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n)
            continue;
        if (visited[newRow][newCol])
            continue;
        if (maze[row][col][i] == 1)
            continue;
        if (fun(maze, visited, newRow, newCol, winRow, winCol, length + 1))
        {
            solution[length] = (char)(i + '0');
            return 1;
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &m, &n);
    char maze[m][n][4];
    int visited[m][n];
    char tempCell[4];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%s", tempCell);
            for (int k = 0; k < 4; k++)
            {
                maze[i][j][k] = tempCell[k];
                visited[i][j] = 0;
            }
        }
    }
    fun(maze, visited, 0, 0, m - 1, n - 1, 0);
    printf("%s\n", solution);

    free(solution);

    return 0;
}
