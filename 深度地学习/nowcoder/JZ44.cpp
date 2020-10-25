#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        vector<int>index;
        index.push_back(-1);
        for(int i=0;i<str.length();i++){
            if(str[i]==' ')
                index.push_back(i);
        }
        int d=str.length();
        while(index.size()>0){
            reverse(str.begin()+index.back()+1,str.begin()+d);
            d=index.back();
            index.pop_back();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
int main(){
    string str="student. a am I";
    Solution s;
    cout<<s.ReverseSentence(str);
    return 0;
}