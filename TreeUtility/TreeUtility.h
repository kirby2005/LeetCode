#pragma once
#include<map>
#include<list>
#include<vector>
#include<array>
#include<vector>

namespace tree
{
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    TreeNode* CreateBinaryTree(const std::map<int, int>& nodes)
    {
		int max = -INT32_MAX;

		for (auto& nodePair : nodes)
		{
			max = max < nodePair.first ? nodePair.first : max;
		}


		std::vector<TreeNode*> nodeArray;
		nodeArray.reserve(max + 1);

		for (int i = 0; i <= max; ++i)
		{
			if (nodes.find(i) != nodes.end())
			{
				TreeNode* node = new TreeNode;
				node->val = nodes.at(i);
				nodeArray.push_back(node);
			}
			else
			{
				nodeArray.push_back(nullptr);
			}
		}

		for (int i = 1; i <= max; ++i)
		{
			TreeNode* node = nodeArray[i];
			TreeNode* parent = nodeArray[(i + 1) / 2 - 1];
			if (parent && node)
			{
				if ((i + 1) % 2 == 0)
				{
					parent->left = node;
				}
				else if ((i + 1) % 2 == 1)
				{
					parent->right = node;
				}
			}
		}

		return nodeArray.size() > 0 ? nodeArray[0] : nullptr;
    }

	TreeNode* CreateSubBinaryTree(const std::vector<int*>& nodeVec, int index)
	{
		if (nodeVec.size() < index || nodeVec[index] == nullptr)
		{
			return nullptr;
		}

		TreeNode* node = new TreeNode(*nodeVec[index]);

		int leftChildIndex = 2 * index + 1;
		int rightChildIndex = 2 * index + 2;
		if (nodeVec.size() > leftChildIndex && nodeVec[leftChildIndex] != nullptr)
		{
			node->left = CreateSubBinaryTree(nodeVec, leftChildIndex);
		}

		if (nodeVec.size() > rightChildIndex && nodeVec[rightChildIndex] != nullptr)
		{
			node->right = CreateSubBinaryTree(nodeVec, rightChildIndex);
		}

		return node;
	}

	TreeNode* CreateBinaryTree(const std::vector<int*>& nodeVec)
	{
		if (nodeVec.size() == 0 || nodeVec[0] == nullptr)
		{
			return nullptr;
		}

		TreeNode* head = CreateSubBinaryTree(nodeVec, 0);

		//for (std::vector<int*>::const_iterator citer = nodeVec.begin(); citer != nodeVec.end(); ++citer)
		/*for (int i = 0; i < nodeVec.size(); ++i)
		{
			if (nodeVec[i] == nullptr)
			{
				std::cout << "null" << std::endl;
			}
			else
			{
				std::cout << *nodeVec[i] << std::endl;
			}
		}*/

		return head;
	}

	int GetNodeHeight(const TreeNode* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		int leftHeight = GetNodeHeight(node->left);
		int rightHeight = GetNodeHeight(node->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
}
