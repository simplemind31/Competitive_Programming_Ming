#include <iostream>
using namespace std;

void change(int arr[3]) {
    arr[0]=100; // modifies original array
}

int main() {
    int a[3] = {1, 2, 3};
    change(a);
    cout << a[0]; // prints 100
}