#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,pad[100001],tam[100001];
ll res[100001],fin;
int find(int a){return (a==pad[a])?a:pad[a]=find(pad[a]);}
void unite(int a,int b){
    if((a=find(a))==(b=find(b)))return;
    if(tam[b]>tam[a])swap(a,b);
    res[a]+=res[b];
    tam[a]+=tam[b];
    pad[b]=a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=2;i<=n;i++){
        tam[i]=1;
        for(int j=2;j*j<=i;j++){
            if(i%j)continue;
            if(j*j==i){
                unite(i,j);
                res[find(i)]+=j;
            }else{
                unite(i,j);
                unite(i,i/j);
                res[find(i)]+=j+i/j;
            }
        }
        fin=max(fin,res[find(i)]);
    }
    cout << 4*fin;
}
//6->3->(-6)->(-3)->6->(2->4->(-2)->(-4)->2)->(-6)->(-2)->(6)