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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (
            head == nullptr ||
            head->next == nullptr ||
            k == 1
        ) return head;


        ListNode *start = head, *end = head;

        ListNode *start_prev = nullptr, *end_prev = nullptr;

        while (true) {

            int cnt = 1;
            while (end != nullptr && cnt < k) {
                end_prev = end;
                end = end->next;
                cnt++;
            }

            if (end == nullptr) break;

            ListNode* prev = start;
            for (auto i = start->next; i != end;) {
                auto nxt = i->next;
                i->next = prev;
                prev = i;
                i = nxt;
            }

            if (start_prev != nullptr) {
                start_prev->next = end;
            } else {
                head = end;
            }

            start->next = end->next;

            end->next = end_prev;

            start_prev = start;
            start = start->next;
            end = start;
        }

        return head;
    }
};