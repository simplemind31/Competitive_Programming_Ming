#include <bits/stdc++.h>
using namespace std;
int n,a;
vector<int> grup[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    // cantidad de x+1 cows
    for(int i=0;i<n;i++){
        cin >> a;
        grup[--a].push_back(i);
    }
}