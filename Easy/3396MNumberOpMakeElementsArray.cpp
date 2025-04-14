class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int k = 0;
        while (true) {
            bool remove = false;
            map<int, int> m;
            for (int num : nums) {
                m[num]++;
                if (m[num] >= 2) {
                    remove = true;
                    break;
                }
            }
            if (remove) {
                int toRemove = min(3, (int)nums.size());
                nums.erase(nums.begin(), nums.begin() + toRemove);
                k++;
            } else {
                break;
            }
        }
        return k;
    }
};