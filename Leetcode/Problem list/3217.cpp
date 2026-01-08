#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n;
struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100000> existe;
        for(auto u:nums)existe[u-1]=1;
        while(existe[head->val-1])head=head->next;
        vector<ListNode*> nose;
        nose.push_back(head);
        while(head->next!=nullptr){
            if(existe[head->next->val-1])head->next=head->next->next;
            else nose.push_back(head=head->next);
        }
        n=nose.size();
        for(int i=n-2;i>=0;i--){
            nose[i]->next=nose[i+1];
        }
        return nose[0];
    }
};