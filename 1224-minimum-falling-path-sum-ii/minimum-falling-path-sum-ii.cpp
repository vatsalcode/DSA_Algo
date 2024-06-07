
// N*N--> Min sum
//grid = [[1,2,3],[4,5,6],[7,8,9]]
// Output--> 13
//[1,5,7,], [1,5,8],[1,6,8]
// dp[i][j]--->start i and ending at j
//base case--> last row ele
// grid = [[1,2,3],[4,5,6],[7,8,9]]
// last row--> dp= [7,8,9]
// for 2nd last row:
// dp[0]= grid[1][0]+min(dp[1], dp[2])= 4+min(8,9)=4+8=12
// dp[1]= grid[1][1]+min(dp[0], dp[2])= 5+min(7,9)=5+7=12
// dp[2]= grid[1][2]+min(dp[0], dp[1])= 6+min(7,8)=6+7=13

// dp=[12,12,13]

// for first row:
// dp[0]= grid[0][0]+min(dp[1], dp[2])= 1+min(12,13)=1+12=13
// dp[1]= grid[0][1]+min(dp[0], dp[2])= 2+min(12,13)=2+12=14
// dp[2]= grid[0][2]+min(dp[0], dp[1])= 3+min(12,12)=3+12=15

// dp= [13,14,15]
// Out min(dp)= 13

//

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>dp= grid[n-1]; // start with last row

        // 2nd to 1 st row

        for(int i=n-2;i>=0;i--){
            vector<int>new_dp(n,INT_MAX);
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j!=k){
                        new_dp[j]=min(new_dp[j], grid[i][j]+dp[k]);
                    }
                }
            }
            dp=new_dp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};