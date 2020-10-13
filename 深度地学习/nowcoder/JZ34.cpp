#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int l=str.length();
        map<char,int>hash;
        for(int i=0;i<l;i++){
            hash[str[i]]++;
        }
        for(int i=0;i<l;i++){
            if(hash[str[i]]==1)
                return i;
        }
        return -1;
    }
};
int main (){
    Solution s;
    cout<<s.FirstNotRepeatingChar("dssdddsfdfdfgfeabytuki");
    return 0;
}