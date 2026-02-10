#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    const vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string current;
        
        backtrack(digits, 0, current, result);
        return result;
    }

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0'; 
        string letters = keypad[digit];

        for (char c : letters) {
            current.push_back(c);           
            backtrack(digits, index + 1, current, result); 
            current.pop_back();           
        }
    }
};