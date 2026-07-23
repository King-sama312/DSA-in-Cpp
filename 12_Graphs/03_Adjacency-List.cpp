#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::queue;
using std::string;
using std::unordered_map;
using std::unordered_set;

// GraphNode used for adjacency list
class GraphNode {
public:
    string val_;
    vector<string> neighbors_;

    // Pass constructor argument by const reference
    GraphNode(const string& val) : val_(val) {}
};


// Given directed edges, build an adjacency list
unordered_map<string, vector<string>> buildAdjList() {
    vector<vector<string>> edges = 
        {{"A", "B"}, {"B", "C"}, {"B", "E"}, {"C", "E"}, {"E", "D"}};
    unordered_map<string, vector<string>> adjList;

    // Use 'const vector<string>&' to avoid copying the vector every iteration
    for (const vector<string>& edge : edges) {
        string src = edge[0], dst = edge[1];
        adjList[src].push_back(dst);
    }
    return adjList;
}

// Count paths (backtracking)
// Pass strings and map by 'const reference' to prevent copying
int dfs(const string& node, const string& target, const unordered_map<string, vector<string>>& adjList,
    unordered_set<string>& visit) {
    
    if (visit.count(node)) {
        return 0;
    }
    if (node == target) { 
        return 1;
    }
    
    int count = 0;
    visit.insert(node);
    
    // Check if the node exists in the map before looping to prevent errors,
    // and use 'const string&' to avoid copying string names.
    if (adjList.count(node)) {
        for (const string& neighbor : adjList.at(node)) {
            count += dfs(neighbor, target, adjList, visit);
        }
    }
    
    visit.erase(node);
    return count;
}

// Shortest path from node to target.
int bfs(const string& node, const string& target, const unordered_map<string, vector<string>>& adjList) {
    int length = 0;
    unordered_set<string> visit;
    queue<string> q; // 'q' is safer so it doesn't shadow the 'queue' namespace
    
    visit.insert(node);
    q.push(node);
    
    while (!q.empty()) { // !q.empty() is standard C++ idiom
        int queueLength = q.size();
        for (int i = 0; i < queueLength; i++) {
            string curr = q.front();
            q.pop();
            
            if (curr == target) {
                return length;
            }
            
            if (adjList.count(curr)) {
                for (const string& neighbor : adjList.at(curr)) {
                    if (visit.count(neighbor) == 0) {
                        visit.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }
        length++;
    }
    // Return -1 if target is unreachable
    return -1; 
}