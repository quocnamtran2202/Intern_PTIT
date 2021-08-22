#include<iostream>
using namespace std;

void reference_swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void pointer_swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a, b;
	cout << "Nhap a:";
	cin >> a;
	cout << "\nNhap b:";
	cin >> b;
	cout << "\nBan da nhap:               a = " << a << "      " << "b = " << b << "\n";
	
	//Tham chieu
	reference_swap(a, b);
	cout << "\nHoan vi truyen tham chieu: a = " << a << "      " << "b = " << b << "\n";
	reference_swap(a, b);
	
	//Con tro
	pointer_swap(&a, &b);
	cout << "\nHoan vi truyen con tro:    a = " << a << "      " << "b = " << b << "\n";
	
	return 0;
}