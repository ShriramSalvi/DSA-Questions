#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    static constexpr long long MAX_K = 1000001L;

    long long countWays(const vector<int>& cnt) {
        int total = 0;
        for (int c : cnt) total += c;

        long long res = 1;
        int remaining = total;
        for (int i = 0; i < 26; ++i) {
            int c = cnt[i];
            for (int j = 1; j <= c; ++j) {
                res = res * (remaining - c + j) / j;
                if (res >= MAX_K) return MAX_K;
            }
            remaining -= c;
        }
        return min(res, MAX_K);
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        int half_len = 0;
        char mid = 0;

        for (int i = 0; i < 26; ++i) {
            half[i] = freq[i] / 2;
            half_len += half[i];
            if (freq[i] % 2 != 0) mid = (char)('a' + i);
        }

        if (countWays(half) < k) return "";

        string left = "";
        for (int pos = 0; pos < half_len; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (half[i] == 0) continue;

                half[i]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back((char)('a' + i));
                    break;
                } else {
                    k -= ways;
                    half[i]++; // Backtrack
                }
            }
        }

        string result = left;
        if (mid != 0) result += mid;
        string right = left;
        reverse(right.begin(), right.end());
        result += right;

        return result;
    }
};