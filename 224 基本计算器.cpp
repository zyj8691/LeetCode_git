/**
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:

输入: "1 + 1"
输出: 2
示例 2:

输入: " 2-1 + 2 "
输出: 3
示例 3:

输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。
*/

class Solution {
public:
    int calculate(string s) {
        
    }
};

/*solution*/
#include <iostream>
#include<stack>
#include <string>
//using namespace std;
class Solution {
public:
	void compute(std::stack<int>&number_stack,
		std::stack<char>&operation_stack){
		if (number_stack.size() < 2){
			return;
		}
		int num2 = number_stack.top();
		number_stack.pop();
		int num1 = number_stack.top();
		number_stack.pop();
		if (operation_stack.top() == '+'){
			number_stack.push(num1 + num2);
		}
		else if (operation_stack.top() == '-'){
			number_stack.push(num1 - num2);
		}
		operation_stack.pop();
	}
	int calculate(std::string s) {
		static const int STATE_BEGIN = 0;
		static const int NUMBER_STATE = 1;
		static const int OPERATION_STATE = 2;
		std::stack<int>number_stack;
		std::stack<char>operation_stack;
		int number = 0;
		int STATE = STATE_BEGIN;
		int compute_flag = 0;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == ' '){
				continue;
			}
			switch (STATE){
			case STATE_BEGIN:
				if (s[i] >= '0'&&s[i] < '9'){
					STATE = NUMBER_STATE;
				}
				else{
					STATE = OPERATION_STATE;
				}
				i--;
				break;
			case NUMBER_STATE:
				if (s[i] >= '0'&&s[i] <= '9'){
					number = number * 10 + s[i] - '0';
				}
				else{
					number_stack.push(number);
					if (compute_flag == 1){
						compute(number_stack, operation_stack);
					}
					number = 0;
					i--;
					STATE = OPERATION_STATE;
				}
				break;
			case OPERATION_STATE:
				if (s[i] == '+' || s[i] == '-'){
					operation_stack.push(s[i]);
					compute_flag = 1;
				}
				else if (s[i]=='('){
					STATE = NUMBER_STATE;//
					compute_flag = 0;
				}
				else if (s[i]>='0'&&s[i]<='9'){
					STATE = NUMBER_STATE;
					i--;
				}
				else if (s[i] == ')'){
					compute(number_stack, operation_stack);
				}
				break;
			}
		}
		if (number != 0){
			number_stack.push(number);
			compute(number_stack, operation_stack);
		}
		if (number == 0 && number_stack.empty()){
			return 0;
		}
		return number_stack.top();
	}
};


int main()
{
	std::string s = "1+121 - (14+(5-6) )";
	Solution solve;
	printf("%d\n", solve.calculate(s));
	return 0;
}