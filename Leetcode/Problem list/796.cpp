#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string& s, string& goal){
        int n=s.size();
        if(n!=goal.size())return false;
        for(int i=0;i<n;i++){
            bool xd=true;
            for(int j=0;j<n && xd;j++)xd=s[(i+j)%n]==goal[j];
            if(xd)return true;
        }
        return false;
    }
};