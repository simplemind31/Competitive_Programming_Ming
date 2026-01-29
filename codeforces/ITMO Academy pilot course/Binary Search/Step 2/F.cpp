#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l,r;
string s,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> t;
    n=s.size();
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }
    r=n-t.size();
    while(l<r){
        int mid=(l+r+1)>>1;
        vector<bool> prohi(n);
        string nue="";
        for(int i=0;i<mid;i++){
            prohi[a[i]]=true;
        }
        for(int i=0;i<n;i++){
            if(!prohi[i])nue.push_back(s[i]);
        }
        //existe t en nue?
        int j=0;
        for(int i=0;i<nue.size() && j<t.size();i++){
            if(nue[i]==t[j])j++;
        }
        if(j==t.size())l=mid;
        else r=mid-1;
    }
    cout << l;
}