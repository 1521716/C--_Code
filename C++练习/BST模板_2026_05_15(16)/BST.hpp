#pragma once
#include<iostream>
#include<string>
//二叉搜索树类
template<class TEM>
class BST {
private:

	struct TreeNode {
		TEM val;
		TreeNode* lchild;
		TreeNode* rchild;
		TreeNode(const TEM& v) : val(v), lchild(nullptr), rchild(nullptr) {}
	};
	TreeNode* T = NULL;

public:
	//无参构造，实现初始化
	BST()
	{
		T = NULL;
	}

	//插入
	void insert(const TEM& val)
	{
		helpInsert(T, val);
	}

	//搜索
	bool search(const TEM& val)
	{
		if (helpSearch(T, val) == NULL)
			return false;
		return true;
	}

	//删除
	bool remove(const TEM& val)
	{
		if (!search(val))
		{
			std::cout << "树中无" << val << "结点，删除失败" << std::endl;
			return false;
		}

		helpRemove(T, val);
		return true;
	}

	//遍历
	//先序遍历
	void showDLR()
	{
		helpShowDLR(T);
	}
	//中序遍历
	void showLDR()
	{
		helpShowLDR(T);
	}
	//后序遍历
	void showLRD()
	{
		helpShowLRD(T);
	}

	//析构函数(释放空间)
	~BST()
	{
		helpDelete(T);
	}


private:
	//辅助插入函数
	void helpInsert(TreeNode*& T, const TEM& val)
	{
		if (T == NULL)
		{
			T = new TreeNode(val);
		}
		else if (val < T->val)
		{
			helpInsert(T->lchild, val);
		}
		else
		{
			helpInsert(T->rchild, val);
		}

	}
	//辅助搜索函数
	TreeNode* helpSearch(TreeNode* T, const TEM& val)
	{
		if (T == NULL)
			return NULL;
		else if (T->val == val)
			return T;
		else if (val < T->val)
			return helpSearch(T->lchild, val);
		else if (val > T->val)
			return helpSearch(T->rchild, val);
	}
	//辅助删除函数
	void helpRemove(TreeNode*& T, const TEM& val)
	{
		if (T == NULL)
			return;
		if (val < T->val)
			helpRemove(T->lchild, val);
		else if (val > T->val)
			helpRemove(T->rchild, val);
		else
		{
			//叶子结点
			if (T->lchild == NULL && T->rchild == NULL)
			{
				delete T;
				T = NULL;
			}
			//单子结点
			else if (T->lchild != NULL && T->rchild == NULL)
			{
				TreeNode* p = T;
				T = T->lchild;
				delete p;
				p = NULL;
			}
			else if (T->rchild != NULL && T->lchild == NULL)
			{
				TreeNode* p = T;
				T = T->rchild;
				delete p;
				p = NULL;
			}
			//双子结点（右子树最小值替换）
			else
			{
				TreeNode* p = T->rchild;
				while (p->lchild)
				{
					p = p->lchild;
				}
				T->val = p->val;
				helpRemove(T->rchild, p->val);
			}
		}
	}
	//辅助遍历函数
	//辅助先序遍历
	void helpShowDLR(const TreeNode* T)
	{
		if (T != NULL)
		{
			std::cout << T->val << " ";
			helpShowDLR(T->lchild);
			helpShowDLR(T->rchild);
		}
	}
	//辅助中序遍历
	void helpShowLDR(const TreeNode* T)
	{
		if (T != NULL)
		{
			helpShowLDR(T->lchild);
			std::cout << T->val << " ";
			helpShowLDR(T->rchild);
		}
	}
	//辅助后序遍历
	void helpShowLRD(const TreeNode* T)
	{
		if (T != NULL)
		{
			helpShowLRD(T->lchild);
			helpShowLRD(T->rchild);
			std::cout << T->val << " ";
		}
	}
	//辅助析构函数
	void helpDelete(TreeNode*& T)
	{
		if (T != NULL)
		{
			helpDelete(T->lchild);
			helpDelete(T->rchild);
			delete T;
			T = NULL;
		}
	}
};
