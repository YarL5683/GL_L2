#pragma once
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Calculator
{
public:
	Calculator();
	
	void Start(void);
	
	void RPN(void);
	void Calculate(void);
	void MoveResult(string);

	bool isSign(int);
	bool isSign(char);
	int priority(string);

	void printStack(void);
	
	~Calculator();

private:
	string input_line;
	string result[10];
	int counter;
	stack<std::string> s1;
	stack<std::string> s2;
};

