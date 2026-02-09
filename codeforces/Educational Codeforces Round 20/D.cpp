#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,con,maxi;
string st;
vector<int> words;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k;
    cin.ignore();
    getline(cin,st);
    for(int i=0;i<st.size();i++){
        con++;
        if(st[i]==' ' ||st[i]=='-'){
            maxi=max(maxi,con);
            words.push_back(con);
            con=0;
        }
    }
    maxi=max(maxi,con);
    words.push_back(con);
    int l=maxi,r=st.size();
    int n=words.size();
    while(l<r){
        int mid=(l+r)>>1;
        int cantiline=1,now=0;
        for(int i=0;i<n && cantiline<=k;i++){
            if(now+words[i]<=mid)now+=words[i];
            else{
                cantiline++;
                now=words[i];
            }
        }
        if(cantiline<=k)r=mid;
        else l=mid+1;
    }
    cout << l;
}