#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
class Solution {
public:
    pair<TreeNode*,int> solve(TreeNode* node){
        pair<TreeNode*,int> res1,res2;
        if(node->left==nullptr && node->right==nullptr){
            return {node,1};
        }
        if(node->left==nullptr){
            res2=solve(node->right);
            return {res2.first,res2.second+1};
        }
        if(node->right==nullptr){
            res1=solve(node->left);
            return {res1.first,res1.second+1};
        }
        res1=solve(node->left);
        res2=solve(node->right);
        if(res1.second==res2.second){
            return {node,res1.second+1};
        }else if(res1.second>res2.second){
            return {res1.first,res1.second+1};
        }else{
            return {res2.first,res2.second+1};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).first;
    }
};