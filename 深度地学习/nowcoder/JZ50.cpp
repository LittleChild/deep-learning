#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        // if(length<=1){
        //     return false;
        // }
        // map<int,int>dic;
        // for(int i=0;i<length;i++){
        //     dic[numbers[i]]++;
        //     if(dic[numbers[i]]>1){
        //         duplication[0]=numbers[i];
        //         return true;
        //     }
        // }
        // return false;
        for(int i=0;i<length;i++){
           int index=numbers[i];
           if(index<0){
               index+=length;
           }
           if(numbers[index]<0){
               duplication[0]=numbers[index]+length;
               return true;
           }
           numbers[index]-=length;
        }
        return false;
            // int index = numbers[i];
            // if (index >= length) {
            //     index -= length;
            // }   
            // if (numbers[index] >= length) {
            //     duplication[0]=numbers[index]-length;
            //     return index;
            // }   
            // numbers[index] = numbers[index] + length;
        // }   
        // return 0 ; 
    }
};

int main(){
    Solution s;
    int numbers[]={2,1,3,1,4};
    int duplication[1];
    cout<<s.duplicate(numbers,7,duplication);
    return 0;
}