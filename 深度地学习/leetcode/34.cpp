#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int L=nums.size();
        if(L==0)
            return {-1,-1};
        vector<int>re(2,-1);
        int r=L-1,l=0;
        while(l<r){
            int m = l +(r-l)/2;
            if(nums[m]>=target) r=m;
            else l=m+1;
        }
        if(nums[l]!=target)return re;
        else re[0]=l;
        r=L;
        while(l<r){
            int m = l + (r-l)/2;
            if(nums[m]>target) r=m;
            else l=m+1;
        }
        re[1]=l-1;
        return re;

        // int l=nums.size();
        // if(l==0)
        //     return {-1,-1};
        // vector<int>re; 
        // bool is=false;
        // nums.push_back(pow(10,9));
        // l++;
        // for(int i=0;i<l;i++){
        //     if(nums[i]==target&&!is){
        //         re.push_back(i);
        //         is=true;
        //     }
        //     else if(nums[i]!=target&&is){
        //         re.push_back(i-1);
        //         is=false;
        //         break;
        //     }
        // }
        // if(re.size()==0){
        //     return {-1,-1};
        // }
        // else if(re.size()==1)
        // {
        //     re.push_back(re[0]);
        // }
        // return re;
    }
};
int main(){
    vector<int>A={2,2};
    Solution s;
    vector<int>re=s.searchRange(A,3);
    for(int i=0;i<re.size();i++)
        cout<<re[i]<<' ';
    return 0;
}