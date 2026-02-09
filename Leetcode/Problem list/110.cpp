#include <bits/stdc++.h>
using namespace std;
/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/
class Solution {
public:
    int mini,maxi;
    pair<int,bool> trav(TreeNode* node,int alt){
        if(node==nullptr)return {alt,true};
        pair<int,bool> a=trav(node->left,alt+1),b=trav(node->right,alt+1);
        if(a.first>b.first)swap(a,b);
        if(!b.second || b.first-a.first>1)a.second=false;
        return {b.first,a.second};
    }
    bool isBalanced(TreeNode* root){
        mini=1e9,maxi=0;
        return trav(root,0).second;
    }
};