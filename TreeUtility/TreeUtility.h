#pragma once
#include<map>
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
}
