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
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
using node = ListNode*;

class Solution {
    node reverse(node &head) {
        node curr(head), prev(nullptr), tail(head);
        while(head) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        head = prev;
        // cout<<"Reversed ll : \n\t";
        // auto temp(head); while(temp) {cout<<temp->val<<" "; temp=temp->next;} cout<<endl;
        return tail;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // reverse(head); return head;
        if(!head || k < 2) return head;
        node sentinel = new ListNode;//(2895, head);
        sentinel->next = head;

        node prevTail(sentinel), unreversedHead(head), sublistTail(nullptr);
        int i = 0;
        while(true) {
            node sublistHead = unreversedHead;
            for(i = 0; unreversedHead && i < k; ++i) {
                sublistTail = unreversedHead;
                unreversedHead = unreversedHead->next;
            }
            if(i < k) break;

            //disconnect sublist from unreversed list
            sublistTail->next = nullptr; 
            //reverse sublist
            auto newTail = reverse(sublistHead); 
            cout<<sublistHead->val<<" : "<<newTail->val<<endl;
            //connect sublist with previously reversed list
            prevTail->next = sublistHead;
            //update prev tail so that next sublist connects to updated reversed lists end
            prevTail = newTail; 
            //connect reversed list with unsorted list so if we exit, it is still joint
            newTail->next = unreversedHead;
        }
        return sentinel->next;
    }
};
