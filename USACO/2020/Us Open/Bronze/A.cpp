#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f1=-1,l1=-1,p1,p2;
int maxi=1e9,posi;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("socdist1.in","r",stdin);
    freopen("socdist1.out","w",stdout);
    cin >> n;
    cin >> st;
    for(int i=0;i<n && f1==-1;i++)if(st[i]=='1')f1=i;
    for(int j=n-1;j>=0 && l1==-1;j--)if(st[j]=='1')l1=j;
    if(f1==-1){
        cout << n-1;
        return 0;
    }
    p1=f1;
    p2=n-l1-1;
    posi=max(min(p1,p2),max(p1,p2)/2);
    int con=0;
    vector<int> espa;
    for(int i=f1+1;i<=l1;i++){
        if(st[i]=='1'){
            maxi=min(maxi,con+1);
            if(con>0)espa.push_back(con);
            con=0;
        }else{
            con++;
        }
    }
    sort(espa.rbegin(),espa.rend());
    if(espa.empty()){
        cout << posi;
        return 0;
    }
    if(p2>p1)swap(p1,p2);
    //uno al p1 otro al espa[0];
    posi=max(posi,min(p1,(espa[0]+1)/2));
    //los dos al espa[0];
    posi=max(posi,(espa[0]+1)/3);
    if(espa.size()==1){
        maxi=min(maxi,posi);
        cout << maxi;
        return 0;
    }
    // uno al espa[0] otro al espa[1];
    posi=max(posi,(espa[1]+1)/2);
    maxi=min(maxi,posi);
    cout << maxi;
}