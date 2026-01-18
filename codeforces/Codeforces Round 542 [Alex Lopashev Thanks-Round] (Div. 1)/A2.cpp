#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,a,b,pos,menos[5000],tam[5000],mini;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)menos[i]=(i-1+n)%n;
    while(m--){
        cin >> a >> b;
        tam[--a]++;
        if((((--b)-a+n)%n)<((menos[a]-a+n)%n))menos[a]=b;
    }
    for(int i=0;i<n;i++){
        mini=0;
        if(tam[i])mini=max(mini,n*(int)(tam[i]-1)+(menos[i]-i+n)%n);
        for(int j=(i+1)%n;j!=i;j=(j+1)%n)if(tam[j])mini=max(mini,((j-i+n)%n)+n*(int)(tam[j]-1)+(menos[j]-j+n)%n);
        cout << mini << ' ';
    }
}