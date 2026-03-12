#include "student.h"

bool hasCycle(struct ListNode *head) {
    // If the list is empty or has only one node, no cycle is possible
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head; // The "Tortoise" moves 1 step
    struct ListNode *fast = head; // The "Hare" moves 2 steps

    // Iterate as long as the fast pointer can move forward
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        // If the fast pointer laps the slow pointer, a cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end (NULL), there is no cycle
    return false;
}