#include <vector>
#include "../TreeUtility/TreeUtility.h"
using std::vector;
using namespace tree;

#define n(i) new int(i)
static vector<int*> test1{ n(1), n(2), n(3), n(4), n(5), nullptr, n(7) };

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> ret;
	if (root == nullptr)       // <--------- important
	{
		return ret;
	}

	if (root->left)
	{
		vector<int> _ret = inorderTraversal(root->left);

		for (vector<int>::const_iterator iter = _ret.begin(); iter != _ret.end(); ++iter)
		{
			ret.push_back(*iter);
		}
	}
	
	ret.push_back(root->val);

	if (root->right)
	{
		vector<int> _ret = inorderTraversal(root->right);

		for (vector<int>::const_iterator iter = _ret.begin(); iter != _ret.end(); ++iter)
		{
			ret.push_back(*iter);
		}
	}

	return ret;
}

int main(int argc, char* argv[])
{
	tree::TreeNode* binaryTree = tree::CreateBinaryTree(test1);

	vector<int> result = inorderTraversal(binaryTree);

	return 0;
}