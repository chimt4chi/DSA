#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    for(auto i: arr) cout << i << " ";
    cout << endl;
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pIndx = partition(arr, low, high);
        quickSort(arr, low, pIndx - 1);
        quickSort(arr, pIndx+1, high);
    }
}

int main () {
    vector<int> arr{4,21,2,6,1};
    int low = 0, high = arr.size() - 1;
    quickSort(arr, low, high);
    // partition(arr, low, high);
    for(auto i: arr){
        cout << i << " ";
    }cout << endl;
    return 0;
}