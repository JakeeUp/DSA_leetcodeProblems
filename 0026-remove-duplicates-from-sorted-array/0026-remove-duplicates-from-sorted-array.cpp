
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //exit function if theres nothing in the array
        if(nums.empty())
            return 0;

        //we need a pointer to start off where we looking at in the array
        int i = 0;

        //so now we need something that will keep moving forward in the array to check
        for(int j = 1; j < nums.size(); j++)
        {
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }

        }

        return i + 1;

        


    

    }
};