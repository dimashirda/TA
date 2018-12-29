#include <iostream>
#include <thread>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

using namespace std;

struct Node {
    int weight, size, priority;
    char data;
    Node *left, *right;
    Node() {
        left = right = NULL;
        weight = 0;
    }

    void update() {
        weight = left->weight + right->weight + 1;
    }

    void bst_node() {
        size = (left ? left->weight + 1 : 1);
    }
};
Node* mainRoot = NULL;

class Rope {
public:
    Node* root;
    Rope() {
        root = NULL;
    }

    Rope(Node* init) {
        root = init;
    }

    Node* new_node(char ch) {
        Node* newNode = new Node();
        newNode->left = newNode->right = NULL;
        newNode->weight = 1;
        newNode->size = 1;
        newNode->priority = rand()%100;
        newNode->data = ch;
        return newNode;
    }

    Node* new_node(char ch, Node* left, Node* right) {
        Node* newNode = new Node();
        newNode->left = left;
        newNode->right = right;
        newNode->update();
        newNode->bst_node();
        newNode->priority = rand()%100;
        newNode->data = ch;
        return newNode;
    }

    Node* leftRotate(Node* x) {
        Node *y = x->right, *T = y->left;
        y->left = x;
        x->right = T;
        return y;
    }

    Node* rightRotate(Node* y) {
        Node *x = y->left , *T = x->right;
        x->right = y;
        y->left = T;
        return x;
    }

    void init() {
        mainRoot = new Node();
        root = mainRoot;
        root->left = root->right = NULL;
        root->weight = 0;
    }

    Node* build(char* start, char* end) {
        if ( start == end ) return root;
        assert(start < end );
        char* mid = start + (end - start)/2;
        return new_node(*mid, build(start, mid), build(mid+1, end));
    }

    pair<Node*, Node*> split(Node* current, int pos) {
        if ( pos == 0 ) return make_pair(mainRoot, current);
        int idx = current->left->weight;

        if ( idx >= pos ) {
            pair<Node*, Node*> new_rope = split(current->left, pos);
            return make_pair(new_rope.first, new_node(current->data, new_rope.second, current->right));
        } else {
            pair<Node*, Node*> new_rope = split(current->right, pos - idx - 1);
            return make_pair(new_node(current->data, current->left, new_rope.first), new_rope.second);
        }
    }

    Node* merge(Node* mainRope, Node* secondRope) {
        if ( mainRope == mainRoot ) return secondRope;
        if ( secondRope == mainRoot ) return mainRope;
        if ( mainRope->priority < secondRope->priority ) {
            return new_node(mainRope->data, mainRope->left, merge(mainRope->right, secondRope));
        } else {
            return new_node(secondRope->data, merge(mainRope, secondRope->left), secondRope->right);
        }
    }

    Node* insert(int pos, char str[]) {
        Node* current = build(str, str + strlen(str));
        pair<Node*, Node*> new_rope = split(root, pos);
        return merge(new_rope.first, merge(current, new_rope.second));
    }

    Node* mutable_begin(int pos, int len) {
        pair<Node*, Node*> first_rope = split(root, pos);
        pair<Node*, Node*> second_rope = split(first_rope.second, len);
        return merge(second_rope.first, merge(first_rope.first, second_rope.second));
    }

    Node* mutable_end(int pos, int len) {
        pair<Node*, Node*> first_rope = split(root, pos);
        pair<Node*, Node*> second_rope = split(first_rope.second, len);
        return merge(merge(first_rope.first, second_rope.second), second_rope.first);
    }

    void print(int pos) {
        pair<Node*, Node*> first_rope = split(root, pos);
        pair<Node*, Node*> second_rope = split(first_rope.second, 1);
        putchar(second_rope.first->data);
        return;
    }

    void inorder(Node* current) {
        if (current != mainRoot) {
            cout << "kiri" << endl;
            inorder(current->left);
            cout << "priority " << current->priority << " weight: "<< current->weight << " | string: "
                << current->data << " size " << current->size << endl;
            if (current->left)
                cout << " | left child: " << current->left->weight;
            if (current->right)
                cout << " | right child: " << current->right->weight;
            cout << endl;
            cout << "kanan" << endl;
            inorder(current->right);
        }
    }

    void inorder() {
        inorder(root);
    }

    Node* index(Node* current, int pos) {
        int idx = current->size;
        if ( pos >= idx ) {
            return index(current->right, pos - current->size - 1);
        } else {
            return index(current->left, pos);
        }
        if ( pos == current->size ) {
            putchar(current->data);
            return NULL;
        }
    }

    void index(int pos) {
        index(root, pos);
    }

    Node* printIndex(Node* now, int pos) {        
        int idx = now->weight;
 
        if (now->right) {
            idx -= now->right->weight;
        }
 
        // Case 1: current node is the target
        if (pos == idx - 1) {
            putchar(now->data);
            return NULL;
        }
 
        // Case 2: The target is in the left of current node
        if (idx > pos) {
            return printIndex(now->left, pos);
        }
 
        if (idx <= pos) {
            return printIndex(now->right, pos - now->left->weight - 1);
        }
    }
 
    void printIndex(int pos) {
        printIndex(root, pos);
 
        return;
    }
};

Rope r[10005];
char str[10005];
int Q, vnow = 0;

int main() {
    srand(time(NULL));
    r[vnow].init();

    scanf("%s", str);
    r[vnow].root = r[vnow].insert(0, str);

    scanf("%d", &Q);
    // r[vnow].inorder();
    while ( Q-- ) {
        int x, y, type;
        scanf("%d", &type);
        if ( type == 3 ) {
            scanf("%d", &y);
            // r[vnow].print(y);
            r[vnow].printIndex(y);
            // r[vnow].index(y);
            vnow++;
            r[vnow].root = r[vnow-1].root;
            printf("\n");
        } else if ( type == 4 ) {
            scanf("%d%d", &x, &y);
            // r[x].print(y);
            r[x].printIndex(y);
            vnow++;
            r[vnow].root = r[vnow-1].root;
            printf("\n");
        } else {
            scanf("%d%d", &x, &y);
            if ( type == 1) {
                vnow++;
                r[vnow].root = r[vnow-1].mutable_begin(x, y - x + 1);
                // r[vnow].inorder();
            } else {
                vnow++;
                r[vnow] = r[vnow-1].mutable_end(x, y - x + 1);
                // r[vnow].inorder();
            }
        }
    }
    return 0;
}