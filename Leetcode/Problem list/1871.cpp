#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(string s,int minJump,int maxJump){
        int n=s.size();
        if(s[n-1]=='1')return false;
        vector<int> psum(n);
        if(maxJump+1>=n)return true;
        psum[minJump]++;
        psum[maxJump+1]--;
        int de=maxJump;
        for(int i=1;i+minJump<n && i<=de;i++){
            psum[i]+=psum[i-1];
            if(s[i]=='1' || !psum[i])continue;
            if(i+maxJump+1>=n)return true;
            psum[i+minJump]++;
            de=i+maxJump;
            psum[i+maxJump+1]--;
        }
        return false;
    }
};