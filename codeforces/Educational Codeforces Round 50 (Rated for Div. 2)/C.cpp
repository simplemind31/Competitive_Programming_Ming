#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a,b,power[5][20],facto[10],combi[20][20];
ll calc(vector<int>& digit,string& st,int pos,int usado){
    if(pos==st.size())return 1;
    ll can=0;
    for(int i=0;i<digit.size();i++){
        if(digit[i]>st[pos]-'0')continue;
        else if(digit[i]==st[pos]-'0')can+=calc(digit,st,pos+1,usado|(1<<i));
        else{
            // algunos solo usaron menos digitos
            // tengo que usar si o si todos;
            int temp=st.size()-pos-1,con=0;
            for(int j=0;j<digit.size();j++)if(!(usado&(1<<j)))con++;
            //hay power[digit.size()] posibilidades, pero tengo que usar si o si con
            can+=power[digit.size()][temp]-power[digit.size()-con][temp];
        }
    }
    return can;
}
ll solve(string x){
    ll can=0;
    // usar si o si 4
    for(int j=1;j<10;j++){
        for(int k=j+1;k<10;k++){
            for(int l=k+1;l<10;l++){
                vector<int> di={0,j,k,l};
                can+=calc(di,x,0,0);
            }
        }
    }
    //usar si o si 3
    for(int j=0;j<10;j++){
        for(int k=j+1;k<10;k++){
            for(int l=k+1;l<10;l++){
                vector<int> di={j,k,l};
                can+=calc(di,x,0,0);
            }
        }
    }
    // usar si o si 2
    for(int j=0;j<10;j++){
        for(int k=j+1;k<10;k++){
            vector<int> di={j,k};
            can+=calc(di,x,0,0);
        }
    }
    // usar si o si 1
    for(int j=0;j<10;j++){
        vector<int> di={j};
        can+=calc(di,x,0,0);
    }
    return can;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    facto[0]=1;
    for(int i=1;i<=10;i++)facto[i]=facto[i-1]*i;
    for(int i=0;i<20;i++){
        combi[i][i]=1;
        for(int j=1;j<i;j++){
            combi[i][j]=combi[i-1][j]+combi[i-1][j-1];
        }
    }
    for(int i=0;i<=4;i++)power[i][0]=1;
    for(int j=2;j<=4;j++){
        for(int i=1;i<20;i++)power[j][i]=power[j][i-1]*j;
    }
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << solve(to_string(b)) << ' ';
        cout << solve(to_string(b))-solve(to_string(a-1)) << '\n';
    }
}