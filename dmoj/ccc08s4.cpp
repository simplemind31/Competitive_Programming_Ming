#include <bits/stdc++.h>
using namespace std;
int n,maxi,card[4],val;
bool xd=true;
vector<vector<int>> posi;
int calc(int a,int b,int c){
    if(c==0)return a+b;
    if(c==1)return a-b;
    if(c==2)return a*b;
    if(b==0){
        xd=false;
        return 0;
    }
    if(a%b)xd=false;
    return a/b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                posi.push_back({i,j,k});
            }
        }
    }
    //(((a,b),c),d)
    //
    while(n--){
        maxi=0;
        for(int i=0;i<4;i++)cin >> card[i];
        sort(card,card+4);
        do{
            for(int i=0;i<posi.size();i++){
                xd=true;
                val=calc(calc(calc(card[0],card[1],posi[i][0]),card[2],posi[i][1]),card[3],posi[i][2]);
                if(xd && val<=24)maxi=max(maxi,val);
                xd=true;
                val=calc(calc(card[0],card[1],posi[i][0]),calc(card[2],card[3],posi[i][2]),posi[i][1]);
                if(xd && val<=24)maxi=max(maxi,val);
                xd=true;
                val=calc(calc(card[0],calc(card[1],card[2],posi[i][1]),posi[i][0]),card[3],posi[i][2]);
                if(xd && val<=24)maxi=max(maxi,val);
                xd=true;
                val=calc(card[0],calc(calc(card[1],card[2],posi[i][1]),card[3],posi[i][2]),posi[i][0]);
                if(xd && val<=24)maxi=max(maxi,val);
                xd=true;
                val=calc(card[0],calc(card[1],calc(card[2],card[3],posi[i][2]),posi[i][1]),posi[i][0]);
                if(xd && val<=24)maxi=max(maxi,val);
            }
        }while(next_permutation(card,card+4));
        cout << maxi << '\n';
    }
}