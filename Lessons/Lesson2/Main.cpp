#include<iostream>
using namespace std;

long double factorial(int n) {
    int i;
    long double f = 1;
    if (n == 0 || n == 1) {
        return f;
    }
    else {
        for (i = 2; i <= n; i++) {
            f *= i;
        }
        return f;
    }
}

int main(){
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    while (cin.fail() || n < 0) {
        cout << "\nWrong format. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> n;
    }
    cout << "\n" << n << "! = " << factorial(n) << "\n";
    return 0;
}
