// Q. Count the unique paths from the top left to the bottom right. A single path may only move along 0's and can't visit the same cell more than once.
#include <vector>
#include <iostream>
using namespace std;

// Pass grid as 'const' reference since we are only reading it
int dfs(const vector<vector<int>> &grid, int r, int c, vector<vector<int>> &visit)
{
    // Edge case for empty grid
    if (grid.empty() || grid[0].empty())
        return 0;

    int ROWS = grid.size(), COLS = grid[0].size();

    // 1. Check bounds and validity
    if (r < 0 || c < 0 || r == ROWS || c == COLS || visit[r][c] == 1 || grid[r][c] == 1)
        return 0;
    // 2. Check if we reached the destination
    if (r == ROWS - 1 && c == COLS - 1)
        return 1;
    // 3. Mark as visited
    visit[r][c] = 1;

    // 4. Explore all 4 directions
    int count = 0;
    count += dfs(grid, r + 1, c, visit);
    count += dfs(grid, r - 1, c, visit);
    count += dfs(grid, r, c + 1, visit);
    count += dfs(grid, r, c - 1, visit);

    // 5. Backtrack
    visit[r][c] = 0;

    return count;
}