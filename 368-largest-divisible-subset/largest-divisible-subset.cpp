class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n=nums.size();
            if(n==0)return {};

            sort(nums.begin(),nums.end());
            vector<int>dp(n,1),parent(n,-1);
            int max_size=1,max_index=0;

        for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > max_size) {
            max_size = dp[i];
            max_index = i;
        }
    }

    vector<int> result;
    for (int i = max_index; i != -1; i = parent[i]) {
        result.push_back(nums[i]);
    }

    return result;        
    }
};