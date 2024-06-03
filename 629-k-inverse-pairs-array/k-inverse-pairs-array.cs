public class Solution {
    public int KInversePairs(int n, int k) {
        const int MOD=1000000007;
        int [,] dp=new int[n+1,k+1];
        //base case
        dp[0,0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int x=0;x<=Math.Min(j,i-1);x++){
                    dp[i,j]=(dp[i,j]+dp[i-1,j-x])%MOD;
                }
            }
        }

        return dp[n,k];
    }
}