class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastz=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[lastz]=nums[i];
                lastz++;
            }
        }

        for(int i=lastz;i<nums.size();i++){
            nums[i]=0;
        }
    }
};