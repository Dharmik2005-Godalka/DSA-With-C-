#include <iostream>
using namespace std;

int main(){
    int arr[] = {2,7,11,15};
    int n = 4, target = 9;

    bool found=false;
    int idx1=-1, idx2=-1;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == target){
                found = true;
                idx1=i; idx2=j;
            }
        }
    }

    if(found){
        cout << "\nYES, indices: " << idx1 << ", " << idx2;
    } else {
        cout << "\nNO, {-1, -1}";
    }
}

