/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    
    while (head != NULL) {
        if (head->next == NULL || head->val != head->next->val) {
            current->next = head;
            current = current->next;
            head = head->next;
        } else {
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            head = head->next;
        }
    }
    
    current->next = NULL;
    return dummy->next;
}


