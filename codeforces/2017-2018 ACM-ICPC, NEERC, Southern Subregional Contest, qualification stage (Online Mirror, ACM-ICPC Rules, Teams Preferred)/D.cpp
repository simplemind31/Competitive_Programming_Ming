#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,T,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> T;
    T--;
    pair<int,int> ord[n];
    int t[n];
    for(int i=0;i<n;i++){
        cin >> t[i];
        t[i]-=i+1;
        t[i]=max(t[i],0);
        ord[i]={t[i],i};
    }
    sort(ord,ord+n);
    // si espero i segundos, puedo elegir los que tienen <=i dentro del pos 0 al T-i-1
    // 0 segundos, <=0 dentro de pos 0 al T-1
    // 1 segundos, <=1 dentro de pos 0 al T-2
    // 2 segundos <=2 dentro de pos0 al T-3
    // para la transition del T-i-1 al T-i-2, eliminar T-i-1 y sumar los que son i+1
    int can=0,poin=0;
    int espero=ord[0].first;
    for(int i=0;i<=T-espero-1 && i<n;i++){
        can+=t[i]<=espero;
    }
    while(poin<n && ord[poin].first<=espero)poin++;
    maxi=can;
    int last=min(T-espero-1,n);
    for(int i=1;i<n;i++){
        // ahora esperar ord[i].first
        int nueespero=ord[i].first;
        // quitar
        while(last>T-nueespero-1){
            if(last<n && last>=0){
                can-=t[last]<=espero;
            }
            last=min(last-1,n);
        }
        //añadir
        while(poin<n){
            if(ord[poin].first<=nueespero){
                if(ord[poin].second<=last)can++;
                poin++;
            }else break;
        }
        maxi=max(maxi,can);
        espero=nueespero;
    }
    cout << maxi;
}// 0,3,0