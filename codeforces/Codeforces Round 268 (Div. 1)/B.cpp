#include <bits/stdc++.h>
using namespace std;
int n,a,b;
struct DSU{
    vector<int> pad,tam;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        return true;
    }
    DSU(int x){
        pad.resize(x);
        tam=pad;
        for(int i=0;i<x;i++)tam[pad[i]]=i;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //x->a-x->a-(a-x)=x;
    cin >> n >> a >> b;
    bool izde[n][2];
    memset(izde,0,sizeof(izde));
    int p[n],res[n];
    memset(res,-1,sizeof(res));
    map<int,int> con;
    for(int i=0;i<n;i++){
        cin >> p[i];
        con[p[i]]=i;
    }
    // que pasa si existe a-p[i] y existe b-p[i]?
    queue<int> cadena;
    for(int i=0;i<n;i++){
        if(con.count(a-p[i]))izde[i][0]=true;
        if(con.count(b-p[i]))izde[i][1]=true;
        if(!con.count(a-p[i]) && !con.count(b-p[i])){
            cout << "NO";
            return 0;
        }
        if(izde[i][0]+izde[i][1]==0){
            cout << "NO";
            return 0;
        }else if(izde[i][0]+izde[i][1]==1){
            cadena.push(i);
        }
    }
    while(!cadena.empty()){
        int top=cadena.front();
        cadena.pop();
        if(izde[top][0]+izde[top][1]==0){
            cout << "NO";
            return 0;
        }
        if(izde[top][0]){
            // poner a a
            res[top]=0;
            // su complemento de b ya no puede usar b
            if(con.count(b-p[top])){
                if(res[con[b-p[top]]]==1){
                    cout << "NO";
                    return 0;
                }
                if(izde[con[b-p[top]]][1]){
                    izde[con[b-p[top]]][1]=false;
                    cadena.push(con[b-p[top]]);
                }
            }
            // el complemento de a ya no puede usar b
            if(!con.count(a-p[top])){
                cout << "NO";
                return 0;
            }
            if(res[con[a-p[top]]]==1){
                cout << "NO";
                return 0;
            }
            if(izde[con[a-p[top]]][1]){
                izde[con[a-p[top]]][1]=false;
                cadena.push(con[a-p[top]]);
            }
            // el complemento de b de su complemento de a  ya no puede usar b
            if(con.count(b-(a-p[top]))){
                if(res[con[b-(a-p[top])]]==1){
                    cout << "NO";
                    return 0;
                }
                if(izde[con[b-(a-p[top])]][1]){
                    izde[con[b-(a-p[top])]][1]=false;
                    cadena.push(con[b-(a-p[top])]);
                }
            }
        }else{
            // poner a b
            res[top]=1;
            // su complemento de a ya no puede usar a
            if(con.count(a-p[top])){
                if(res[con[a-p[top]]]==0){
                    cout << "NO";
                    return 0;
                }
                if(izde[con[a-p[top]]][0]){
                    izde[con[a-p[top]]][0]=false;
                    cadena.push(con[a-p[top]]);
                }
            }
            // el complemento de b ya no puede usar a
            if(!con.count(b-p[top])){
                cout << "NO";
                return 0;
            }
            if(res[con[b-p[top]]]==0){
                cout << "NO";
                return 0;
            }
            if(izde[con[b-p[top]]][0]){
                izde[con[b-p[top]]][0]=false;
                cadena.push(con[b-p[top]]);
            }
            // el complemento de a de su complemento de b ya no puede usar a
            if(con.count(a-(b-p[top]))){
                if(res[con[a-(b-p[top])]]==0){
                    cout << "NO";
                    return 0;
                }
                if(izde[con[a-(b-p[top])]][0]){
                    izde[con[a-(b-p[top])]][0]=false;
                    cadena.push(con[a-(b-p[top])]);
                }
            }
        }
    }
    cout << "YES\n";
    for(int i=0;i<n;i++){
        if(res[i]==-1){
            if(izde[i][0])res[i]=0;
            else res[i]=1;
        }
        cout << res[i] << ' ';
    }
}