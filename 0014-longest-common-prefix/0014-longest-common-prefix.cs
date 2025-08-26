public class Solution {
    public string LongestCommonPrefix(string[] strs) {

        if(strs == null || strs.Length == 0)
        {
             return "";
        }
          
        string prefix = "";


        for (int i = 0; i < strs[0].Length; i++)
        {
            char currentChar = strs[0][i];

            for (int j = 0; j < strs.Length; j++)
            {
                if(i >= strs[j].Length || strs[j][i] != currentChar)
                {
                    return prefix;
                }
            }
            prefix += currentChar;

        }
        return prefix;
        
    }
}