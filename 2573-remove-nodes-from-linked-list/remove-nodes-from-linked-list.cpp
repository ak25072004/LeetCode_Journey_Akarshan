/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
         
        stack<ListNode*> nodeval;
        ListNode* temp = head;
        
        while(temp){

            while(!nodeval.empty() && nodeval.top()->val < temp->val){
                nodeval.pop();
            }
            
            nodeval.push(temp);
            temp = temp->next;
        }
        
        ListNode* prev_node = nullptr;
        while(!nodeval.empty()){
            ListNode* node = nodeval.top();
            nodeval.pop();
            
            node->next = prev_node;
            prev_node = node;
        }
        
        return prev_node;
    }
};