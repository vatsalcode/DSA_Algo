class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        #dp[i][j]-->insert[i,j-1], delete-->[i-1,j], replace-->[i-1,j-1]
        n=len(word1)
        m=len(word2)

        #Dp
        dp=[[0]*(m+1) for x in range (n+1)]

        for i in range(n+1):
            for j in range(m+1):
                if i==0:
                    dp[i][j]=j
                elif j==0:
                    dp[i][j]=i
                elif word1[i-1]==word2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]= 1+min(
                        dp[i][j-1],
                        dp[i-1][j],
                        dp[i-1][j-1]
                    )
        return dp[n][m]

        