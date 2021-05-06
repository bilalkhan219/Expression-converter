#include "conversions.h"
#include <string>
using namespace std;
conversion::conversion(){
	st.push('L');
}
int conversion::prec(char c) {
	if (c == '%' || c == '*' || c == '/') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else
		return -1;
}
string conversion::infixtopostfix(string exp) {
	int l = exp.length();
	string str;
	for (int i = 0; i < l; i++) {
		if (exp[i] == '(') {
			st.push(exp[i]);
		}
		else if (exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= 'a' && exp[i] <= 'z') {
			str = str + exp[i];
		}
		else if (exp[i] == ')') {
			while (st.checktop() != 'L' && st.checktop() != '(') {
				str += st.pop();
			}
			st.pop();
		}
		else {
			while (st.checktop() != 'L' && (prec(exp[i]) <= prec(st.checktop()))) {
				str += st.pop();
			}
			st.push(exp[i]);
		}
	}
	while (st.checktop() != 'L') {
		str += st.pop();
	}
	return str;
}
string conversion::reverse(string exp) {
	for (int i = 0; i < exp.length(); i++) {
		st.push(exp[i]);
	}
	string rev;
	while (st.checktop() != 'L') {
		rev += st.pop();
	}
	return rev;
}
string conversion::infixtoprefix(string e) {
	string exp = reverse(e);
	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] == ')') {
			exp[i] = '(';
			continue;
		}
		else if (exp[i] == '(') {
			exp[i] = ')';
			continue;
		}
	}
	string str;
	str = infixtopostfix(e);
	str = reverse(str);
	return str;
}
string conversion::postfixtoinfix(string exp) {
	int l = exp.length();
	string str;
	for (int i = l-1; i >= 0; i--) {
		if (exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= 'a' && exp[i] <= 'z') {
			str += exp[i];
			while (st.checktop() != '+' && st.checktop() != '*' && st.checktop() != '-' && st.checktop() != '/' && st.checktop() != '%' && st.checktop() != 'L') {
				str += st.pop();
			}
			if (st.checktop() != 'L') {
				str += st.pop();
			}
		}
		else {
			str += ')';
			st.push('(');
			st.push(exp[i]);
		}
	}
	str = reverse(str);
	return str;
}
string conversion::prefixtoinfix(string exp) {
	string str;
	for (int i = 0; i < exp.length() ; i++) {
		if (exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= 'a' && exp[i] <= 'z') {
			str += exp[i];
			while (st.checktop() != '+' && st.checktop() != '*' && st.checktop() != '-' && st.checktop() != '/' && st.checktop() != '%' && st.checktop() != 'L') {
				str += st.pop();
			}
			if (st.checktop() != 'L') {
				str += st.pop();
			}
		}
		else {
			str += '(';
			st.push(')');
			st.push(exp[i]);
		}
	}
	return str;
}
