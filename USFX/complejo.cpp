#include <bits/stdc++.h>
using namespace std;
pair<double,double> sumar(pair<double,double> x,pair<double,double> y){
    return {x.first+y.first,x.second+y.second};
}
pair<double,double> restar(pair<double,double> x,pair<double,double> y){
    return {x.first-y.first,x.second-y.second};
}
pair<double,double> multiplicar(pair<double,double> x,pair<double,double> y){
    return {x.first*y.first-x.second*y.second,x.first*y.second+y.first*x.second};
}
pair<double,double> dividir(pair<double,double> x,pair<double,double> y){
    return {(x.first*y.first+x.second*y.second)/(y.first*y.first+y.second*y.second),(x.second*y.first-x.first*y.second)/(y.first*y.first+y.second*y.second)};
}
pair<double,double> conjugada(pair<double,double> x){
    return {x.first,-x.second};
}
double abs(pair<double,double> x){
    return x.first*x.first+x.second*x.second;
}
void imprimir(pair<double,double> x){
    cout << fixed << setprecision(2) << x.first;
    if(x.second<0){
        cout << "-" << -x.second << "i\n";
    }else{
        cout << "+" << x.second << "i\n";
    }
}
int main(){
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    pair<double,double> z1={a,b},z2={c,d};
    //imprimir(sumar(z1,z2));
    //imprimir(restar(z1,z2));
    //imprimir(multiplicar(z1,z2));
    //imprimir(dividir(z1,z2));
    imprimir(conjugada(z1));
    cout << abs(z13);
}