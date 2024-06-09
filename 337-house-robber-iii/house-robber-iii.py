# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        memo={} # dp+memoization
        #1-> rob ccurr node we have skip its child
        #2--> if we dont rob curr then we can rob its child
        def max_rob(node):
            if not node:
                return 0
            if node in memo:
                return memo[node]

            rob_this=node.val
            if node.left:
                rob_this+=max_rob(node.left.left)+max_rob(node.left.right)
            if node.right:
                rob_this+=max_rob(node.right.right)+max_rob(node.right.left)

            #if we dont rob this node
            not_rob_this= max_rob(node.left)+max_rob(node.right)

            ans= max(rob_this, not_rob_this)
            memo[node]=ans
            return ans

        return max_rob(root)
        