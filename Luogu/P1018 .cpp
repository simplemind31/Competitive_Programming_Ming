#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m;
string numero;
string operator +(string a,string b){
    if(a.size()>b.size()){
        swap(a,b);
    }
    reverse(ALL(a));
    reverse(ALL(b));
    while(a.size()<b.size()){
        a.push_back('0');
    }
    string res=a;
    int sobra=0;
    for(int i=0;i<a.size();i++){
        int now=a[i]-'0'+b[i]-'0'+sobra;
        res[i]=now%10+'0';
        sobra=now/10;
    }
    if(sobra){
        res.push_back('1');
    }
    while(!res.empty()){
        if(res.back()=='0'){
            res.pop_back();
        }else{
            break;
        }
    }
    if(res.empty()){
        res="0";
    }
    reverse(ALL(res));
    return res;
}
string operator *(string a,char c){
    string res="0";
    for(int i=0;i<c-'0';i++){
        res=res+a;
    }
    reverse(ALL(res));
    while(!res.empty()){
        if(res.back()=='0'){
            res.pop_back();
        }else{
            break;
        }
    }
    if(res.empty()){
        res="0";
    }
    reverse(ALL(res));
    return res;
}
string operator *(string a,string b){
    string res="0";
    string atras="";
    for(int i=b.size()-1;i>=0;i--){
        string temp=a*b[i];
        temp+=atras;
        atras.push_back('0');
        res=res+temp;
    }
    reverse(ALL(res));
    while(!res.empty()){
        if(res.back()=='0'){
            res.pop_back();
        }else{
            break;
        }
    }
    if(res.empty()){
        res="0";
    }
    reverse(ALL(res));
    return res;
}
string maximo(string a,string b){
    if(a.size()>b.size()){
        return a;
    }else if(b.size()>a.size()){
        return b;
    }else{
        return max(a,b);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string dp[40][7];
    for(int i=0;i<40;i++){
        for(int j=0;j<7;j++){
            dp[i][j]="0";
        }
    }
    cin >> n >> m >> numero;
    string temp="";
    for(int i=0;i<n;i++){
        temp.push_back(numero[i]);
        dp[i][0]=temp;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<i;k++){
                //dp[k][j-1]*string(k+1,i);
                temp.clear();
                for(int l=k+1;l<=i;l++){
                    temp.push_back(numero[l]);
                }
                dp[i][j]=maximo(dp[i][j],dp[k][j-1]*temp);
            }
        }
    }
    cout << dp[n-1][m];
}