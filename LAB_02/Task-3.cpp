#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,3,4,2,5,3};
    int n = 6;

    bool visited[100] = {false};

    for(int i=0;i<n;i++){
        if(visited[arr[i]]){
            cout << "\nDuplicate: " << arr[i];
            break;
        }
        visited[arr[i]] = true;
    }
}

