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
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        ListNode* curr = head;
        stack<ListNode*> st;
        while(curr != NULL){
            int temp = curr -> val;
            while(!st.empty() && (st.top()->val) < temp){
                st.pop();
            }
            st.push(curr);
            curr = curr -> next;
        }

        ListNode* ans = NULL;
        while(!st.empty()){
            ListNode * temp = st.top();
            cout << temp -> val << " ";
            st.pop();
            temp -> next = ans;
            ans = temp;
        }

        return ans;
    }
};