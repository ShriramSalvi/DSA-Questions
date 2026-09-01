/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next || !head->next->next)return {-1,-1};
        
        ListNode * temp = head;
        vector<int>nums;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        vector<int>help;

        for(int i=1;i<nums.size()-1;i++){
         
         if(
           (nums[i]>nums[i-1] && nums[i]>nums[i+1])
           ||
           (nums[i]<nums[i-1] && nums[i]<nums[i+1])

           )help.push_back(i);
         
        }

        if(help.size()<2)return {-1,-1};

        int minima = INT_MAX;
        int maxima = help[help.size()-1]-help[0];
        
        for(int i=1;i<help.size();i++){
            minima = min(minima,(help[i]-help[i-1]));
        }

        return {minima,maxima};
    }
};