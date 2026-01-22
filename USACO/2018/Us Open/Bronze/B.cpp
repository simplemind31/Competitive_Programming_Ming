#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie();
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    cin >> n >> m >> k;
    vector<int> ord;
    vector<int> pos(n,-1);
    vector<int> usado(n,-1);
    int te=m;
    for(int i=0;i<te;i++){
        cin >> a;
        if(i<m){
            ord.push_back(--a);
            if(a==0)m=i+1;
        }
    }
    while(k--){
        cin >> a >> b;
        pos[--b]=--a;
        if(a==0){
            cout << b+1;
            return 0;
        }
        usado[a]=b;
    }
    if(ord.back()==0){
        //poner lo mas antes posible
        int j=0,i=0;
        for(;j<m;){
            while(j<m && usado[ord[j]]!=-1){
                i=usado[ord[j]]+1;
                j++;
            }
            if(j==m)break;
            while(pos[i]!=-1)i++;
            usado[ord[j]]=i;
        }
        cout << usado[0]+1;
        return 0;
    }
    //poner lo más atras
    int j=m-1,i=n-1;
    for(;j>=0;){
        while(j>=0 && usado[ord[j]]!=-1){
            i=usado[ord[j]]-1;
            j--;
        }
        if(j==-1)break;
        while(pos[i]!=-1)i--;
        pos[i]=j;
        usado[ord[j]]=i;
    }
    for(int i=0;i<n;i++){
        if(pos[i]==-1){
            cout << i+1;
            return 0;
        }
    }
}