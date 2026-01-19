#include <bits/stdc++.h>
using namespace std;
int a;
set<int> dif;
void solve(int day,int sum,vector<int> fi,vector<int> se){
    if(day==4){
        dif.insert(sum);
        return;
    }
    if(day&1){
        vector<int> nue1=fi,nue2=se;
        for(int i=0;i<se.size();i++){
            nue1.push_back(nue2[0]);
            nue2.erase(nue2.begin());
            solve(day+1,sum+nue1.back(),nue1,nue2);
            nue2.push_back(nue1.back());
            nue1.pop_back();
        }
    }else{
        vector<int> nue1=fi,nue2=se;
        for(int i=0;i<fi.size();i++){
            nue2.push_back(nue1[0]);
            nue1.erase(nue1.begin());
            solve(day+1,sum-nue2.back(),nue1,nue2);
            nue1.push_back(nue2.back());
            nue2.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    vector<int> nums1(10),nums2(10);
    for(int i=0;i<10;i++)cin >> nums1[i];
    for(int j=0;j<10;j++)cin >> nums2[j];
    solve(0,0,nums1,nums2);
    //for(auto u:dif)cout <<u << ' ';
    cout << dif.size();
}