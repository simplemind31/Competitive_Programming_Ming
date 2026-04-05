#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    switch(n){
        case 1:
        cout << "walk";
        break;
        case 2:
        cout << "no";
        break;
        case 3:
        cout << "no";
        break;
        case 4:
        cout << "no";
        break;
        case 5:
        cout << "yes";
        break;
        case 6:
        cout << "yes";
        break;
        case 7:
        cout << "backwards";
        break;
        default:
        cout << "seven";
    }
}