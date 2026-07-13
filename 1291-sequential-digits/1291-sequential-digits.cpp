class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
vector<int> first = {
    0, 0,
    12,
    123,
    1234,
    12345,
    123456,
    1234567,
    12345678,
    123456789
};

vector<int> add = {
    0, 0,
    11,
    111,
    1111,
    11111,
    111111,
    1111111,
    11111111,
    111111111
};

vector<int> ans;

for (int len = 2; len <= 9; len++) {
    int num = first[len];

    while (true) {
        if (num >= low && num <= high)
            ans.push_back(num);

        if (num % 10 == 9)
            break;

        num += add[len];
    }
   }

   return ans;
    }
};