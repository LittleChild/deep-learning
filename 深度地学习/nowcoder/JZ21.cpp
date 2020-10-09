#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()&&popV.empty())
            return true;
        int l=pushV.size();
        vector<int> record;
        int k=0;
        for(int i=0;i<l;i++){
            record.push_back(pushV[i]);
            while(!record.empty()&&record.back()==popV[k]){
                record.pop_back();
                k++;
                }
            }
        if (record.empty())
            return 1;
        else
            return 0;







        // if(pushV.empty()&&popV.empty())
        //     return true;
        // int l=pushV.size();
        // vector<int> record;
        // int k=0;
        // for(int i=0;i<l;i++){
        //     if (pushV[i]!=popV[k]){
        //         record.push_back(pushV[i]);
        //     }
        //     else{
        //         if(!record.empty()){
        //             while(record.back()==popV[++k]){
        //                 record.pop_back();
        //             }
        //         }
        //         else
        //         {
        //             k++;
        //         }
                
        //     }
        // }
        // if (record.empty())
        //     return 1;
        // else
        //     return 0;
    }

};

int main(){
    Solution a;
    vector<int> pushV={1,2,3,4,5};
    vector<int> popV={4,5,3,2,1};
    bool re=a.IsPopOrder(pushV,popV);
    cout<<re<<endl;
    return 0;
}