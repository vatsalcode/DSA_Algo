class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size() ; 
        long long ans = 0 ; 
        int xor_d = 1e9 ; // The min difference we have to sacrifice without doing xor operation
        int nxor_d = 1e9 ; // The min difference we have to sacrifice by doing xor .
        int cnt = 0 ; // No of elements where xor val is greater than node val
        for(int i = 0 ; i < n ; i++){
            int xor_val = nums[i]^k ;
            if(xor_val > nums[i]){
                cnt++;
                ans += xor_val ; 
                xor_d = min(xor_d , xor_val - nums[i]);
            }else{
                ans += nums[i] ;
                nxor_d = min(nxor_d , nums[i]-xor_val) ; 
            }
        }
        if(cnt%2 == 0){
            return ans ;
        }
        return ans - min(xor_d , nxor_d) ;
    }
};