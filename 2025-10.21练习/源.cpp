/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //深度优先搜索
    //void dfs(TreeNode* root, string path, vector<string>& paths)
    //{
    //    if (root != nullptr)
    //    {
    //        path += to_string(root->val);
    //        if (root->left == nullptr && root->right == nullptr)
    //        {
    //            paths.push_back(path);
    //        }
    //        else
    //        {
    //            path += "->";
    //            dfs(root->left, path, paths);
    //            dfs(root->right, path, paths);
    //        }
    //    }
    //}
    //vector<string> binaryTreePaths(TreeNode* root) {
    //    vector<string> paths;
    //    dfs(root, "", paths);
    //    return paths;
    //}
    //广度优先搜索
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> paths;
        if (root == nullptr)
            return paths;
        queue<TreeNode*> node_queue;
        queue<string> path_queue;

        node_queue.push(root);
        path_queue.push(to_string(root->val));
        while (!node_queue.empty())
        {
            TreeNode* node = node_queue.front();
            string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                paths.push_back(path);
            }
            else
            {
                if (node->left != nullptr)
                {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + to_string(node->left->val));
                }
                if (node->right != nullptr)
                {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + to_string(node->right->val));
                }
            }
        }
        return paths;
    }
};