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
    ListNode* reverse(ListNode* &head) {
        // for(auto temp = head; temp; temp = temp->next) cout<<temp->val<<" "; cout<<endl;
        ListNode *curr(head), *prev(nullptr), *tail(head);
        while(head) {
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        // for(auto temp = curr; temp; temp = temp->next) cout<<temp->val<<" "; cout<<endl;
        head = prev;
        return tail;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // reverseLL(head);return head;
        if(!head || k < 2) return head;

        node sentinel = new ListNode;
        sentinel->next = head;
        
        node unreversedHead(head), prevTail(sentinel);
        int i = 0;
        while(true) {
            node reversedHead(unreversedHead), prev(nullptr);
            for(i = 0; unreversedHead && (i < k); ++i) {
                prev = unreversedHead; //store k'th element to separate from remaining linked list
                unreversedHead = unreversedHead->next; //point to (k + 1)th element
            }
            if(i < k) break; //break when insufficient number of nodes left to reverse
            
            prev->next = nullptr; //break the group of k
            
            node tail = reverse(reversedHead);
            
            //link newly reversed group to already reversed linked list
            prevTail->next = reversedHead;
            //link newly reversed group to remaining/unreversed linked list
            tail->next = unreversedHead;
            //update tail of overall reversed linked list
            prevTail = tail;
        }
        return sentinel->next;
    }
};
