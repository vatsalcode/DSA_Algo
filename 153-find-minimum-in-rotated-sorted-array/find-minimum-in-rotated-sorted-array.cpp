class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                ans=nums[i+1];
                return ans;
            }
        }
        return nums[0];
    }
};