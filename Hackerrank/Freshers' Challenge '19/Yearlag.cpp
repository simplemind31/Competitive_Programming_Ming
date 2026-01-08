#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d >> e;
    cout << ((((a<40)+(b<40)+(c<40)+(d<40)+(e<40))>2)?"YEARLAG":"CAZZ");
}