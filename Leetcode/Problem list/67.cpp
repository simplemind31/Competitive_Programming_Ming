#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
class Solution {
public:
    string addBinary(string a, string b){
        int n=a.size(),m=b.size();
        reverse(ALL(a));
        reverse(ALL(b));
        while(n<m){
            a.push_back('0');
            n++;
        }
        while(m<n){
            b.push_back('0');
            m++;
        }
        string nue=a;
        bool sobra=0;
        for(int i=0;i<n;i++){
            nue[i]=((sobra+a[i]+b[i])&1)+'0';
            sobra=(sobra+a[i]-'0'+b[i]-'0')>>1;
        }
        if(sobra)nue.push_back('1');
        reverse(ALL(nue));
        return nue;
    }
};