#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int re=0;
        int bit=1;
        for(int i=str.length()-1;i>=0;i--){
            if(int(str[i])<=57 && int(str[i])>=48){
                re+=bit*(int(str[i])-48);
                bit*=10;
            }else if(i==0){
                if(str[i]=='+')
                    return re;
                if(str[i]=='-')
                    return -re;
                return 0;
            }
            else{
                return 0;
            }
        }
        return re;
    }
};

int main(){
    Solution s;
    string str="1234564";
    
    cout<<s.StrToInt(str);
    return 0;
}