#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int MAXN=1000000;
int n,a,k,mini=MAXN;
bool existe[MAXN];
int dist(int a,int b){
    if(a>b)swap(a,b);
    return min(b-a,a+MAXN-b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        mini=min(mini,a);
        existe[a]=true;
    }
    cin >> k;
    int l=0,r=MAXN;
    while(l<r){
        int mid=(l+r)>>1;
        // siempre a drecha
        vector<int> usado;
        usado.push_back((mini+mid)%MAXN);
        for(int i=0;i<MAXN;i++){
            if(existe[i]){
                if(dist(usado.back(),i)<=mid || dist(usado[0],i)<=mid)continue;
                usado.push_back((i+mid)%MAXN);
            }
        }
        if(usado.size()<=k){
            r=mid;
            continue;
        }
        // ir siempre a la derecha
        usado.clear();
        usado.push_back((mini-mid+MAXN)%MAXN);
        for(int i=MAXN-1;i>=0;i--){
            if(existe[i]){
                if(dist(usado.back(),i)<=mid || dist(usado[0],i)<=mid)continue;
                usado.push_back((i-mid+MAXN)%MAXN);
            }
        }
        if(usado.size()<=k)r=mid;
        else l=mid+1;
    }
    cout << l;
}