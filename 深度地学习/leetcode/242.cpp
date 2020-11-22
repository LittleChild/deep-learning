#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[27]={0};
        int count2[27]={0};
        for(int i=0;i<s.length();i++){
            count[int(s[i])-97]++;
        }
        for(int i=0;i<t.length();i++){
            count2[int(t[i])-97]++;
        }
        for(int i=0;i<27;i++){
            if(count[i]!=count2[i])
                return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    cout<<s.isAnagram("anagram","na")<<endl;
    return 0;
}