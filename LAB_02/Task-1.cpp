#include <iostream>
using namespace std;

int main() {
    int arr[] = {2,0,1,2,1,0,0,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int count0=0, count1=0, count2=0;

    for(int i=0;i<n;i++){
        if(arr[i]==0) count0++;
        else if(arr[i]==1) count1++;
        else count2++;
    }

    int k=0;
    while(count0--) arr[k++] = 0;
    while(count1--) arr[k++] = 1;
    while(count2--) arr[k++] = 2;

    cout << "\nSorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

