using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size()<2) return {};

        vector<int> myReturn{};

        unordered_map<int,int> pastNumbers{};

        for(int i=0; i<nums.size(); i++)
        {
            if(pastNumbers.find(target-nums[i])!= pastNumbers.end())
            {
                myReturn.push_back(pastNumbers[target-nums[i]]);
                myReturn.push_back(i);
                return myReturn;
            }
            else
                pastNumbers[nums[i]]=i;
        }

        return myReturn;

    }
};