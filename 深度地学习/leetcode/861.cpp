#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            if(A[i][0]==0){
                for(int j=0;j<A[i].size();j++){
                    A[i][j]=1-A[i][j];
                }
            }
        }
        for(int i=1;i<A[0].size();i++){
            for(int j=0;j<A.size();j++){
                
            }
        }
    }
};
int main(){
    vector<int>A={2,2};
    Solution s;
    
    return 0;
}