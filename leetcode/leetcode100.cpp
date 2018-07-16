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
#include <ctime>
#include <cstring>
#include <sstream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q){
            return 1;
        }
        if(p&&!q){
            return 0;
        }
        if(q&&!p){
            return 0;
        }
        if(p->val!=q->val){
            return 0;
        }
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        //return (isSameTree(p->left,q->left)|&&isSameTree(p->right,q->right))||(isSameTree(p->left,q->right)&&isSameTree(p->right,q->left));
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* p = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* q = stringToTreeNode(line);
        
        bool ret = Solution().isSameTree(p, q);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

/*创建一棵树，数据结构使用结构体数组*/

// struct TreeNode {
//     int val;
//     int left;
//     int right;
//     TreeNode(int x) : val(x), left(-1), right(-1) {}
// };


// TreeNode node[MAXN];
// int checked[MAXN];

// int createTree(){
//     int n;
//     cin>>n;
//     for (int i = 0; i < n; ++i)
//     {
//         cin>>node[i].val>>node[i].left>>node[i].right;
//         checked[node[i].left]=1;
//         checked[node[i].right]=1;

//     }
//     for (int i = 0; i < n; ++i)
//     {
//         if(!checked[i])
//             return i;
//     }
//     return -1;
// }