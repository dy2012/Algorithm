

struct Node {
  int value;
  Node* left;
  Node* right;
};

int lca1(Node t, Node u, Node v) {
  int left = u.value;
  int right = v.value;

  if (left > right) {
    int temp = left;
    left = right;
    right = temp;
  }

  while(true) {
    if (t.value < left) {
        t = t.right;
    } else if (t.value > right) {
        t = t.left;
    } else {
        return t.value;
    }
  }
  return -1;
}
