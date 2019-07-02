//============================================================================
// Name        : Assig1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Stack.h"
#include "Stack.cpp"
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


void getexp(char exp[20]) {

	cout << "\n Enter The Infix Expression: ";
	cin >> exp;

}


void display(string title, char exp[20]) {
	cout << "\n" << title;
	cout << exp;
}

int priority(char c) {

	if (c == '^')
		return 5;
	else if (c == '%')
		return 4;
	else if (c == '*' || c == '/')
		return 3;
	else if (c == '-' || c == '+')
		return 2;
	else
		return 0;
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '%' || c == '!')
		return true;
	return false;
}

void pre_post(char exp[20], char res[20], int code) {
	int j = 0;
	Stack<char> s1;
	for (int i = 0; exp[i] != '\0'; i++) {


		if (isalpha(exp[i])) {
			res[j] = exp[i];
			j++;

		} else if (isOperator(exp[i]) || exp[i] == '(') {

			if (exp[i] == '^') {
				if (code == 0) {
					while (!s1.isEmpty()
							&& priority(s1.Top()) > priority(exp[i])) {
						res[j] = s1.pop();
						j++;
					}

				} else {
					while (!(s1.isEmpty())
							&& priority(s1.Top()) >= priority(exp[i])) {
						res[j] = s1.pop();
						j++;
					}
				}
				s1.push(exp[i]);

			} else {
				if (exp[i] == '(')
					s1.push(exp[i]);
				else {
					if (code == 0) {
						while (!(s1.isEmpty())
								&& priority(s1.Top()) >= priority(exp[i])) {
							res[j] = s1.pop();
							j++;
						}
					} else {
						while (!(s1.isEmpty())
								&& priority(s1.Top()) > priority(exp[i])) {
							res[j] = s1.pop();
							j++;
						}
					}

					s1.push(exp[i]);
				}

			}

		} else if (exp[i] == ')') {
			while (s1.Top() != '(') {
				res[j] = s1.pop();
				j++;
			}
			s1.pop();

		} else {
			cout << "\nCharacter Is Digit or Any Other Symbol";
		}
	}

	while (!(s1.isEmpty())) {
		res[j] = s1.pop();
		j++;
	}

	res[j] = '\0';

}

void reverse(char exp[20], char rev[20]) {
	int i = 0, j = 0;
	int l = strlen(exp);
	for (i = l - 1; i >= 0; i--) {
		if (exp[i] == ')') {
			rev[j] = '(';
			j++;
		} else if (exp[i] == '(') {
			rev[j] = ')';
			j++;
		} else {
			rev[j] = exp[i];
			j++;
		}
	}
	rev[j] = '\0';
}
float performOP(float op1, float op2, char c) {
	switch (c) {

	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	case '^':
		return pow(op1, op2);
	case '%':
		return (int(op1) % int(op2));
		break;
	default:
		return 0;

	}
}
float evaluate(char exp[20], int code) {
	Stack<float> s2;
	int i = 0;
	float val, op1, op2;
	while (exp[i] != '\0') {
		if (isalpha(exp[i])) {
			cout << "\nEnter Value For operand "<<exp[i]<<" :";
			cin >> val;
			s2.push(val);
			i++;
			continue;
		} else {
			if (code == 0) {
				op2 = s2.pop();
				op1 = s2.pop();
				float ans = performOP(op1, op2, exp[i]);
				s2.push(ans);
				i++;
			} else {
				op1 = s2.pop();
				op2 = s2.pop();
				float ans = performOP(op1, op2, exp[i]);
				s2.push(ans);
				i++;
			}
		}
	}

	return s2.Top();

}

bool isValid(char exp[20]) {

	int k = 0, j = 0;
	int bo = 0;


	for (int i = 0; exp[i]; i++) {

	/*	if(!isOperator(exp[i]) && !isalpha(exp[i]) && !isdigit(exp[i]))
		{
			if(exp[i] != '(')
			{
				if(exp[i] != ')')

					return false;
			}
		}

		if(exp[i] == '!')
		{
			if(!isOperator(exp[i-1]))
			{
				return false;
			}
		}*/
		if(isOperator(exp[0]))
			 return false;

		if (isOperator(exp[i])) {
			k++;
			if ((isalpha(exp[i - 1]) || (exp[i-1] == ')')) && (isalpha(exp[i + 1]) || (exp[i+1] == '(')) && (exp[i + 1] != '\0')  && !(exp[i+1] == ')'))
			{

					j++;
			}
		}

		if (exp[i] == '(') {
			bo++;
		}

		if (exp[i] == ')') {
			bo--;
		}
	}

	if (k == j && bo == 0)
		return true;
	return false;

}

int main() {
	char exp[20], res[20], rev[20];
	int choice, code;
	exp[0] = '\0';
	do {

		cout << "\n\n----------- MAIN MENU -------------";
		cout<< "\n1.Enter Expression.\n2.Display Expression\n3.Infix To Postfix\n4.Infix To Prefix\n5.Evaluate Prefix Expression\n6.Evaluate Postfix Expression\n7.Exit";
		cout << "\n-----------------------------------";

		cout << "\nEnter Your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
				getexp(exp);

				if(!isValid(exp)){
					cout << "\nPlease Enter The correct Infix Expression";
				    exp[0] = '\0';
				}
				else{
					cout<<"\n";
				}

			break;

		case 2:
			if (exp[0] == '\0') {
				cout<< "\nExpression is Not Entered";
			} else {
				display("Entered Infix Expression Is: ", exp);
			}
			break;

		case 3:
			if (exp[0] == '\0') {
				cout<< "\nExpression is Not Entered ";
			} else {
				code = 0;
				pre_post(exp, res, code);
				display("Postfix Expression Is: ", res);
			}
			break;
		case 4:
			if (exp[0] == '\0' || !isValid(exp)) {
				cout<< "\nExpression is Not Entered ";
			} else {
				code = 1;
				reverse(exp, rev);
				pre_post(rev, res, code);
				reverse(res,rev);
				display("Prefix Equation Is: ", rev);
			}
			break;
		case 5:
			if (exp[0] == '\0' || !isValid(exp)) {
				cout<< "\nExpression is Not Entered ";
			} else {
				code = 0;
				reverse(exp, rev);
				pre_post(rev, res, code);
				reverse(res,rev);

				float ans = evaluate(res, code);

				cout << "\nAns Of Prefix Expression is: " << ans;
			}

			break;
		case 6:
			if (exp[0] == '\0') {
				cout<< "\nExpression is Not Entered";
			} else {
				code = 1;
				pre_post(exp, res, code);

				float ans = evaluate(res, code);

				cout << "\nAns Of Postfix Expression is: " << ans;
			}
			break;

		default:
			cout << "\nEnter Valid Choice";
		}

	} while (choice != 7);
	return 0;
}
