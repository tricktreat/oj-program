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

class Solution {
public:
    int d[1<<20];
    vector<int> v;
    bool canJump(vector<int>& nums) {
        memset(d,-1,sizeof(d));
        d[0]=1;
        v=nums;
        return dp(nums.size()-1);
    }
    
    bool dp(int t){
        if(d[t]>-1){
            return d[t];
        }
        d[t]=0;
        for(int i=0;i<t;i++){
            if(dp(i)==1&&i+v[i]>=t){
               d[t]=1;
                break;
            }
        }
        return d[t];
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}