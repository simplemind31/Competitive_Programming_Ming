#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,sob,a,b;
struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool sob=false;
    vector<int> nume;
    void add(ListNode* l1, ListNode* l2){
        if(l1==nullptr && l2==nullptr){
            if(sob){
                nume.push_back(1);
                sob=false;
            }
            return;
        }
        if(l1==nullptr){
            l2->val+=sob;
            sob=0;
            if(l2->val>9){
                l2->val-=10;
                sob=true;
            }
            nume.push_back(l2->val);
            add(nullptr,l2->next);
        }else if(l2==nullptr){
            l1->val+=sob;
            sob=0;
            if(l1->val>9){
                l1->val-=10;
                sob=true;
            }
            nume.push_back(l1->val);
            add(l1->next,nullptr);
        }else{
            int temp=l1->val+l2->val+sob;
            sob=0;
            if(temp>9){
                temp-=10;
                sob=1;
            }
            nume.push_back(temp);
            add(l1->next,l2->next);
        }

    }
    ListNode* convert(vector<int> nums){
        ListNode* head=new ListNode(nums[0]);
        ListNode* now=head;
        for(int i=1;i<nums.size();i++){
            now->next=new ListNode(nums[i]);
            now=now->next;
        } 
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        add(l1,l2);
        return convert(nume);
    }
};