class Solution {
public:
    bool checkIncreasing(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] < nums[i])
                count++;
        }

        return count == 1;
    }

    bool checkDecreasing(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] > nums[i])
                count++;
        }

        return count == 1;
    }

    int minOperations(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        if (n == 2)
            return nums[0] == 0 ? 0 : 1;

        bool inc = checkIncreasing(nums);
        bool dec = checkDecreasing(nums);

        if (!inc && !dec)
            return -1;

        int idxOfZero = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                idxOfZero = i;
                break;
            }
        }

        int leftDist = idxOfZero;
        int rightDist = n - idxOfZero;

        int ans = INT_MAX;

        if (inc) {
            ans = min(ans, leftDist);
            ans = min(ans, rightDist + 2);
        }

        if (dec) {
            ans = min(ans, rightDist);
            ans = min(ans, leftDist + 2);
        }

        return ans;
    }
};