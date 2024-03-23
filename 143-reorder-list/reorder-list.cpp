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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return;
        ListNode * curr = head;
        stack<ListNode*> st;
        int size=  0;
        while(curr != NULL){
            st.push(curr);
            curr = curr -> next;
            size++;
        }
        size = size/2;
        curr = head;
        while(size--){
            ListNode* next = curr -> next;
            ListNode* top = st.top();
            curr -> next = top;
            top -> next = next;
            cout << curr -> val << " " << top -> val << endl;
            curr = next;
            st.pop();
        }

        curr -> next  = NULL;
    }
};