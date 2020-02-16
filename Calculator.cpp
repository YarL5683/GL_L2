#include "Calculator.h"

Calculator::Calculator()
{
	counter = -1;
	Start();
}

void Calculator::Start(void)
{
	//Input in cycle new math task
	bool cycle = true;
	while(cycle)
	{
		std::cin >> input_line;
		
		if (isdigit(input_line[0]) || input_line[0] == '$')
		{
			counter++;
			RPN();
		}
		else
			cycle = false;		
	}
}

void Calculator::RPN(void)
{
	int i = 0;
	
	while (i < input_line.size())
	{
		//Processing digit to stack 1
		if (isdigit(input_line[i]))
		{
			std::string digit = "";
			while (isdigit(input_line[i]))
			{
				digit += input_line[i];
					i++;
			}

			s1.push(digit);
		}

		//Load&add data from history ($0-9)
		if (input_line[i] == '$')
		{
			i++;
			int num = (int)input_line[i] - 48;
		
			if(num >=0 && num < 10)
				s1.push(result[num]);
		
			i++;
		}

		if (isSign(i))//Processing operator
		{
			std::string op="";
			op += input_line[i];
			
			if (s2.empty())
				s2.push(op);
			else
			{
				if (priority(s2.top()) == priority(op))
				{
					s1.push(s2.top());
					s2.pop();
					s2.push(op);
				}
				else if (priority(s2.top()) > priority(op))
				{
					while (s2.size() != 0) {
						s1.push(s2.top());
						s2.pop();
					}
					s2.push(op);
				}
				else
					s2.push(op);
			}
			i++;
			
		}
		
	}

	//Adding to the end s1 all operator from s2
	for (int i = s2.size(); i > 0; i--)
	{
		s1.push(s2.top());
		s2.pop();
	}

	//Revers stack
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}

	Calculate();
}


void Calculator::Calculate()
{
	int a1, a2;
	while(!s2.empty())
	{
		std::string item = s2.top();
		
		if(isdigit(item[0]))
		{
			s1.push(item);
		}
		else
		{
			string::size_type sz;
	
			a1 = stoi(s1.top(), &sz);
			s1.pop();
			
			a2 = stoi(s1.top(), &sz);
			s1.pop();

			switch (item[0])
			{
			case '+': a2 += a1;	break;
			case '-': a2 -= a1;	break;
			case '*': a2 *= a1;	break;
			case '/': a2 /= a1;	break;
			}
			
			s1.push(to_string(a2));
		}
		s2.pop();
	}
	MoveResult(to_string(a2));
	printStack();
}


void Calculator::MoveResult(string a0)
{
	
	if(counter < 10)
		result[counter] = a0;
	if(counter > 9)
	{
		for (int i = 9; i >= 1; i--)
			result[i] = result[i - 1];
		result[0] = a0;
	}
}

void Calculator::printStack(void)
{
	cout << s1.top() << endl;
}

bool Calculator::isSign(int i)
{
	if (input_line[i] == '+' || input_line[i] == '-' || input_line[i] == '*' || input_line[i] == '/')
		return true;
	return false;
}

bool Calculator::isSign(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
		return true;
	return false;
}

int Calculator::priority(string input_op)
{
	if (input_op[0] == '+' || input_op[0] == '-')
		return 1;
	return 2;
}

Calculator::~Calculator()
{
}