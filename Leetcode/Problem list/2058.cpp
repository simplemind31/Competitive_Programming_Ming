/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=1e9,valant=head->val,last=-1,first=-1;
        head=head->next;
        for(int i=1;head;i++,valant=head->val,head=head->next){
            if(head->next && ((head->val<valant && head->val<head->next->val)||(head->val>valant && head->val>head->next->val))){
                if(last!=-1)mini=min(mini,i-last);
                if(first==-1)first=i;
                last=i;
            }
        }
        if(mini==1e9)return {-1,-1};
        return {mini,last-first};
    }
};