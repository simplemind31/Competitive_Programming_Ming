#include <bits/stdc++.h>
using namespace std;
int n,lastg,lasth;
string st;
bool eg,eh;
int lh=-1,lg=-1,canp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        if(st[i]=='H')lasth=i;
        else lastg=i;
    }
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(st[i]=='H'){
            if(!eh){
                if(nums[i]>=lasth+1)lh=i;
            }
            eh=true;
        }else{
            if(!eg){
                if(nums[i]>=lastg+1)lg=i;
            }
            eg=true;
        }
    }
    if(lg!=-1 && lh!=-1)canp++;
    for(int i=0;i<n;i++){
        if(st[i]=='H'){
            if(i==lh)continue;
            if(i<=lg && lg<=nums[i]-1)canp++;
        }else{
            if(i==lg)continue;
            if(i<=lh && lh<=nums[i]-1)canp++;
        }
    }
    cout << canp;
}