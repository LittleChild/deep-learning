#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string re;
        int map[26]={0},vis[26]={0};
        // map记录s的字母出现次数，vis记录栈中是否存在，即判断是否是新字母
        for(int i=0;i<s.length();i++){
            map[int(s[i])-int('a')]++;  
        }
        for(char ch:s){
            if(!vis[ch-'a']){
                while(!re.empty() && re.back() > ch){
                // 如果栈顶元素的字典序比新的字母大，看其是否有多个，考虑删掉
                    if(map[re.back()-'a']){
                        vis[re.back()-'a']=0;
                        re.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                // 新字母进栈
                vis[ch-'a']=1;
                re.push_back(ch);
            }
            // 进栈后要map计数减1
            map[ch-'a']--;
        }
        return re;
    }
};
int main(){
    Solution s;
    
    return 0;
}