#include <iostream>
#include <vector>
using namespace std;

// class Solution {
//     vector<vector<int>> solutions;
    
//     void solve(vector<int>& nums, vector<bool>& used, vector<int>& sol){
//         if(sol.size() == nums.size()){
//             solutions.push_back(sol);
//             return;
//         }
        
//         for(int i=0; i<nums.size(); i++){
//             if(used[i]) continue;
//             used[i] = true;
//             sol.push_back(nums[i]);
//             solve(nums, used, sol);
//             sol.pop_back();
//             used[i] = false;
//         }
//     }
    
//     public:
//     vector<vector<int>> permute(vector<int>& nums){
//         vector<int> sol;
//         vector<bool> used(nums.size(), false);
//         solve(nums, used, sol);
//         return solutions;
//     }
    
//     void print() {
//         for(int i=0; i<solutions.size(); i++){
//             for(auto j: solutions[i]){
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//     }
// };


class Solution {
// Optimized
public:
    void permutation(vector<vector<int>> &ans, vector<int> &nums, int start, int end){
        if(start == end){
            ans.push_back(nums);
            return;
        }
        for(int i = start; i <= end; i++){
            swap(nums[start], nums[i]);
            permutation(ans, nums, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(ans, nums, 0, nums.size() - 1);
        for(int i=0; i<ans.size(); i++){
            for(auto j: ans[i]){
                cout << j << " ";
            }
            cout << endl;
        }
        return ans;
    }
};

int main () {
    vector<int> nums{1,2,3};
    Solution permutation;
    permutation.permute(nums);
    // permutation.print();
    return 0;
}