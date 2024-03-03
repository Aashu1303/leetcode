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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == NULL || head == NULL){
            return nullptr;
        }

        ListNode* curr = head; // copy
        int size = 0;
        while(curr != NULL){
            size++;
            curr = curr -> next;
        }
        n = size - n;
        ListNode* prev = NULL; 
        curr = head;
        if(n == 0){
            return head -> next;
        }

        while(n--){
            prev = curr;
            curr = curr -> next;
        }
        
        prev -> next = curr -> next;

        return head;
    }
};