#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size(),m=boxGrid[0].size();
        vector res(m,vector<char>(n));
        for(int i=0;i<n;i++){
            int last=m;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j]=='*')last=j;
                else if(boxGrid[i][j]=='#'){
                    boxGrid[i][j]='.';
                    last--;
                    boxGrid[i][last]='#';
                    res[last][n-i-1]=boxGrid[i][last];
                    while(last>j && boxGrid[i][last-1]!='.')last--;
                }
                res[j][n-i-1]=boxGrid[i][j];
            }
        }
        return res;
    }
};