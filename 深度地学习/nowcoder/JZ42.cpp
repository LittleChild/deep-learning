#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>re;
        int i=0,j=array.size()-1;
        while(i<j){
            if(array[i]+array[j]==sum){
                re.push_back(array[i]);
                re.push_back(array[j]);
                break;
            }
            
            while(i<j && array[i]+array[j]<sum) i++;
            while (i<j && array[i]+array[j]>sum) j--;
        }
        // int i=0,j=1;
        // if(array.size()<1)
        //     return re;
        // if(array.size()==2){
        //     if(re[0]+re[1]==sum){
        //         re.push_back(re[0]);
        //         re.push_back(re[1]);
        //     }
        //     return re;
        // }
        // int s=sum;
        // for(i;i<array.size();i++){
        //     s-=array[i];
        //     for(j=i+1;j<array.size();j++){
        //         if(array[j]==s){
        //             re.push_back(array[i]);
        //             re.push_back(array[j]);
        //             break;
        //         }
        //         if(array[j]>s)
        //             break;
        //     }
        //     if(re.size()>1)
        //         break;
        //     s=sum;
        // }
        return re;
    }
};
int main(){
    Solution s;
    vector<int>t={1,2,3,4,5,6,7,8,9,10};
    vector<int>re=s.FindNumbersWithSum(t,15);
    for(int i=0;i<re.size();i++){
        cout<<re[i]<<' ';
    }
    return 0;
}