#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int L=A.size();
        map<int,int>m1;
        map<int,int>m2;
        int c1[250000]={0};
        int c2[250000]={0};
        for(int i=0;i<L;i++){
            for(int j=0;j<L;j++){
                c1[i+j*L]+=A[i];
                c1[i+j*L]+=B[j];
                c2[i+j*L]+=C[i];
                c2[i+j*L]+=D[j];
                // cout<<c1[i+j*L]<<' '<<c2[i+j*L]<<endl;
                m1[c1[i+j*L]]++;
                m2[c2[i+j*L]]++;
            }
        }
        int re=0;
        for(map<int,int>::reverse_iterator iter=m1.rbegin();iter!=m1.rend();iter++){
            if(m2[-(iter->first)]){
                re+=(m2[-(iter->first)]*iter->second);
            }
        }
        return re;

        // unordered_map<int, int> countAB;
        // for (int u: A) {
        //     for (int v: B) {
        //         ++countAB[u + v];
        //     }
        // }
        // int ans = 0;
        // for (int u: C) {
        //     for (int v: D) {
        //         if (countAB.count(-u - v)) {
        //             ans += countAB[-u - v];
        //         }
        //     }
        // }
        // return ans;

    }
};


int main(){
    Solution s;
    vector<int>A={1,2};
    vector<int>B={-2,-1};
    vector<int>C={-1,2};
    vector<int>D={0,2};
    cout<<s.fourSumCount(A,B,C,D);
    return 0;
}