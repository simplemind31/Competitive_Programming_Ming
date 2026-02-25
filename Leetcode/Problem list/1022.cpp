#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root,int val=0){
        if(root==nullptr)return 0;
        val=(val<<1)+root->val;
        if(root->left!=nullptr && root->right!=nullptr)return sumRootToLeaf(root->left,val)+sumRootToLeaf(root->right,val);
        if(root->left!=nullptr)return sumRootToLeaf(root->left,val);
        if(root->right!=nullptr)return sumRootToLeaf(root->right,val);
        return val;
    }
};