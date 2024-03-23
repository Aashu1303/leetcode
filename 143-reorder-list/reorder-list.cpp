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
    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return;
        ListNode * temp = head;
        while(temp -> next != NULL){
            temp -> next = reverse(temp -> next);
            temp = temp -> next;
        }
    }
};