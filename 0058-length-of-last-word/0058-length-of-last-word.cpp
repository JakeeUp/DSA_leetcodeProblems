class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = 0;

        for(int i = s.length() - 1; i >= 0; --i)
        {
            if(s[i] != ' ')
            {
                ++k;

            }
            else if (k > 0)
                return k;
        }

        return k;
    }
};