#include"BST.hpp"

void test_int()
{
	BST<int> Tree;
	Tree.insert(5);
	Tree.insert(3);
	Tree.insert(7);
	Tree.insert(2);
	Tree.insert(4);
	Tree.insert(6);
	Tree.insert(8);
	Tree.insert(1);

	Tree.remove(5);

	std::cout << "先序遍历：";
	Tree.showDLR();
	std::cout << std::endl;
	std::cout << "中序遍历：";
	Tree.showLDR();
	std::cout << std::endl;
	std::cout << "后序遍历：";
	Tree.showLRD();
}

void test_string()
{
	BST<std::string> Tree;
	Tree.insert("a");
	Tree.insert("v");
	Tree.insert("d");
	Tree.insert("c");
	Tree.insert("n");
	Tree.insert("e");
	Tree.insert("g");
	Tree.insert("b");

	Tree.remove("c");

	std::cout << "先序遍历：";
	Tree.showDLR();
	std::cout << std::endl;
	std::cout << "中序遍历：";
	Tree.showLDR();
	std::cout << std::endl;
	std::cout << "后序遍历：";
	Tree.showLRD();
}
int main()
{

	//test_int();
	test_string();

	return 0;
}