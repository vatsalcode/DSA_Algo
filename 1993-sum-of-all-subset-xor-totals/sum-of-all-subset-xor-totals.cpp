class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
    int n = nums.size();
 
    for (int i = 1; i < (1 << n); ++i) {  // 1 << n gives 2^n, the number of subsets
        int currentXOR = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {  // Check if the j-th element is in the subset
                currentXOR ^= nums[j];
            }
        }
        sum += currentXOR;
    }
    return sum;
    }
};