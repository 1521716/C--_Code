#include<iostream>
using namespace std;
#include <stack>
#include<queue>

//测试函数1，用于实现栈的简单操作
void testStack()
{
	//创建一个整型栈
	stack<int> s;

	//用size查看栈的有效元素个数
	cout << "当前栈的元素个数为：" << s.size() << endl;

	//将1-5入栈
	for (int i = 1; i < 6; i++)
	{
		//push将括号内的元素压入栈中
		s.push(i);
	}

	//用size查看栈的有效元素个数
	cout << "当前栈的元素个数为：" << s.size() << endl;

	//循环获取栈顶元素，并出栈
	while (!s.empty())//empty判断当前栈是否为空，为空返回true,不为空返回false
	{
		//top获取栈顶元素
		cout << s.top() << " ";
		//pop将栈顶元素出栈
		s.pop();
	}

	//用size查看栈的有效元素个数
	cout << endl << "当前栈的元素个数为：" << s.size() << endl;
}

//测试函数2，用于实现队列的函数
void testQueue()
{
	//创建一个整型队列
	queue<int> q;

	//用size查看当前队列中有效元素个数
	cout << "当前队列中有效元素个数为:" << q.size() << endl;

	//用循环将1-5进队
	for (int i = 1; i < 6; i++)
	{
		//push将括号内元素进队（从队尾进队）
		q.push(i);
	}

	//用size查看当前队列中有效元素个数
	cout << "当前队列中有效元素个数为:" << q.size() << endl;

	//循环打印队头元素，并将队头元素出队
	while (!q.empty())//empty判断队列是否为空，为空返回true,不为空返回false
	{
		//front返回对头元素
		cout << q.front() << " ";
		//pop让对头元素出队
		q.pop();
	}

	//用size查看当前队列中有效元素个数
	cout << endl << "当前队列中有效元素个数为:" << q.size() << endl;
}


int main()
{
	testStack();
	cout << endl;
	testQueue();

	/*
	
	问：对比使用c语言链表实现，使用std::stack(queue同理)的好处是什么？
	答：使用起来非常方便，用c语言的话在使用这些函数之前还需要自己实现相应的函数、结构，导致时间成本变高，
		而且自己写的话一个是容易出错，再有就是每个人的命名习惯，函数接口的设置习惯并不相同，导致函数的健壮性、灵活性降低；
		使用std::stack则没有上述隐患

	问：代价或者缺点可能是什么？
	答：std::stack是已经确定的格式，它的具体实现方法，函数返回值，参数等等都需要自己查询；格式固定虽然解决了接口问题、命名问题，
		但是正是因为它的固定，导致它的使用方法非常受限，比如用c语言实现的时候，每个函数的返回值与参数可以根据需求自己设置，
		pop我就可以多传入一个参数来接收出栈的元素大小或者地址，非常灵活。
	
	*/

	return 0;
}
