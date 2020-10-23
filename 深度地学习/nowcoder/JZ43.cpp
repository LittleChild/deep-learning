#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        // char t;
        // for(int i=0;i<n;i++){
        //     t=str[0];
        //     str.erase(str.begin());
        //     str+=t;
        // }
        // return str;

        // string re="";
        // for(int i=n;i<str.length();i++){
        //     re+=str[i];
        // }
        // for(int i=0;i<n;i++){
        //     re+=str[i];
        // }
        // return re;
        
        // reverse(str.begin(), str.end());
        // reverse(str.begin(), str.begin() + str.size() - n);
        // reverse(str.begin() + str.size() - n, str.end());
        // return str;
        
        // if(str=="")
        //     return str;
        // reflow(str,0,str.length()-1);
        // reflow(str,0,str.length()-n-1);
        // reflow(str,str.length()-n,str.length()-1);
        // return str;
        
        if(str=="")
            return str;
        reflow(str,0,n-1);
        reflow(str,n,str.length()-1);
        reflow(str,0,str.length()-1);
        return str;
    }
    void reflow(string &str,int start,int end){
        char t;
        while(start<end){
            t=str[start];
            str[start]=str[end];
            str[end]=t;
            start++;
            end--;
        }
    }
};

int main(){
    string a="abcXYZdef";
    Solution s;
    cout<<s.LeftRotateString(a,3);
    return 0;
}