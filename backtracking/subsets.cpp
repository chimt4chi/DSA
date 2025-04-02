#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int index){
    if(index == nums.size()){
        ans.push_back(nums[curr]);
        return;
    }
    
    curr.push_back(nums[index]);
    helper(nums, ans, curr, index + 1);
    curr.pop_back();
    helper(nums, ans, curr, index + 1);
    
}

vector<vector<int>> susets(vector<int>& nums) {
    vector<vector<int>> ans{};
    vector<int> curr{};
    helper(nums, ans, curr, 0);
    return ans;
}

int main () {
return 0;
}