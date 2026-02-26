#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    /*
    if(a>b){
        if(a>c){
            cout << "a es mayor";
        }else{
            if(a<c){
                cout << "c es mayor";
            }else{
                cout << "a y c son mayores";
            }
        }
    }else if(a<b){
        if(b>c){
            cout << "b es mayor";
        }else{
            if(b<c){
                cout << "c es mayor";
            }else{
                cout << "b y c son mayores";
            }
        }
    }else{
        // b==a
        if(c>a){
            cout << "c es mayor";
        }else{
            if(c<a){
                cout << "a y b son mayores";
            }else{
                cout << "a, b y c son mayores";
            }
        }
    }*/
    if(a>b && a>c){
        cout << "a es mayor";
    }else{
        if(b>a && b>c){
            cout << "b es mayor";
        }else{
            if(c>a && c>b){
                cout << "c es mayor";
            }else{
                if(a>b){
                    cout << "a y c son mayores";
                }else{
                    if(a>c){
                        cout << "a y b son mayores";
                    }else{
                        if(b>a){
                            cout << "b y c son mayores";
                        }else{
                            cout << "a, b y c son mayores";
                        }
                    }
                }
            }
        }
    }

    if(a>b && a>c){
        cout << "a es mayor";
    }else if(b>a && b>c){
        cout << "b es mayor";
    }else if(c>a && c>b){
        cout << "c es mayor";
    }else if(a>b){
        cout << "a y c son mayores";
    }else if(a>c){
        cout << "a y b son mayores";
    }else if(b>a){
        cout << "b y c son mayores";
    }else{
        cout << "a, b y c son mayores";
    }
}