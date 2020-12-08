#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> ans;
    vector<int> splitIntoFibonacci(string S) {
        const int n = S.length();
        backtracking(0,n,S);
        return ans; 
    };
    bool backtracking(int p,int n,string S) {
        if (p == n) return ans.size() > 2;
        long num = 0;
        int max_len = S[p] == '0' ? 1 : 10;
        for (int i = p; i < min(p + max_len, n); ++i) {
            num = num * 10 + S[i] - '0';
            if (num > INT_MAX) break; // prunning ...
            if (ans.size() >= 2) {
            long sum = ans.rbegin()[0];
            sum += ans.rbegin()[1];
            if (num > sum) break; // pruning ...
            else if (num < sum) continue;
            // num must equals to s
            }
            ans.emplace_back(num);
            if (backtracking(i + 1,n,S)) return true;;
            ans.pop_back();
        }
        return false;
    };
};
int main(){
    
    Solution s;
    vector<int>A=s.splitIntoFibonacci("123456579");
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<' ';
    }
    return 0;
}