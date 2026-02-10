#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> nums;
    void trav(TreeNode* node){
        if(node==nullptr)return;
        trav(node->left);
        nums.push_back(node->val);
        trav(node->right);
    }
    TreeNode* fill(int l,int r){
        if(l>r)return nullptr;
        int mid=(l+r)>>1;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=fill(l,mid-1);
        node->right=fill(mid+1,r);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root){
        nums.clear();
        trav(root);
        if(nums.empty())return root;
        TreeNode* res=new TreeNode(nums[0]);
        return fill(0,nums.size()-1);
    }
};