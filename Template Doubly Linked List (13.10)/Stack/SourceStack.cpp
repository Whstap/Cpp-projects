#include "Stack.h"

void createStackByNumber(Stack<int>& stack, int num)
{
	int temp{};
	while (num)
	{
		temp = num % 10;
		stack.push(temp);
		num /= 10;
	}
}

void changeNumsInStack(Stack<int>& stack, const int num1 = 0, const int num2 = 1)
{
	Stack<int> temp_stack{};
	while (!stack.empty()) {

		if (stack.top() == num1)
			temp_stack.push(num2);
		else if (stack.top() == num2)
			temp_stack.push(num1);
		else
			temp_stack.push(stack.top());
		stack.pop();
	}
	while (!temp_stack.empty()) {
		stack.push(temp_stack.top());
		temp_stack.pop();
	}
}

int uniqueNumbersInStack(Stack<int> stack)
{
	int uniqueCount{};
	bool nums[10]{false};
	while (!stack.empty()) {
		int current = stack.top();
		nums[current] = true;
		stack.pop();
	}
	for (size_t i = 0; i < 10; i++)
	{
		if (nums[i] == true)
			uniqueCount++;
	}
	return uniqueCount;
}

int sumStack(Stack<int> stack)
{
	int sum{};
	while (!stack.empty())
	{
		sum += stack.top();
		stack.pop();
	}
	return sum;
}

void stackWithoutRepeats(Stack<int>& stack)
{
	Stack<int> temp_stack{};
	bool nums[10]{ false };
	while (!stack.empty()) {

		if (nums[stack.top()] == false) {
			temp_stack.push(stack.top());
			nums[stack.top()] = true;
		}
		stack.pop();
	}

	while (!temp_stack.empty()) {
		stack.push(temp_stack.top());
		temp_stack.pop();
	}

}

int main() {

	Stack<int> st1;
	
	int num{};
	cout << "enter number -> ";
	cin >> num;
	createStackByNumber(st1, num);
	//changeNumsInStack(st1);
	//cout << sumStack(st1) << endl;
	stackWithoutRepeats(st1);
	cout << "size: " << st1.size() << endl;;

	while (!st1.empty())
	{
		cout << st1.top() << ' ';
		st1.pop();
	}
	cout << endl;
	return 0;
}