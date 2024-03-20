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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list1;
        ListNode* temp1 = list2;
        ListNode* temp2 = list2;

        while(a > 1){
            curr1 = curr1 -> next;
            a--;
        }
        while(b > 0){
            curr2 = curr2 -> next;
            b--;
        }

        while(temp2 -> next != NULL){
            temp2 = temp2 -> next;
        }
        
        curr1 -> next = temp1;
        temp2 -> next = curr2 -> next;

        return list1;
    }
};