#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
         int *state=new int[n*n];
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(state[i*n+j]!=2){
                    int t=matrix[i][j];
                    matrix[i][j]=matrix[n-1-i][j];
                    matrix[n-1-i][j]=t;
                    state[i*n+j]=2;
                    state[(n-1-i)*n+j]=2;
                 }
             }
         }
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(state[i*n+j]!=1){
                    int t=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=t;
                    state[i*n+j]=1;
                    state[j*n+i]=1;
                 }
             }
         }
    }
};
int main(){
    Solution s;
    
    return 0;
}