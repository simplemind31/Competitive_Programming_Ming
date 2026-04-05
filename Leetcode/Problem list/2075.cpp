#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows){
        string st="";
        int n=encodedText.size()/rows;
        for(int i=0;i<n;i++){
            for(int j=i;j<n*rows;j+=n+1){
                st.push_back(encodedText[j]);
            }
        }
        while(!st.empty() && st.back()==' ')st.pop_back();
        return st;
    }
};