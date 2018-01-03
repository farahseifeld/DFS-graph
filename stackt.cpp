
#include <iostream>
using namespace std;

template <class type>
Stackt<type>:: Stackt(int size) {
	maxsize = size;
	stack = new type[maxsize];
	top = -1;
}


template <class type>
Stackt<type>:: Stackt(const Stackt <type> &orginal) {
	maxsize = original.maxsize;
	top = original.top;

	int k = 0;
	while (k <= top) {
		stack[k] = original.stack[k];
		k++;
	}
}

template <class type>
Stackt<type>:: ~Stackt() {
	delete[] stack;
}

template <class type>
void Stackt<type>:: push(type e) {

	if (!stackfull()) {
		top++;
		stack[top] = e;
	}
	else cout << "Stack Overflow" << endl;
}

template <class type>
void Stackt<type>:: pop(type &e) {
	if(!stackempty()){
		e = stack[top];
		top--;
	}
	else cout << "Stack Underflow" << endl;
}

template <class type>
void Stackt<type>:: seeTop(type &e) const {
	if (!stackempty()) 
		e = stack[top];
	else cout << "Stack is Empty. No top to see." << endl;
}

template <class type>
bool Stackt<type>::stackempty()const {
	return top == -1;

}

template <class type>
bool Stackt<type>::stackfull() const {
	return top == maxsize-1;
}