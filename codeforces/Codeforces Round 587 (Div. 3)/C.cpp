#include <bits/stdc++.h>
using namespace std;
int pap[3][4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<3;i++)for(int j=0;j<4;j++)cin >> pap[i][j];
    for(int i=1;i<=2;i++){
        if(pap[i][0]<=pap[0][0] && pap[0][2]<=pap[i][2] && pap[i][1]<=pap[0][1] && pap[0][3]<=pap[i][3]){
            cout << "NO";
            return 0;
        }else if(pap[i][0]<=pap[0][0] && pap[0][2]<=pap[i][2]){
            if(pap[i][1]<=pap[0][1] && pap[0][1]<=pap[i][3]){
                pap[0][1]=pap[i][3];
            }else if(pap[i][1]<=pap[0][3] && pap[0][3]<=pap[i][3]){
                pap[0][3]=pap[i][1];
            }
        }else if(pap[i][1]<=pap[0][1] && pap[0][3]<=pap[i][3]){
            if(pap[i][0]<=pap[0][0] && pap[0][0]<=pap[i][2]){
                pap[0][0]=pap[i][2];
            }else if(pap[i][0]<=pap[0][2] && pap[0][2]<=pap[i][2]){
                pap[0][2]=pap[i][0];
            }
        }
    }
    cout << "YES";
}