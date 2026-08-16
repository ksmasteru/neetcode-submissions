/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        Node *kopf = new Node(head->val);
        kopf->random = head->random;
        map<Node *, Node *> nodeMap;
        nodeMap.insert(std::pair<Node *, Node*>(head, kopf));
        head = head->next;
        Node* prev = kopf;
        Node* current;
        /* linking new list */
        while (head)
        {
            current = new Node(head->val);
            current->random = head->random;
            prev->next = current;
            nodeMap.insert(std::pair<Node *, Node*>(head, current));
            prev = current;
            head = head->next;
        }
        /* updating ranodm variable */
        Node *tmp = kopf;
        while (tmp)
        {
            /* each key[] has a value */
            if (tmp->random) /*avoid null */
            {
                tmp->random = nodeMap[tmp->random];
            }
            tmp = tmp->next;
        }
        return (kopf);
    }
};


// map : key -- value : index of node : address of node.

// old adress : new adress.
/* while {
    map<old *p, new *p> : this . new adress. to be filled.
        this loop simply creates the a a copy  random is not to be changed.
        key of the map old adress, value new address.
} */
/*
    second while loop is for assignning the random pointer.
        random : fetch in the map the val of this key :: update it.
*/