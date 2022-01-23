//Duplicates may present in array
#include<bits/stdc++.h>

using namespace std;
class Solution {
  private:
    void recurPermute(int idx, vector <int> &nums, vector<vector<int>> &ans) {
        if (idx == nums.size()) {ans.push_back(nums);return;}

        for (int i = idx; i < nums.size(); i++) {
            if(i==idx || nums[i-1]!=nums[i]){
                swap(nums[idx], nums[i]);
                recurPermute(idx + 1, nums, ans);
                swap(nums[idx], nums[i]);
            }
        }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
        vector < vector < int >> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> v {1,2,2};
    sort(v.begin(),v.end());
    vector<vector<int>> sum = obj.permute(v);

    cout << "All Permutations are" << endl;
    for (int i = 0; i < sum.size(); i++) {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}