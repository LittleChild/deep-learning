#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k)
            return "0";
        int count=0;
        num+="0";
        while (count<k)
        {
            for(int i=0;i<num.length();i++){
                if(int(num[i])>int(num[i+1])){
                    count++;
                    num.erase(i,1);
                    break;
                }
            }
        }
        num.pop_back();
        while(num.length()>1 && num[0]=='0')
            num.erase(0,1);
        return num;
    }
};
int main(){
    Solution s;
    string num="10200";
    string re=s.removeKdigits(num,1);
    cout<<re<<endl;

    return 0;
}