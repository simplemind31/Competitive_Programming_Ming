#include <bits/stdc++.h>
using namespace std;
string ans;
vector<int> solve(int l,int r){
    if(l==r)return {l};
    int mid=(l+r)>>1;
    vector<int> iz=solve(l,mid),de=solve(mid+1,r),res;
    int n=iz.size(),m=de.size(),i=0,j=0;
    while(i<n && j<m){
        cout << "? " << iz[i] << ' ' << de[j] << '\n';
        cout.flush();
        cin >> ans;
        if(ans=="YES")res.push_back(iz[i++]);
        else res.push_back(de[j++]);
    }
    while(i<n)res.push_back(iz[i++]);
    while(j<m)res.push_back(de[j++]);
    return res;
}
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> orden=solve(1,n),res(n);
    for(int i=0;i<n;i++)res[orden[i]-1]=i+1;
    cout << "! ";
    for(int i=0;i<n;i++)cout << res[i] << ' ';
    cout.flush();
}