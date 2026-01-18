#include <bits/stdc++.h>
using namespace std;
int n,con[2][2],res[2][2]={{-1,-1},{-1,-1}};
string c,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> c >> s;
    for(int i=0;i<n;i++)con[c[i]-'0'][s[i]-'0']++;
    for(int i=0;i<=con[0][1] && res[0][0]==-1;i++){
        for(int j=0;j<=con[1][0] && res[0][0]==-1;j++){
            // j perform clown
            int pe1=j,used1=i+j;
            int use11=0,use00=0,cop00=con[0][0],cop11=con[1][1];
            int pe2=con[0][1]-i,used2=con[1][0]+con[0][1]-i-j;
            // make them equal
            int need=abs(pe2-pe1);
            if(cop11<need)continue;
            if(pe1<=pe2){
                pe1+=need;
                used1+=need;
                use11+=need;
            }else{
                pe2+=need;
                used2+=need;
            }
            cop11-=need;
            if(cop11&1)continue;
            need=abs(used1-used2);
            if(cop00<need)continue;
            if(used1<=used2){
                used1+=need;
                use00+=need;
            }else{
                used2+=need;
            }
            cop00-=need;
            if(cop00&1)continue;
            res[0][0]=use00+cop00/2;
            res[1][1]=use11+cop11/2;
            res[0][1]=i;
            res[1][0]=j;
        }
    }
    if(res[0][0]==-1){
        cout << -1;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(res[c[i]-'0'][s[i]-'0']){
            cout << i+1 << ' ';
            res[c[i]-'0'][s[i]-'0']--;
        }
    }
}