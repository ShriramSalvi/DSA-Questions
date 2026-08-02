class Solution {
public:

    bool helper(int left,
                int right,
                int score1,
                int score2,
                bool player1Turn,
                vector<int>& nums)
    {
        if(left > right)
            return score1 >= score2;

        if(player1Turn)
        {
            // Player 1 tries to find at least one winning move.
            return helper(left + 1, right,
                          score1 + nums[left],
                          score2,
                          false,
                          nums)
                ||
                   helper(left, right - 1,
                          score1 + nums[right],
                          score2,
                          false,
                          nums);
        }
        else
        {
            // Player 2 tries to make Player 1 lose.
            return helper(left + 1, right,
                          score1,
                          score2 + nums[left],
                          true,
                          nums)
                &&
                   helper(left, right - 1,
                          score1,
                          score2 + nums[right],
                          true,
                          nums);
        }
    }

    bool predictTheWinner(vector<int>& nums) {

        return helper(0,
                      nums.size() - 1,
                      0,
                      0,
                      true,
                      nums);
    }
};