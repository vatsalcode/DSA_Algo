class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int>possible;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==0){
                    int put= max(nums[i],nums[j]);
                    possible.push_back(put);
                
                }
            }
        }
        if(possible.empty()){
            return -1;
        }
        int ans= *max_element(possible.begin(), possible.end());
        return ans;
    }
};