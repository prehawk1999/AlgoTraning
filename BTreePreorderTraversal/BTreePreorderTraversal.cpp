/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <assert.h>

using std::string;
using std::vector;
using std::stack;
using std::cout;
using std::endl;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


namespace {

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret;

        auto nd = root;
        while(nd != NULL || !_nextTraversal.empty()) {
            ret.push_back(nd->val);
            if(nd->right != NULL) _nextTraversal.push(nd->right);
            if(nd->left != NULL) {
                nd = nd->left;
            }
            else if(!_nextTraversal.empty()) {
                nd = _nextTraversal.top();
                _nextTraversal.pop();
            }
            else {
                nd = NULL;
            }
        }
        return ret;
    }


private:
    stack<TreeNode*>        _nextTraversal;
};


} // namespace



int main(int argc, char const *argv[])
{
    auto so = new Solution;
    auto a = new TreeNode(1);
    auto b = new TreeNode(2);
    auto c = new TreeNode(3);
    auto d = new TreeNode(4);
    auto e = new TreeNode(5);
    auto f = new TreeNode(6);
    auto g = new TreeNode(7);
    auto h = new TreeNode(8);
    auto i = new TreeNode(9);
    a->left = b;
    a->right = e;
    b->left = c;
    b->right = d;
    e->left = g;
    e->right = f;
    f->right = h;
    h->right = i;

    auto ret = so->preorderTraversal(a);
    cout << "The traversal result is:" << endl;
    for(auto it = ret.begin(); it != ret.end(); ++it) {
        cout << (*it) << endl;
    }

    return 0;
}