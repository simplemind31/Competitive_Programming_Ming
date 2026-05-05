#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};
class Solution {
public:
    int tam;
    ListNode* rotateRight(ListNode* head,int k){
        ListNode* now=head;
        tam=0;
        while(now!=nullptr){
            tam++;
            now=now->next;
        }
        // now=cola
        if(tam==0)return head;
        k%=tam;
        if(k==0)return head;
        ListNode* nue=head;
        for(int i=0;i<tam-k-1;i++){
            nue=nue->next;
        }
        ListNode* cabe=nue->next;
        ListNode* temp=cabe;
        nue->next=nullptr;
        now=head;
        while(temp->next!=nullptr)temp=temp->next;
        temp->next=head;
        return cabe;
    }
};