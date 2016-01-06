/*
Given a binary tree, return the postorder traversal of its nodes' values.

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using std::string;
using std::vector;
using std::stack;
using std::cout;
using std::endl;

namespace {

class Solution {
public:

    bool isLeaf(TreeNode *nd) const {return (!nd->left and !nd->right);}

    void walk(TreeNode *nnd) {
        if(NULL == nnd) return;
        _nd = nnd;
        _path.push(_nd);
    }

    bool back() {
        _path.pop();
        _result.push_back(_nd->val);
        if(_path.empty()) return false;

        bool final = (top() == _root and top()->right == _nd);
        _nd = top();
        if(final) _result.push_back(_nd->val);
        return !final;
    }

    TreeNode* top() const {return (_path.empty())?NULL:_path.top();}

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return _result;
        _root = root;

        walk(root);
        do {
            while(_nd->left and !isLeaf(_nd->left)) {
                walk(_nd->left); // walk into the left most leaf's parent
            }

            if(_nd->left) _result.push_back(_nd->left->val);

            do {
                if(_nd->right and _nd->right != _prev) {
                    walk(_nd->right);
                    break;
                }
                _prev = _nd;
            }while(back());

        }while(_nd != root and _nd != NULL);

        return _result;
    }

private:
    vector<int>             _result;
    stack<TreeNode*>        _path;
    TreeNode*               _nd;
    TreeNode*               _prev;
    TreeNode*               _root;
};


} // namespace



int main(int argc, char const *argv[])
{
    auto so = new Solution;
    auto a = new TreeNode(1);
    auto b = new TreeNode(4);
    auto c = new TreeNode(3);
    auto d = new TreeNode(2);

    a->left  = b;
    a->right = c;
    b->left  = d;

    // a->left = c;
    // c->left = d;

    // a->left = b;
    // b->right = c;

    auto ret = so->postorderTraversal(a);
    cout << "The traversal result is:" << endl;
    for(auto it = ret.begin(); it != ret.end(); ++it) {
        cout << (*it) << endl;
    }
    return 0;
}