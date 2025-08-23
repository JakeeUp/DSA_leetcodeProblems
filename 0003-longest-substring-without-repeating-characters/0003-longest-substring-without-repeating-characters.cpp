//test leetHub
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char,int> last;
        int best = 0, left = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            auto it = last.find(s[i]);
            if (it != last.end() && it->second >= left) left = it->second + 1;
            last[s[i]] = i;
            best = std::max(best, i - left + 1);
        }
        return best;
    }
};