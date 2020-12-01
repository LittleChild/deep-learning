#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reorganizeString(string S) {

        if (S.length() < 2) {
            return S;
        }
        vector<int> counts(26, 0);
        int maxCount = 0;
        int length = S.length();
        for (int i = 0; i < length; i++) {
            char c = S[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }
        if (maxCount > (length + 1) / 2) {
            return "";
        }
        auto cmp = [&](const char& letter1, const char& letter2) {
            return counts[letter1 - 'a']  < counts[letter2 - 'a'];
        };
        priority_queue<char, vector<char>,  decltype(cmp)> queue{cmp};
        for (char c = 'a'; c <= 'z'; c++) {
            if (counts[c - 'a'] > 0) {
                queue.push(c);
            }
        }
        string sb = "";
        while (queue.size() > 1) {
            char letter1 = queue.top(); queue.pop();
            char letter2 = queue.top(); queue.pop();
            sb += letter1;
            sb += letter2;
            int index1 = letter1 - 'a', index2 = letter2 - 'a';
            counts[index1]--;
            counts[index2]--;
            if (counts[index1] > 0) {
                queue.push(letter1);
            }
            if (counts[index2] > 0) {
                queue.push(letter2);
            }
        }
        if (queue.size() > 0) {
            sb += queue.top();
        }
        return sb;
        // int l=S.length();
        // if(l<2) return S;
        // if(l==2){
        //     if(S[0]==S[1]) return "";
        //     else return S;
        // }
        
        // int m[27]={0};
        // int temp=0;
        // for(int i=0;i<l;i++){
        //     m[int(S[i])-int('a')]++;
        // }
        // sort(m,m+26,greater<int>());
        // for(int i=0;i<26;i++){
        //     if(m[i]==0){
        //         if(abs(temp)>=2)
        //             return "";
        //         break;
        //     }
        //     if(temp>0)
        //         temp-=m[i];
        //     else
        //         temp+=m[i];
        // }
        // return "OK";
    }
};
int main(){
    string S="cxmwmmm";
    Solution s;
    // cout<<char(97);
    cout<<s.reorganizeString(S);
    return 0;
}