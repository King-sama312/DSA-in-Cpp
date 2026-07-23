// Q. Count the number of unique paths from top left to bottom right. You are only allowed to move down or right
#include <unordered_map>
#include <vector>
using namespace std;

int bruteForce(int r, int c, int rows, int cols)
{
    if (r == rows || c == cols)
        return 0;

    if (r == rows - 1 || c == cols - 1)
        return 1;

    int count = 0;
    count += bruteForce(r + 1, c, rows, cols);
    count += bruteForce(r, c + 1, rows, cols);

    return count;
}

// top-down DP approach
int memoization(int r, int c, int rows, int cols, vector<vector<int>> &cache)
{
    if (r == rows || c == cols)
        return 0;

    if (cache[r][c] > 0)
        return cache[r][c];

    if (r == rows - 1 || c == cols - 1)
        return 1;

    cache[r][c] = memoization(r + 1, c, rows, cols, cache) + memoization(r, c + 1, rows, cols, cache);
    
    return cache[r][c];
}

// bottom-up DP approach

int dp(int rows, int cols) {
    // Create a vector of size 'cols' initialized with 0s
    vector<int> prevRow(cols, 0);

    for (int r = rows - 1; r >= 0; r--) {
        vector<int> curRow(cols, 0);
        curRow[cols - 1] = 1;
        
        for (int c = cols - 2; c >= 0; c--) {
            curRow[c] = curRow[c + 1] + prevRow[c];
        }
        
        prevRow = curRow; 
    }
    
    return prevRow[0];
}