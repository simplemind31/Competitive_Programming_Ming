#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary){
        int n=queries[0].size();
        vector<string> res;
        for(auto u:queries){
            for(auto v:dictionary){
                int con=0;
                for(int i=0;i<n && con<3;i++)con+=u[i]!=v[i];
                if(con<3){
                    res.push_back(u);
                    break;
                }
            }
        }
        return res;
    }
};