#include "stack.h"
#include "stack.cpp"
#pragma once
//template <typename C>
class conversion
{
	stack <char> st;
public:
	int prec(char c);
	conversion();
	string infixtopostfix(string exp);
	string infixtoprefix(string exp);
	string reverse(string exp);
	string postfixtoinfix(string exp);
	string prefixtoinfix(string exp);
};

