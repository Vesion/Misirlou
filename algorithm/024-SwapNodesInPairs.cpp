#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

void print(ListNode* head) {
    if (head) {
        cout << head->val << " ";
        print(head->next);
    }
}

ListNode* append(ListNode* head, int val) {
    if (!head) head = new ListNode(val);
    else head->next = append(head->next, val);
    return head;
}


// Solution 1 : first split into two lists, then chain them
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* r = head->next;
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        ListNode *p1 = h1, *p2 = h2;
        while (p1 && p2 && p1->next && p2->next) {
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p2 = p2->next;
        }
        if (p1) p1->next = NULL;
        if (p2) p2->next = NULL;
        while (h1 && h2) {
            ListNode* t1 = h1->next;
            ListNode* t2 = h2->next;
            h2->next = h1;
            if (t2) h1->next = t2;
            h1 = t1;
            h2 = t2;
        }
        return r;
    }
};


// Solution 2 : use two-level-pointer
class Solution_2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode** pp = &head;
        ListNode* r = head->next;
        while (*pp && (*pp)->next) {
            ListNode* tmp = (*pp)->next;
            (*pp)->next = tmp->next; // cur's next points to next's next
            tmp->next = *pp; // next's next points to cur
            *pp = tmp; // pre's next points to next (the new cur), this is why we need two-level-pointer
            pp = &((*pp)->next->next);
        }
        return r;
    }
};


// Solution 3 : recursively
class Solution_3 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p = head->next;
        head->next = swapPairs(head->next->next);
        p->next = head;
        return p;
    }
};



int main() {
    Solution_2 s;
    ListNode* h = NULL;
    h = append(h, 1);
    h = append(h, 2);
    h = append(h, 3);
    h = append(h, 4);
    h = append(h, 5);
    print(h); cout << endl;
    h = s.swapPairs(h);
    print(h); cout << endl;
    return 0;
}

