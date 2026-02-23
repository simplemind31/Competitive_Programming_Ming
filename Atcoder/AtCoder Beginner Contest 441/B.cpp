#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,m;
char c;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<bool> ahikst(26),aikot(26);
    while(n--){
        cin >> c;
        ahikst[c-'a']=true;
    }
    while(m--){
        cin >> c;
        aikot[c-'a']=true;
    }
    cin >> n;
    while(n--){
        cin  >> st;
        bool xd1=true,xd2=true;
        for(int i=0;i<st.size();i++){
            if(!ahikst[st[i]-'a'])xd1=false;
            if(!aikot[st[i]-'a'])xd2=false;
        }
        if(xd1==xd2)cout << "Unknown\n";
        else if(xd1)cout << "Takahashi\n";
        else cout << "Aoki\n";
    }
}