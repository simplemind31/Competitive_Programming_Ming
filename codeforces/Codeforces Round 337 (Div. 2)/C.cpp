#include <bits/stdc++.h>
using namespace std;
int lim,con=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> lim;
    vector<bitset<1024>> res[lim+1];
    res[0].push_back(0);
    for(int i=1;i<=lim;i++){
        for(int j=0;j<con;j++){
            for(int k=con;k<2*con;k++){
                res[i-1][j][k]=res[i-1][j][k-con];
            }
        }
        for(int j=0;j<con;j++){
            res[i].push_back(res[i-1][j]);
        }
        for(int j=0;j<con;j++){
            res[i].push_back(res[i-1][j]);
        }
        for(int j=con;j<2*con;j++){
            for(int k=con;k<2*con;k++){
                res[i][j][k]=1-res[i][j][k];
            }
        }
        con*=2;
    }
    for(int i=0;i<con;i++){
        for(int j=0;j<con;j++){
            if(res[lim][i][j])cout << '*';
            else cout << '+';
        }
        cout << endl;
    }
}
/*
0
0
1
00
01
2
0000
0101
0000
0101
3
0000
0101
0011
0110
*/