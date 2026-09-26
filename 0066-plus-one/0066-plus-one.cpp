class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int lastValue = digits.back();

        for(int i = digits.size() - 1; i >= 0; --i )
        {
            //if its not 9 return asap
            if(digits[i] != 9)
            {
                digits[i] += 1;
                return digits;
            }
            //if it is 9 make i = 0
            if(digits[i] == 9)
            {
                //something here
                digits[i] = 0;
                continue;
            }
        }
        //insert 1 at the start of the list
        digits.insert(digits.begin(), 1);
        return digits;
    }
};