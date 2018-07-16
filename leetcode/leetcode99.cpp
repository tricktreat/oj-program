#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <list>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// /**
//  * 解法一（迭代版本中序遍历）
//  */
// class Solution {
// public:
//     TreeNode* first;
//     TreeNode* second;
//     TreeNode* prev;
    
//     void recoverTree(TreeNode* root) {
        
//         traverse(root);
        
//         int tmp=first->val;
//         first->val=second->val;
//         second->val=tmp;
//     }
    
//     void traverse(TreeNode* root){
//         if(!root){
//             return;
//         }
//         traverse(root->left);
//         if (!first&&prev&&prev->val>root->val){
//             first=prev;
//         }
//         if(first&&prev->val>root->val){
//             second=root;
//         }
//         prev=root;
        
//         traverse(root->right);
//     }
// };
    

/**
 * 解法二（递归版本中序遍历）
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* t=root;
        TreeNode *first=NULL, *second=NULL,*prev=NULL;
        stack<TreeNode*> s;
        while(t||!s.empty()){
            while(t){
                s.push(t);
                t=t->left;
            }
            
            if(!s.empty()){
                t=s.top();
                s.pop();
                /*中序遍历 do something end*/
                if(!first&&prev&&prev->val>t->val){
                    first=prev;
                }
                if(first&&prev->val>t->val){
                    second=t;
                }
                prev=t;
                /*中序遍历 do something end*/
                t=t->right;
                
            }
        }
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
        
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        Solution().recoverTree(root);

        string out = treeNodeToString(root);
        cout << out << endl;
    }
    return 0;
}

