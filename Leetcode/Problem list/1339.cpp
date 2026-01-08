#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//Definition for a binary tree node.
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/
class Solution {
public:
    ll con,maxi;
    vector<ll> nums;
    ll trans(TreeNode* node){
        int now=con;
        nums[now]=node->val;
        if(node->left!=nullptr){
            con++;
            nums[now]+=trans(node->left);
        }
        if(node->right!=nullptr){
            con++;
            nums[now]+=trans(node->right);
        }
        return nums[now];
    }
    void trans2(TreeNode* node){
        maxi=max(maxi,nums[con]*(nums[0]-nums[con]));
        if(node->left!=nullptr){
            con++;
            trans2(node->left);
        }
        if(node->right!=nullptr){
            con++;
            trans2(node->right);
        }
    }
    int maxProduct(TreeNode* root){
        nums.clear();
        nums.resize(5e4);
        con=maxi=0;
        trans(root);
        con=0;
        trans2(root);
        return maxi%1000000007;
    }
};