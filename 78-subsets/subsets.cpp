class Solution {
public:
    void dfs(vector<vector<int>>&ans,int start,vector<int>&curr,vector<int>&nums){
        ans.push_back(curr);
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            dfs(ans,i+1,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        dfs(ans,0,curr,nums);
        return ans;
    }
};