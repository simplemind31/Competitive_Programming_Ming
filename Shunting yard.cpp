#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
    map<char,int> orden;
    orden['+']=0;
    orden['-']=0;
    orden['*']=1;
    orden['/']=1;
    orden['^']=2;
    orden['&']=-1;
    orden['|']=-2;
    orden['%']=1;
    cin >> str;
    string postfix;
    stack<char> cola;
    cola.push('(');
    for(int i=0;i<str.size();i++){
        if(('0'<=str[i] && str[i]<='9')||('a'<=str[i] && str[i]<='z')||('A'<=str[i] && str[i]<='Z')){
            postfix.push_back(str[i]);
        }else{
            if(str[i]=='(' || str[i]=='^'){
                cola.push(str[i]);
            }else if(str[i]==')'){
                while(cola.top()!='('){
                    postfix.push_back(cola.top());
                    cola.pop();
                }
                cola.pop();
            }else{
                while(cola.top()!='(' && orden[cola.top()]>=orden[str[i]]){
                    postfix.push_back(cola.top());
                    cola.pop();
                }
                cola.push(str[i]);
            }
        }
    }
    while(cola.top()!='('){
        postfix.push_back(cola.top());
        cola.pop();
    }
    cola.pop();
    cout << postfix;
}