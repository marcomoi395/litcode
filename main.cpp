#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static void backtracking(vector<vector<int>> &result, vector<int> &nums, vector<int> &cur, int i) {
        if(i == nums.size() + 1) return;
        result.push_back(cur);

        for (int j = i; j < nums.size(); j++) {
            cur.push_back(nums[j]);
            backtracking(result, nums, cur, j + 1);
            cur.pop_back();
        }
    }

    static vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> cur;
        backtracking(result, nums, cur, 0);
        return result;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x: nums) cin >> x;

    vector<vector<int>> res = Solution::subsets(nums);

    for (auto x: res) {
        for (int y: x) cout << y << ' ';
        cout << endl;
    }
}