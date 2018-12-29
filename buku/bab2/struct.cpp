struct Node {
  Node *left, *right;
  int size;
  char value; 
  Node(char v);
  Node* update();
};