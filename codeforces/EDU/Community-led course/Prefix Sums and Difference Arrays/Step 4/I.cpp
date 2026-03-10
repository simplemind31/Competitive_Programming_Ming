#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int m,q;
unsigned int a,b,cur,psum[(1<<24)+4],res;
unsigned int nextRand(){
    cur=cur*a+b;
    return cur>>8;
}
void add(){
    unsigned int adding=nextRand();
    unsigned int l=nextRand();
    unsigned int r=nextRand();
    if(l>r)swap(l,r);
    psum[l]+=adding;
    psum[r+1]-=adding;
}
unsigned int sum(){
    unsigned int l=nextRand();
    unsigned int r=nextRand();
    if(l>r)swap(l,r);
    if(l>0)return psum[r]-psum[l-1];
    return psum[r];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> q >> a >> b;
    while(m--)add();
    for(int i=1;i<((1<<24)+4);i++)psum[i]+=psum[i-1];
    for(int i=1;i<((1<<24)+4);i++)psum[i]+=psum[i-1];
    while(q--)res+=sum();
    cout << res;
}