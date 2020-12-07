#include<iostream>
#include<vector>
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
        int c=0;
        for(int i=1;i<A[0].size();i++){
            c=0;
            for(int j=0;j<A.size();j++){
                if(A[j][i]==0)
                    c++;
            }
            if(c>A.size()/2){
                for(int j=0;j<A.size();j++){
                A[j][i]=1-A[j][i];
            }
            }
        }
        int re=0;
        for(int i=0;i<A.size();i++){
            int t=1;
            for(int j=A[i].size()-1;j>=0;j--){
                // cout<<A[i][j]<<' ';
                    re+=A[i][j]*t;
                    t*=2;
                }
            // cout<<endl;
        }
        return re;
    }
};
int main(){
    vector<int>A={2,2};
    Solution s;
    
    return 0;
}
