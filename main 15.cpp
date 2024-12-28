/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* node, int currentNumber) {
        if (!node) return 0;
        currentNumber = currentNumber * 10 + node->val;
        if (!node->left && !node->right) return currentNumber;
        return dfs(node->left, currentNumber) + dfs(node->right, currentNumber);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;
    cout << solution.sumNumbers(root) << endl;

    return 0;
}
