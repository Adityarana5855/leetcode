class Solution {
public:
    vector<vector<int>>result;
    void backtrack(int index,vector<int>&nums,vector<int>&path){
        result.push_back(path);

        for(int i = index;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(i+1,nums,path);
            path.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        backtrack(0,nums,path);

        return result;
        
    }
};