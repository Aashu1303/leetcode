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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * curr = new ListNode(0 , head);
        unordered_map<int,ListNode*> mp;
        int preSum = 0;

        for(ListNode* prev = curr ; prev != NULL ; prev = prev->next){
            preSum += prev -> val;
            mp[preSum] = prev;
        }
        preSum = 0;
        for(ListNode* prev = curr ; prev != NULL ; prev = prev->next){
            preSum += prev -> val;
            prev -> next = mp[preSum] -> next;
        }

        return curr -> next;
    }
};