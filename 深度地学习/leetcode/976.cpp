#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        for(int i=A.size()-1;i>1;i--){
            if(A[i]<A[i-1]+A[i-2]){
                return (A[i]+A[i-1]+A[i-2]);
            }
        }
        return 0;
    }
};
int main(){
    vector<int>A={3,2,3,4};
    Solution s;
    cout<<s.largestPerimeter(A);
    return 0;
}