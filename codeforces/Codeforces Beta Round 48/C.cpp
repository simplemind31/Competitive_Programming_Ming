#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    long double house[n];
    for(int i=0;i<n;i++)cin >> house[i];
    sort(house,house+n);
    long double l=0,r=(1e9)/6;
    while(abs(l-r)>=1e-6){
        long double mid=(l+r)/2;
        int con=0;
        long double last=-1e9;
        for(int i=0;i<n && con<=3;i++){
            if(house[i]>last+mid){
                con++;
                last=house[i]+mid;
            }
        }
        if(con>3)l=mid;
        else r=mid;
    }
    l=r;
    cout << fixed << setprecision(6);
    cout << l << '\n';
    int con=0;
    long double last=-1e9;
    for(int i=0;i<n && con<3;i++){
        if(house[i]>(last+l)){
            last=house[i]+l;
            con++;
            cout << last << ' ';
        }
    }
    while(con++<3){
        cout << last << ' ';
    }
}