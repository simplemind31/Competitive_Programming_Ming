#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(string s,int minJump,int maxJump){
        int n=s.size();
        if(s[n-1]=='1')return false;
        vector<int> psum(n);
        psum[0]=1;
        psum[minJump]++;
        for(int i=0;i<n;i++){
            
        }
    }
};