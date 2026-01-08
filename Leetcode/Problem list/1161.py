#Definition for a binary tree node.
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def solve(self, node, level):
        self.maxi=max(self.maxi,level)
        self.suma[level]+=node.val
        if(node.left is not None):
            self.solve(node.left,level+1)
        if(node.right is not None):
            self.solve(node.right,level+1)
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        self.suma=[0 for _ in range(10000)]
        self.maxi=0
        self.solve(root,0)
        for i in range(self.maxi-1,-1,-1):
            if(self.suma[i]==1):
                print(i)
            if(self.suma[i]>=self.suma[self.maxi]):
                self.maxi=i
        return self.maxi+1