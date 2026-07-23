// below is the 2d recursion bruteforce approach we saw earlier in 05_recursion

#include <unordered_map>
#include <vector>
using namespace std;

int bruteForce(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return bruteForce(n - 1) + bruteForce(n - 2);
}

// top-down DP approach
int memoization(int n, unordered_map<int, int> &cache)
{
    if (n <= 1)
    {
        return n;
    }

    if (cache.count(n))
    {
        return cache[n];
    }

    cache[n] = memoization(n - 1, cache) + memoization(n - 2, cache);

    return cache[n];
}

// bottom-up DP approach

int dp(int n)
{
    if (n < 2)
        return n;

    vector<int> dp = {0, 1};

    int i = 2;

    while (i <= n)
    {
        int tmp = dp[1];
        dp[1] = dp[0]+ dp[1];
        dp[0] = tmp;
        i += 1;
    }
    return dp[1];
}

// we can also remove vector completely from above code

// int dp(int n)
// {
//     if (n < 2)
//         return n;

//     int prev2 = 0;
//     int prev1 = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         int curr = prev1 + prev2;
//         prev2 = prev1;
//         prev1 = curr;
//     }

//     return prev1;
// }