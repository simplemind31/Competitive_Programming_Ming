#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n,con;
ld L;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> L;
    pair<ld,ld> point[n];
    for(int i=0;i<n;i++)cin >> point[i].first >> point[i].second;
    ld l=0,r=1e9;
    while(con++<60){
        ld mid=(l+r)/2,last=0;
        for(int i=0;i<n;i++){
            if(mid<abs(point[i].second))continue;
            ld dist=sqrtl(mid*mid-point[i].second*point[i].second);
            if(point[i].first-dist<=last)last=max(last,point[i].first+dist);
        }
        if(last>=L)r=mid;
        else l=mid;
    }
    cout << fixed << setprecision(4) << l;
}