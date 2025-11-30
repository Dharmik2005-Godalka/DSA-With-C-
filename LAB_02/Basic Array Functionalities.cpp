#include <iostream>
using namespace std;

const int MAX = 100;

void traverse(int arr[], int n) {
    cout << "\nArray Elements: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int searchElement(int arr[], int n, int key) {
    for(int i=0; i<n; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

void insertElement(int arr[], int &n, int pos, int value) {
    if(pos < 0 || pos > n) {
        cout << "Invalid Position!\n";
        return;
    }
    for(int i=n; i>pos; i--)
        arr[i] = arr[i-1];
    arr[pos] = value;
    n++;
}

void deleteElement(int arr[], int &n, int pos) {
    if(pos < 0 || pos >= n) {
        cout << "Invalid Position!\n";
        return;
    }
    for(int i=pos; i<n-1; i++)
        arr[i] = arr[i+1];
    n--;
}

void deleteAllOccurrences(int arr[], int &n, int key) {
    int j = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] != key)
            arr[j++] = arr[i];
    }
    n = j;
}

void frequencyCount(int arr[], int n) {
    cout << "\nFrequency of elements:\n";
    bool visited[MAX] = {false};

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            int count = 1;
            for(int j=i+1; j<n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    visited[j] = true;
                }
            }
            cout << arr[i] << " ? " << count << " times\n";
        }
    }
}

int main() {
    int arr[MAX], n, choice, key, pos, value;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    traverse(arr, n);

    cout << "\nEnter element to search: ";
    cin >> key;
    int index = searchElement(arr, n, key);
    (index != -1) ? cout << "Found at index " << index << endl : cout << "Not Found!\n";

    cout << "\nInsert Element: Enter position and value: ";
    cin >> pos >> value;
    insertElement(arr, n, pos, value);
    traverse(arr, n);

    cout << "\nDelete Element: Enter position: ";
    cin >> pos;
    deleteElement(arr, n, pos);
    traverse(arr, n);

    cout << "\nDelete all occurrences of value: ";
    cin >> key;
    deleteAllOccurrences(arr, n, key);
    traverse(arr, n);

    frequencyCount(arr, n);

    return 0;
}

