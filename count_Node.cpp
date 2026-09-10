#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    int count = 0;
    
    pair<int, int> postOrder(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        
        // First iterate over left and right subtrees (Post-order traversal)
        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);
        
        int nodeSum = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;

        // Check if the average of the subtree is equal to the node value.
        if (root->val == nodeSum / nodeCount) {
            count++;
        }
        
        // Return the sum of nodes and the count in the subtree.
        return {nodeSum, nodeCount};
    }
    
    int averageOfSubtree(TreeNode* root) {
        count = 0; // Reset count in case the function is called multiple times
        postOrder(root);
        return count;
    }
};

// Helper function to free the allocated memory
void deleteTree(TreeNode* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    
    
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    Solution S;
    
    // Calculate and print the result
    int result = S.averageOfSubtree(root);
    
    cout << "Number of nodes equal to the average of their subtree: " << result << endl;
    
    // Clean up memory
    deleteTree(root);

    return 0;
}