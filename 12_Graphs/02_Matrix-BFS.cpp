// DFS answered how many paths are there from A to B while BFS answers what is the shortest path from A to B

// Q. Find the shortest path from the top left to the bottom right   


#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::pair;

// Pass grid as 'const' reference since we are only reading it
int bfs(const vector<vector<int>>& grid) {
    // Handle edge case of an empty grid
    if (grid.empty() || grid[0].empty()) return -1;

    int ROWS = grid.size();
    int COLS = grid[0].size();
    
    // Tracks visited cells to prevent infinite loops and redundant work
    vector<vector<int>> visit(ROWS, vector<int>(COLS, 0));
    
    // Queue stores coordinates as {row, col} for the BFS traversal
    queue<pair<int, int>> q;
    
    // Initialize the starting point
    q.push({0, 0});
    visit[0][0] = 1;

    // Tracks the number of steps taken from the start
    int length = 0; 
    
    // Traverse the grid level by level (radiating outward)
    while (!q.empty()) {
        // Snapshot the number of nodes at the current distance level
        int queueLength = q.size();
        
        // Process all nodes at the current distance before moving further outward
        for (int i = 0; i < queueLength; i++) {
            pair<int, int> curPair = q.front();
            q.pop();
        
            int r = curPair.first, c = curPair.second;
            
            // Target reached: return the current path length
            if (r == ROWS - 1 && c == COLS - 1) {
                return length;
            }

            // Explore all 4 adjacent directions: Right, Left, Down, Up
            int neighbors[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
            
            for (int j = 0; j < 4; j++) {
                int newR = neighbors[j][0], newC = neighbors[j][1];
                
                // Skip if out of bounds, already visited, or an obstacle (1)
                if (newR < 0 || newC < 0 || newR == ROWS || newC == COLS
                    || visit[newR][newC] || grid[newR][newC]) {
                    continue;
                }
                
                // Mark as visited immediately upon adding to the queue to prevent duplicates
                q.push({newR, newC});
                visit[newR][newC] = 1;
            }
        }
        // Increment distance after finishing all nodes at the current level
        length++;
    }
    
    // If the queue empties and the target was never reached, the path is blocked
    return -1;
}