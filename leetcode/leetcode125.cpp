class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string::iterator left=s.begin();
        string::iterator right=s.end()-1;
        while(left<right){
            if(!isalnum(*left)){
                left++;
            }else if(!isalnum(*right)){
                right--;
            }else if(*left!=*right){
                return false;
            }else{//相等
                left++;
                right--;
            }
        }
        return true;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}