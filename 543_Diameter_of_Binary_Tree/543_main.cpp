#include <iostream>
#include <map>
#include <list>
#include <string>
#include "../TreeUtility/TreeUtility.h"
using namespace std;

#define n(i) new int(i)

static map<int, int> test{ {0, 1}, {1, 2}, {2, 3}, {4, 5} };
static vector<int*> test1{ n(1), n(2), n(3), n(4), n(5), nullptr, n(7)};

int GetNodeHeight(const tree::TreeNode* node, int &maxDiameter)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = ::GetNodeHeight(node->left, maxDiameter);
    int rightHeight = ::GetNodeHeight(node->right, maxDiameter);

    maxDiameter = maxDiameter > (leftHeight + rightHeight) ? maxDiameter : (leftHeight + rightHeight);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int diameterOfBinaryTree(tree::TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        if (root->left)
        {

        }

        int leftDiameter = root->left != nullptr ? diameterOfBinaryTree(root->left) + 1 : 0;
        int rightDiameter = root->right != nullptr ? diameterOfBinaryTree(root->right) + 1 : 0;

        return leftDiameter > rightDiameter ? leftDiameter : rightDiameter;
    }
}

int main(int argc, char* argv[])
{
    //tree::TreeNode* binaryTree = tree::CreateBinaryTree(test);
    //cout << diameterOfBinaryTree(binaryTree) << endl;

    tree::TreeNode* binaryTree = tree::CreateBinaryTree(test1);
    //cout << diameterOfBinaryTree(binaryTree) << endl;
    //cout << "height" << " " << tree::GetNodeHeight(binaryTree) << endl;

    int maxDiameter = 0;
    int height = ::GetNodeHeight(binaryTree, maxDiameter);

    cout << "Max Diameter: " << maxDiameter << endl;
    cout << "Height: " << height << endl;
}