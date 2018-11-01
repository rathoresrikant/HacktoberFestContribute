#include <iostream>
#include <vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
public:
	T data;
	vector<TreeNode*>children;
	TreeNode(T d)
	{
		data=d;
	}
	~TreeNode()
	{
		for(int i=0;i<children.size();i++)
			delete children[i];
	}
};

