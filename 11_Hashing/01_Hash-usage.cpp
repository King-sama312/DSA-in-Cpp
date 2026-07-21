#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    vector<string> names = {"alice", "brad", "collin", "brad", "dylan", "kim"};
    unordered_map<string, int> countMap;

    for (const string &name : names)
    {
        countMap[name]++;
    }
    return 0;
}