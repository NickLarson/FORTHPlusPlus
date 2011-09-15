#include <iostream>
#include <istream>
#include <ostream>
#include <stack>
#include <ostream>


int math_interpret(std::string n, std::stack<int> pile)
{
/* This interprets all of the RPN Math notation... must keep this abstracted... 
going to find a better way to do statements... Didn't have much time tonight.. Thinking Parallel Arrays! */
	int first;
	int second;
	first = pile.top();
	pile.pop();
	second = pile.top();
	pile.pop();
	if(n == "+")
		return first + second;
	else if(n == "/")
		return (first / second);
	else if(n == "*")
		return first * second;
	else if(n == "^")
		return first ^ second;
	else if(n == "-")
		return first - second;
	else
		throw 2;
}

int main()
{	
	using namespace std;
	stack<int> pile; //Get the stack set up... cheating a little since the built in stack is so robust
	int selection; 
	string error_catcher("");
	while(cin >> selection)
	{
	if(pile.size() > 1) /*This isn't an actual limit... just for testing purposes... Be aware that size indexes 0, 1, ..., n*/
		break;
	pile.push(selection); //Push anything and everything except whitespace onto the stack... this is very important
	}
	cout << "What would you like to do? ";
	string ans("");
	cin >> ans;
	cout << math_interpret(ans, pile);
}
	
	
	
	