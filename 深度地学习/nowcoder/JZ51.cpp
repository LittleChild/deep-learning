#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int>re(A.size());
        // int temp=1;
        // for(int i=0;i<A.size();i++){
        //     temp=1;
        //     for(int j=0;j<A.size();j++){
        //         if(j!=i){
        //             temp*=A[j];
        //         }
        //     }
        //     re.push_back(temp);
        // }
        int ret=1;
        for(int i=0;i<A.size();i++){
            re[i]=ret;
            ret*=A[i];
        }
        ret=1;
        for(int i=A.size()-1;i>=0;i--){
            re[i]*=ret;
            ret*=A[i];
        }
        return re;
    }
};

int main(){
    vector<int>A={1,2,3,4,5};
    Solution s;
    vector<int>b=s.multiply(A);
    for(int i=0;i<b.size();i++)
        cout<<b[i]<<' ';
    return 0;
}