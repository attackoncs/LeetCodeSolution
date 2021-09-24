/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* dummy = new Node(0);
        dummy->next = head;
        for (; head != NULL; head = head->next) {
            if (head->child != NULL) {
                //理解起来不难，但写起来不好写
                //容易忘记孩子节点和前节点赋值
                Node* tmp = head->next;
                Node* child = head->child;
                head->next = child;
                child->prev = head;
                head->child = NULL;
                Node* last = head;
                while (last->next != NULL) last = last->next;
                last->next = tmp;
                if (tmp != NULL) tmp->prev = last;
            }
        }
        return dummy->next;
    }
};