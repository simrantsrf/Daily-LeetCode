//Brute force approach:sum of the subarray is done. Maximum is the winner.
#include<iostream>
#include<vector>
#include <climits>//added this for INT_MIN
using namespace std;

int main()
{
    int n =5;
    int arr[5]={1,-2,3,4,-6};

    int maxSum= INT_MIN;

    for(int st=0;st<n;st++){
        int currSum = 0;
        for(int end=st;end<n;end++){
            currSum += arr[end];
        }

    }
    cout<<"max of the subarray is: "<<maxSum<<endl;

    return 0;

}