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
    ListNode* reverse(ListNode *head , ListNode* slow){
        if(head -> next == slow || head == slow) return head;
        ListNode* prev = slow;
        ListNode* curr = head;
        while(curr != slow){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL){
            return true;
        }
        ListNode * slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        head = reverse(head , slow);
        if(fast) slow = slow -> next;
        ListNode* temp =  head;
        while(slow != NULL && head -> val == slow -> val){
            slow = slow -> next;
            head = head -> next;
        }
        
        //while(temp) cout << temp -> val , temp = temp -> next;

        if(slow == NULL) return true;

        return false;
    }
};