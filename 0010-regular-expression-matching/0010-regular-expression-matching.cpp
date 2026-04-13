class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return dp(s, p, 0, 0, memo);
    }

private:
    bool dp(const string& s, const string& p, int i, int j, vector<vector<int>>& memo) {
        if (j == p.size()) return i == s.size();
        if (memo[i][j] != -1) return memo[i][j];

        bool firstMatch = (i < s.size()) && (s[i] == p[j] || p[j] == '.');

        bool result;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            result = dp(s, p, i, j + 2, memo) ||
                     (firstMatch && dp(s, p, i + 1, j, memo));
        } else {
            result = firstMatch && dp(s, p, i + 1, j + 1, memo);
        }

        memo[i][j] = result;
        return result;
    }
};