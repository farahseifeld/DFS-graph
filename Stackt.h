#pragma once

#ifndef STACKT_H
#define STACKT_H

template <class type>

class Stackt {

private:
	type *stack;
	int maxsize;
	int top;

public:

	Stackt(int size = 200);
	Stackt(const Stackt <type> &);
	~Stackt();

	void push(type);
	void pop(type &);
	void seeTop(type &) const;
	bool stackempty()const;
	bool stackfull() const;


};

#endif 
#include "stackt.cpp"