#include<iostream>

//树节点
typedef struct TreeNode {
	int val;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode,*BTree;

//二叉搜索树类
class BST {
public:
	//无参构造，实现初始化
	BST()
	{
		T = NULL;
	}

	//插入
	void insert(int val)
	{
		T = helpInsert(T, val);
	}

	//搜索
	const TreeNode* search(int val)
	{
		return helpSearch(T, val);
	}

	//获取T地址
	const BTree getBTree()const
	{
		return T;
	}

	//析构函数(释放空间)
	~BST()
	{
		helpDelete(T);
	}


private:
	//辅助插入函数
	TreeNode* helpInsert(TreeNode* T, int val);
	//辅助搜索函数
	const TreeNode* helpSearch(TreeNode* T, int val);
	//辅助析构函数
	void helpDelete(const TreeNode* T);
private:
	BTree T = NULL;
};

//辅助插入函数
TreeNode* BST::helpInsert(TreeNode* T, int val)
{
	if (T == NULL)
	{
		T = new TreeNode;
		T->val = val;
		T->lchild = NULL;
		T->rchild = NULL;
		return T;
	}
	else if (val < T->val)
	{
		T->lchild = helpInsert(T->lchild, val);
		return T;
	}
	else
	{
		T->rchild = helpInsert(T->rchild, val);
		return T;
	}
	
}

//辅助搜索函数
const TreeNode* BST::helpSearch(TreeNode* T, int val)
{
	if (T == NULL)
		return NULL;
	else if (T->val == val)
		return T;
	else if (val < T->val)
		return helpSearch(T->lchild, val);
	else if(val > T->val)
		return helpSearch(T->rchild, val);
}

//辅助析构函数
void BST::helpDelete(const TreeNode* T)
{
	if (T != NULL)
	{
		helpDelete(T->lchild);
		helpDelete(T->rchild);
		delete T;
		T = NULL;
	}
}

void test()
{
	BST Tree;
	Tree.insert(5);
	Tree.insert(3);
	Tree.insert(7);
	Tree.insert(2);
	Tree.insert(4);
	Tree.insert(6);
	Tree.insert(8);

	if (Tree.search(4) != NULL)
		std::cout << Tree.search(4)->val << std::endl;
	else
		std::cout << "未找到" << std::endl;

	if (Tree.search(9) != NULL)
		std::cout << Tree.search(9)->val << std::endl;
	else
		std::cout << "未找到" << std::endl;
}

int main()
{
	
	test();

	return 0;
}