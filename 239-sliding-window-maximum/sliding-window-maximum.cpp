class Solution {
public:
/*
nums = [1,3,-1,-3,5,3,6,7] K=3
empty deque 
1 ->3 , rmeove 1 from the dq 3>1
move -1, dq has 3,-1 max--> 3,

*/

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int>dq; // store indecineres

        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};