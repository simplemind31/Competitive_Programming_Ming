#include <vector>
#include <iostream>
using namespace std;
int main(){
    string a="abcde";
    a.push_back('X');
    cout << a << endl;
    a.pop_back();
    cout << a << endl;
    cout << a.size();
}
