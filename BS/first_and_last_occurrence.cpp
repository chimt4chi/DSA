#include <bits/stdc++.h>
using namespace std;

vector<int> bS(vector<int>& arr, int target){
    int low = 0;
    int high = arr.size() - 1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target){
            first = mid;
            high--;
            // high = mid-1;
            // low = mid + 1;
        }else if(arr[mid] < target){
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    
    low = 0, high = arr.size() - 1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target){
            last = mid;
            // high = mid-1;
            // low = mid + 1;
            low++;
        }else if(arr[mid] < target){
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    
    return {first, last};
}

int main () {
    int target = 3;
    vector<int> arr{0,0,0,0,1,2,2,4,5,6,8};
    vector<int> ans = bS(arr, target);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}