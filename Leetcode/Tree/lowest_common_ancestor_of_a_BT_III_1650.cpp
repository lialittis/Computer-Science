/* VIP */

/* Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA). */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

/* First Try :
 * The parent reference helps a node to find its parent quickly
 * 
 */

Node* lowestCommonAncestor(Node* p, Node* q) {
    Node* a = p, *b = q;
    while(a != b) {
        if(a==nullptr) a = q;
        else a = a->parent;
        if(b==nullptr) b = p;
        else b = b->parent;
    }

    return a;
}