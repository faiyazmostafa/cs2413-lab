#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    // Return head immediately if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next_node = NULL;

    while (curr != NULL) {
        // 1. Temporarily store the next node
        next_node = curr->next;
        
        // 2. Reverse the current node's pointer to point to the previous node
        curr->next = prev;
        
        // 3. Move the 'prev' and 'curr' pointers one step forward
        prev = curr;
        curr = next_node;
    }

    // After the loop, 'prev' is the new head of the reversed list
    return prev;
}