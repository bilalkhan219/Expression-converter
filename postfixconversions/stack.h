#pragma once
#include "node.h"
#include"node.cpp"
#include <iostream>
using namespace std;
template <typename T>
class stack
{
	node<T>* top;
public:
	stack(node<T>* t = nullptr);
	void push(T d);
	T pop();
	bool isempty();
	~stack();
	T checktop();
};

