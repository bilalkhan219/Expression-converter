#include "stack.h"
#include <iostream>
using namespace std;
template <typename T>stack<T>::stack(node<T>* t) {
	top = t;
}
template <typename T> void stack<T>::push(T d) {
	top = new node<T>(d, top);
}
template <typename T> bool stack <T>::isempty() {
	return top == nullptr;
}
template <typename T> T stack <T>::pop() {
	if (!isempty()) {
		T d = top->data;
		node<T>* t = top;
		top = top->next;
		delete t;
		return d;
	}
	exit(1);
}
template <typename T> stack <T> ::~stack() {
	node<T>* t;
	while (!isempty()) {
		t = top;
		top = top->next;
		delete t;
	}
}
template <typename T> T stack <T> ::checktop() {
	T element;
	element = this->pop();
	this->push(element);
	return element;
}