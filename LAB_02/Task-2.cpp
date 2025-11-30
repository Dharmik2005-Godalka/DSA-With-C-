#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1,3,5,7};
    int arr2[] = {2,4,6,8};

    int n=4, m=4;
    int result[n+m];
    int i=0,j=0,k=0;

    while(i<n && j<m){
        if(arr1[i] < arr2[j]) result[k++] = arr1[i++];
        else result[k++] = arr2[j++];
    }

    while(i<n) result[k++] = arr1[i++];
    while(j<m) result[k++] = arr2[j++];

    cout << "\nMerged Array: ";
    for(int x=0; x<n+m; x++)
        cout << result[x] << " ";
}

