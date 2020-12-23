#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int map[26]={0};
        
        for(int i=0;i<s.length();i++){
            map[int(s[i]-'a')]++;
        }
        for(int i=0;i<s.length();i++){
            if(map[int(s[i]-'a')]==1)
                return i;
        }
        return -1;
    }
};

int main(){
    string s="leetcode";
    Solution a;
    // cout<<('c'-'a');
    cout<<a.firstUniqChar(s);
    return 0;
}