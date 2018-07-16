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
    int s;
    int t;
    int count;
    int pathSum(TreeNode* root, int sum) {
        s=sum;
        count=0;
        vector<int> t;
        t.push_back(0);
        dfs(root,t);
        return count;
    }
    
    void dfs(TreeNode* root,vector<int> sums){
        if(!root){
            return;
        }

        sums.push_back(sums[sums.size()-1]+root->val);

        int cur=sums[sums.size()-1];
        for(int i=0;i<sums.size()-1;i++){
            if(cur-sums[i]==s){
                count++;
            }
        }
        dfs(root->left,sums);
        dfs(root->right,sums);
    }
};

// 双递归
// class Solution {
// public:
//     int pathSum(TreeNode* root, int sum) {
//         if(!root) return 0;
//         return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
//     }
// private:
//     int sumUp(TreeNode* root, int pre, int& sum){
//         if(!root) return 0;
//         int current = pre + root->val;
//         return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
//     }
// };

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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);
        
        int ret = Solution().pathSum(root, sum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}