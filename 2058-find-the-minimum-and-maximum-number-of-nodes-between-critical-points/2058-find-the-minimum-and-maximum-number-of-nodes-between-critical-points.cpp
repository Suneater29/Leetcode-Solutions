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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        int firstCriticalIndex = -1;
        int prevCriticalIndex = -1;
        int minDistance = INT_MAX;
        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            bool isMaxima = (curr->val > prev->val) && (curr->val > nextNode->val);
            bool isMinima = (curr->val < prev->val) && (curr->val < nextNode->val);
            if (isMaxima || isMinima) {
                if (firstCriticalIndex == -1) {
                    firstCriticalIndex = index;
                } else {
                    minDistance = min(minDistance, index - prevCriticalIndex);
                }
                prevCriticalIndex = index;
            }
            prev = curr;
            curr = nextNode;
            index++;
        }
        if (firstCriticalIndex == -1 || prevCriticalIndex == firstCriticalIndex) {
            return {-1, -1};
        }
        int maxDistance = prevCriticalIndex - firstCriticalIndex;
        return {minDistance, maxDistance};
    }
};