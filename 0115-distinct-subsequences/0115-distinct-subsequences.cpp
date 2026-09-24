#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.size();
        int n = t.size();
        
        // dp[j] stores the number of distinct subsequences of s that equal t[0...j-1]
        // Use unsigned long long to prevent intermediate runtime integer overflow
        std::vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: An empty t can be formed by any prefix of s in 1 way
        dp[0] = 1;
        
        // Iterate through each character of s
        for (char count_char : s) {
            // Iterate backwards through t to use the current row's updated states correctly
            for (int j = n; j >= 1; --j) {
                if (count_char == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};
