#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int t=0;
        int count=0;
        if(nums.size()==1)
            return;
        for(int i=0;i<nums.size();i++){
            if(i>=(nums.size()-count))
                break;
            if(nums[i]==0){
                count++;
                int j=i+1;
                while (t==0)
                {
                    if(j>=nums.size())
                            break;
                    if(nums[j]!=0){
                        nums[i]=nums[j];
                        nums[j]=0;
                        t=1;
                    }
                    else{
                        j++;
                    }
                   
                }
                t=0;
                
            }
        }
        // int i = 0,j = 0;
        // for(i = 0 ; i < nums.size(); i++)
        // {
        //     if(nums[i] != 0)
        //     {
        //         nums[j++] = nums[i];
        //     }
        // }
        // while(j < nums.size())
        // {
        //     nums[j++] = 0;
        // }

    }

};

int main(){
    Solution s;
    vector<int>nums={0,1,0,3,12};
    s.moveZeroes(nums);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<' ';
    return 0;
}
