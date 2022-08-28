#include <vector>
#include <iostream>
#include <string>
#include "cow.h"
#include "records.h"

using namespace std;

int a = 37;
int *ptr;
cow *my_cow;
vector<int> primes;
Student my_student(1,"Hilda Jones");
Course my_course(7,"Physics 101",4);
Grade my_grade(1,7,'B');

void initialize();
StudentRecords SR;
int id;

int square(int x) {
  x = x * x;
  return x;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

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
    cout << "The vector has " << primes.size() << " elements." << endl;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(4);
    primes.push_back(5);
    primes.push_back(7);
    cout << "The vector has " << primes.size() << " elements." << endl;
    cout << "The element at index 2 is " << primes[2] << endl;
    primes[2] = 13;
    cout << "The element at index 2 is " << primes[2] << endl;
    vector<cow> cattle;
    cattle.push_back(cow("better", 6, meat));
    cattle.push_back(cow("Libby", 4, pet));
    cattle.push_back(cow("Trudy", 5, dairy));
    cout << "The first cow is " << cattle.begin()->get_name() << endl;
    cout << "At index 1 we have " << cattle[1].get_name() << endl;
    cout << "Next to last is " << prev(cattle.end(), 2)->get_name() << endl;
    cout << "the last cow is " << (cattle.end() - 1)->get_name() << endl;
    cout << "Student: " << my_student.get_name() << endl;
    cout << "Course: " << my_course.get_name() << endl;
    cout << "Credits: " << my_course.get_credits() << endl;
    cout << "Grade: " << my_grade.get_grade() << endl;
    
    //chapter 4
    //chapter 5
    initialize();
    cout << "Enter a student ID: ";
    cin >> id;
    SR.report_card(id);
    
    // swap
    int a = 9, b;
    b = square(a);
    cout << "a = " << a << ", b = " << b << endl;
    swap(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    return (0);
}

void initialize() {
  SR.add_student(1, "George P. Burdell");
  SR.add_student(2, "Nancy, Rhodes");

  SR.add_course(1, "Algebra", 5);
  SR.add_course(2, "Physics", 4);
  SR.add_course(3, "English", 3);
  SR.add_course(4, "Economics", 4);

  SR.add_grade(1,1,'B');
  SR.add_grade(1,2,'A');
  SR.add_grade(1,3,'C');
  SR.add_grade(2,1,'A');
  SR.add_grade(2,2,'A');
  SR.add_grade(2,4,'B');
}