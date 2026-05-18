#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //x->a-x->a-(a-x)=x;
    cin >> n >> a >> b;
    int p[n],res[n];
    memset(res,-1,sizeof(res));
    map<int,int> con;
    for(int i=0;i<n;i++){
        cin >> p[i];
        con[p[i]]=i;
    }
    // que pasa si existe a-p[i] y existe b-p[i]?
    for(int i=0;i<n;i++){
        if(!con.count(a-p[i]) && !con.count(b-p[i])){
            cout << "NO";
            return 0;
        }
        if(con.count(a-p[i]) && con.count(b-p[i]))continue;
        if(con.count(a-p[i]))res[i]=0;
        else res[i]=1;
    }
    for(int i=0;i<n;i++){
        if(res[i]!=-1)continue;
        if(res[con[a-p[i]]]==0)res[i]=res[con[a-p[i]]];
        else if(res[con[b-p[i]]]==1)res[i]=res[con[b-p[i]]];
        else res[i]=0;
    }
    cout << "YES\n";
    for(int i=0;i<n;i++)cout << res[i] << ' ';
    cout << con[a-69962];
}