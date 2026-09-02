#include <bits/stdc++.h>
using namespace std;
int age;
double weight,heart_rate,tiempo;
int main(){
    cin >> age >> weight >> heart_rate >> tiempo;
    cout << "Calories: " << fixed << setprecision(2) << (age*0.2757+weight*0.03295+heart_rate*1.0781-75.4991)*tiempo/8.368 << " calories";
}