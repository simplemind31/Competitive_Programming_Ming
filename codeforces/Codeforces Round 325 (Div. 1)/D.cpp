#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n[2];
ll maxi=-2e18;
vector<vector<ll>> nums[2];
unordered_map<ll,ll> posi;
ll a1,a2,b1,c1;
void solve(ll a,ll b,ll c,bool ve,int pos){
    if(pos==n[ve]){
        b-=a;
        c-=a;
        if(!ve){
            if(posi.count(b*1e8+c))posi[b*1e8+c]=max(posi[b*1e8+c],a);
            else posi[b*1e8+c]=a;
        }else{
            if(!posi.count(-b*1e8-c))return;
            if(posi[-b*1e8-c]+a>maxi){
                maxi=posi[-b*1e8-c]+a;
                a1=posi[-b*1e8-c];
                a2=a;
                b1=-b,c1=-c;
            }
        }
        return;
    }
    solve(a+nums[ve][pos][0],b+nums[ve][pos][1],c,ve,pos+1);
    solve(a+nums[ve][pos][0],b,c+nums[ve][pos][2],ve,pos+1);
    solve(a,b+nums[ve][pos][1],c+nums[ve][pos][2],ve,pos+1);
}
vector<string> respuestas[2];
bool restaurar(ll a,ll b,ll c,ll ta,ll tb,ll tc,int pos, bool ve){
    if(pos==n[ve])return (a==ta && b==tb && c==tc);
    if(restaurar(a+nums[ve][pos][0],b+nums[ve][pos][1],c,ta,tb,tc,pos+1,ve)){
        respuestas[ve].push_back("LM");
        return true;
    }
    if(restaurar(a+nums[ve][pos][0],b,c+nums[ve][pos][2],ta,tb,tc,pos+1,ve)){
        respuestas[ve].push_back("LW");
        return true;
    }
    if(restaurar(a,b+nums[ve][pos][1],c+nums[ve][pos][2],ta,tb,tc,pos+1,ve)){
        respuestas[ve].push_back("MW");
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n[0];
    n[1]=n[0]/2;
    n[0]=n[0]-n[1];
    for(int j=0;j<2;j++){
        nums[j].assign(n[j],vector<ll>(3));
        for(int i=0;i<n[j];i++)cin >> nums[j][i][0] >> nums[j][i][1] >> nums[j][i][2];
        solve(0,0,0,j,0);
    }
    if(maxi==-2e18){
        cout << "Impossible";
        return 0;
    }
    restaurar(0,0,0,a1,b1+a1,c1+a1,0,0);
    restaurar(0,0,0,a2,-b1+a2,-c1+a2,0,1);
    for(int j=0;j<2;j++){
        reverse(ALL(respuestas[j]));
        for(auto u:respuestas[j])cout << u << '\n';
    }
}