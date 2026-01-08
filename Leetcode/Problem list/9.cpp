#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x){
        if(x<0)return 0;
        vector<int> n,m;
        while(x){
            n.push_back(x%10);
            x/=10;
        }
        m=n;
        reverse(m.begin(),m.end());
        return n==m;
    }
};