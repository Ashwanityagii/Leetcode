void dfs(char** grid, int row, int col, int r, int c) {
    if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == '0')
        return;

    grid[r][c] = '0';

    dfs(grid, row, col, r + 1, c);
    dfs(grid, row, col, r - 1, c);
    dfs(grid, row, col, r, c + 1);
    dfs(grid, row, col, r, c - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int cols = gridColSize[0];

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridSize, cols, i, j);
            }
        }
    }

    return count;
}