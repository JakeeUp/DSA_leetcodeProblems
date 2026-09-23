class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //input
        //given array


        //what technique :: kadanes algorith
        //init current max number
        //init global max number, init index of the given array

        int currentMax = nums[0];
        int globalMax = nums[0];


        //what to do with the data?
        // scan through the array to find the max sum of a subarray
        // create the sub array

        for(int i = 1; i < nums.size(); i++)
        {
            currentMax = max(nums[i], currentMax + nums[i]);

            if(currentMax > globalMax)
                globalMax = currentMax;
        }


        //output

        //return the max sum of a subarray

        return globalMax;
    }
};