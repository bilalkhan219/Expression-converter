#include "conversions.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	conversion c;
	string expression;
	string res;
	int n;
	cout << "Enter 1 to convert from infix to postfix" << "\n" << "Enter 2 to convert from infix to prefix\n" << "Enter 3 to convert from postfix to infix\n" << "Enter 4 to convert from prefix to infix\n";
	cin >> n;
	switch (n) {
	case 1:
		cout << "Enter expression:\n";
			cin >> expression;
			res = c.infixtopostfix(expression);
			cout << "Result: " << res << "\n";
			break;
	case 2:
		cout << "Enter expression:\n";
		cin >> expression;
		res = c.infixtoprefix(expression);
		cout << "Result: " << res << "\n";
		break;
	case 3:
		cout << "Enter expression:\n";
		cin >> expression;
		res = c.postfixtoinfix(expression);
		cout << "Result: " << res << "\n";
		break;
	case 4:
		cout << "Enter expression:\n";
		cin >> expression;
		res = c.prefixtoinfix(expression);
		cout << "Result: " << res << "\n";
		break;
	}
	system("pause");
	return 0;
}