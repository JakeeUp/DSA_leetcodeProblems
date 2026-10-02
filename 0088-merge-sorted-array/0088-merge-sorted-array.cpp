
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //m is already nums 1 , and n is already nums2


        //make new ints thats pointing through each of the arrays

        for(int a = 0, i = m; a < n; a++)
        {
            nums1[i] = nums2[a];
            i++;
        }

        std::sort(nums1.begin(),nums1.end());
    }
};