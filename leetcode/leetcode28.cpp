class Solution {
public:
    int ne[1<<20];
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        getNext(needle);
        return kmpGetIndex(haystack,needle);
    }
    
    void getNext(string needle){
        int m=needle.size();
        int j=0;
        int k=-1;
        ne[j]=k;
        while(j<m){
            if(k==-1||needle[j]==needle[k]){
                ne[++j]=++k;
            }else{
                k=ne[k];
            }
        }
    }
    
    int kmpGetIndex(string str,string pattern){
        int l=str.size();
        int p=pattern.size();
        int i=0;
        int k=0;
        while(i<l){
            if(k==-1||str[i]==pattern[k]){
                k++;
                i++;
            }else{
                k=ne[k];
            }
            if(k==p){
                return i-p;
            }
        }
        return -1;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);
        
        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}