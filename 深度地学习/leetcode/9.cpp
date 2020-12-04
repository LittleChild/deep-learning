#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string ss=to_string(x);
        int i=0,j=ss.length()-1;
        while(i<j){
            if(ss[i]!=ss[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
};

int main(){
    Solution s;
    cout<<s.isPalindrome(123);
    return 0;

}