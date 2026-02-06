#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
float m,h;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> h;
    if(m/(h*h)<18.5)cout << "Underweight";
    else if(m/(h*h)<24)cout << "Normal";
    else cout << m/(h*h) << "\nOverweight";
}