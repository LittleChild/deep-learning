#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()==0)
            return false;
        int min=14;
        int max=-1;
        int d[14]={0};
        for(int i=0;i<numbers.size();i++){
            d[numbers[i]]++;
            if(numbers[i]==0)
                continue;
            if(d[numbers[i]]>1)
                return false;
            if(numbers[i]>max)
                max=numbers[i];
            if(numbers[i]<min)
                min=numbers[i];
        }
        if(max-min>=5)
            return false;
        return true;
        // if(numbers.size()==0)
            // return false;    
        // int count=0;
        // for(int i=0;i<numbers.size();i++){
        //     for(int j=i+1;j<numbers.size();j++){
        //         if(numbers[i]>numbers[j]){
        //             int temp=numbers[i];
        //             numbers[i]=numbers[j];
        //             numbers[j]=temp;
        //         }
        //     }
        // }
        // int base=0;
        // for(int i=0;i<numbers.size();i++){
        //     if(numbers[i]==0)
        //         count++;
        //     if(base==0)
        //         base=numbers[i];
        //     else{
        //         if(numbers[i]==base)
        //             return false;
        //         count-=(numbers[i]-base-1);
        //         base=numbers[i];
        //         if(count<0)
        //             return false;
        //     }
        // }
        // return true;
    }
};
int main(){
    vector<int> num={1,3,2,6,4};
    Solution s;
    cout<<s.IsContinuous(num);
    return 0;
}