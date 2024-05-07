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
    int solve(ListNode* &head){
        if(head == NULL) return 0;
        int prev = head -> val;
        head -> val = solve(head -> next) + ((head -> val * 2) % 10);
        if(prev > 4){
            return 1;  
        }
        return 0;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = solve(head);
        if(carry){
            ListNode* temp = new ListNode(1);
            temp -> next = head;
            return temp;
        }
        return head;
    }
};