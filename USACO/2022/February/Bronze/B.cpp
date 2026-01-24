#include <bits/stdc++.h>
using namespace std;
bool movee[100000];
int a[100000],b[100000],n,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        b[i]--;
    }
    int j=0;
    for(int i=0;i<n;i++){
        while(movee[a[j]])j++;
        if(a[j]==b[i]){
            j++;
            continue;
        }
        movee[b[i]]=true;
        res++;
    }
    cout << res;
}