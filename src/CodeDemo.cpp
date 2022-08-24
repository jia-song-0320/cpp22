#include <iostream>
#include <string>
#include "cow.h"

using namespace std;

int a = 37;
int *ptr;
cow *my_cow;

int main(){
    ptr = &a;
    cout << "             The content of a is: " << a << endl;
    cout << "    ptr is pointing to addres is: " << ptr << endl;
    cout << "             The address of a is: " << &a << endl;
    cout << "  Where ptr is pointing, we have: " << *ptr << endl;
    cout << "           The address of ptr is: " << &ptr << endl;
    cout << endl;

    my_cow = new cow("HIldy",7,pet);
    cout << my_cow->get_age() << "; " << my_cow->get_name() << "; " << (int)my_cow->get_purpose() << endl;
    cout << &my_cow << endl;
    cout << typeid(ptr).name() << endl;
    cout << typeid(my_cow).name() << endl;
    delete my_cow;
    return (0);
}