#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    // If the list is empty or has only one node, no swaps are possible
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // A 'dummy' node makes it easier to handle the head of the list after the first swap
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        // Identify the two nodes to be swapped
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;

        // Perform the swap by rewiring the pointers
        // 1. Point the first node to the node following the pair
        first->next = second->next;
        // 2. Point the second node back to the first node
        second->next = first;
        // 3. Connect the previous part of the list to the new first node of this pair
        prev->next = second;

        // Move 'prev' forward two steps (to the end of the current pair)
        prev = first;
    }

    // Return the new head, which is stored in dummy.next
    return dummy.next;
}