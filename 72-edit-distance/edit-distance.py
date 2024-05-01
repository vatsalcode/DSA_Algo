class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m=len(word1)
        n=len(word2)
        dp=[[0]*(n+1) for _ in range(m+1)]
        for i in range(m+1):
            for j in range(n+1):
                if i==0:
                    dp[i][j]=j # filling thr first row
                elif j==0:
                    dp[i][j]=i # Cokum
                elif word1[i-1]==word2[j-1]: #charcter match no extra cost
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]= min(
                        dp[i-1][j]+1, #delection
                        dp[i][j-1]+1,  #incertion
                        dp[i-1][j-1]+1 # swap
                    )
        return dp[m][n]
        