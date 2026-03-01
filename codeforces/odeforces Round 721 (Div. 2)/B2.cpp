#include <bits/stdc++.h>
using namespace std;
int t;
// alice-bob
//<0 alice wins, minimiza
//>0 bob wins,maximiza
//draw
int res[2][2][2][1001][1001];
int seen[2][2][2][1001][1001];
int stamp=1;
int solve(bool Alice,bool mid,bool siosi,int con0,int con1){
    if(con0==0 && con1==0 && mid==0)return res[Alice][mid][siosi][con0][con1]=0;
    if(seen[Alice][mid][siosi][con0][con1]==stamp)return res[Alice][mid][siosi][con0][con1];
    if(Alice){
        res[Alice][mid][siosi][con0][con1]=1e9;
        // completar 01
        if(con1)res[Alice][mid][siosi][con0][con1]=min(res[Alice][mid][siosi][con0][con1],1+solve(!Alice,mid,false,con0,con1-1));
        // completar 00
        if(con0)res[Alice][mid][siosi][con0][con1]=min(res[Alice][mid][siosi][con0][con1],1+solve(!Alice,mid,false,con0-1,con1+1));
        //completar mid
        if(mid)res[Alice][mid][siosi][con0][con1]=min(res[Alice][mid][siosi][con0][con1],1+solve(!Alice,!mid,false,con0,con1));
        if(res[Alice][mid][!siosi][con0][con1]==1e9)res[Alice][mid][!siosi][con0][con1]=res[Alice][mid][!siosi][con0][con1];
        //no hacer nada
        if(!siosi && con1)res[Alice][mid][siosi][con0][con1]=min(res[Alice][mid][siosi][con0][con1],solve(!Alice,mid,true,con0,con1));
    }else{
        res[Alice][mid][siosi][con0][con1]=-1e9;
        // completar 01
        if(con1)res[Alice][mid][siosi][con0][con1]=max(res[Alice][mid][siosi][con0][con1],-1+solve(!Alice,mid,false,con0,con1-1));
        // completar 00
        if(con0)res[Alice][mid][siosi][con0][con1]=max(res[Alice][mid][siosi][con0][con1],-1+solve(!Alice,mid,false,con0-1,con1+1));
        //completar mid
        if(mid)res[Alice][mid][siosi][con0][con1]=max(res[Alice][mid][siosi][con0][con1],-1+solve(!Alice,!mid,false,con0,con1));
        if(res[Alice][mid][!siosi][con0][con1]==1e9)res[Alice][mid][!siosi][con0][con1]=res[Alice][mid][!siosi][con0][con1];
        //no hacer nada
        if(!siosi && con1)res[Alice][mid][siosi][con0][con1]=max(res[Alice][mid][siosi][con0][con1],solve(!Alice,mid,true,con0,con1));
    }
    if(seen[Alice][mid][!siosi][con0][con1]!=stamp)seen[Alice][mid][siosi][con0][con1]!=stamp;
    seen[Alice][mid][siosi][con0][con1]=stamp;
    return res[Alice][mid][siosi][con0][con1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int ii=0;ii<=1000;ii++){
                    for(int jj=0;jj<=1000;jj++){
                        solve(i,j,k,ii,jj);
                    }
                }
            }
        }
    }
    cin >> t;
    while(t--){
        int n;
        string st;
        cin >> n >> st;
        int con0=0,con1=0;
        for(int i=0;i<n/2;i++){
            if(st[i]==st[n-i-1] && st[i]=='0')con0++;
            else if(st[i]!=st[n-i-1])con1++;
        }
        int val=solve(true,(n&1)&&(st[n/2]=='0'),false,con0,con1);
        if(val<0)cout << "ALICE\n";
        else if(val==0)cout << "DRAW\n";
        else cout << "BOB\n";
    }
}