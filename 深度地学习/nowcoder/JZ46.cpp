#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0)
            return -1;
        vector<int>index;
        for(int i=0;i<n;i++){
            index.push_back(i);
        }
        int i=0;
        int count=0;
        while(index.size()>1){
            if (count==m-1){
                index.erase(index.begin()+i);
                count=0;
            }
            else{
                i++;
                count++;
            }
            if(i>=index.size()){
                i=0;
            }
        }
        return index[0];
        
    }
};
int main(){
    Solution s;
    cout<<s.LastRemaining_Solution(10,3);
    return 0;
}
