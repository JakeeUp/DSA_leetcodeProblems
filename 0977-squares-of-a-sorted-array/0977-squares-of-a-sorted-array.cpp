#include <iostream>
template <typename T>
        T square(T x)
        {
            return x * x;
        }

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        

        for(int i = 0; i < nums.size(); i++)
        {
            square(nums[i]);
            nums[i] = square(nums[i]);
        }

        sort(nums.begin(), nums.end());
        return nums;
        
    }

};