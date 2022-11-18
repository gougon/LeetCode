#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* oddCur = odd;
        ListNode* evenCur = even;
        ListNode* cur = even->next;
        bool isOdd = true;
        while (cur) {
            ListNode* linkNode = isOdd ? oddCur : evenCur;
            linkNode->next = cur;
            linkNode = linkNode->next;
            
            cur = cur->next;
            isOdd = !isOdd;
        }
        oddCur->next = even;
        evenCur->next = nullptr;
        return odd;
    }
};

int main(int argc, char *argv[]) {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(7);

    Solution sol = Solution();
    head = sol.oddEvenList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
