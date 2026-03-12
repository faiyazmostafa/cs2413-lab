#include "student.h"

int middleNodeValue(struct ListNode *head) {
    // If the list is empty, return 0 or a default error value
    if (head == NULL) {
        return 0;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Fast moves two steps, slow moves one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is now at the middle (or the second middle for even lengths)
    return slow->val;
}