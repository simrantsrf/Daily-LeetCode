//Linear Search
#include<iostream>
using namespace std;

int linearSearch (int arr[],int sz,int target){
    for (int i=0;i<sz;i++){
        if(arr[i]==target){
            return 1;//FOUND
        }
    }
    return -1;//NOT FOUND
}
int main(){
    int arr[]={2,3,4,5,6,7,8};
    int sz=7;
    int target=5;

    cout<<linearSearch(arr,sz,target)<<endl;
    return 0;
}