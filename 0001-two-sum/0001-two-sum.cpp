class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
    void main() {
        vector<int> num = {2, 7, 11, 15};
        int target = 9;
        vector<int> ans = twoSum(num, target);
        cout << ans[0] << " " << ans[1] << endl;
    }
};