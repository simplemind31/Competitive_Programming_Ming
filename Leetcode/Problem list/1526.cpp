#include <bits/stdc++.h>
using namespace std;
int n,con;
class Solution {
public:
    int minNumberOperations(vector<int>& target){
        n=target.size();
        con=target[0];
        for(int i=1;i<n;i++){
            if(target[i]-target[i-1]>0){
                con+=target[i]-target[i-1];
            }
        }
        return con;
    }
};