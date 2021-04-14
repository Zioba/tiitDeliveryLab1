#include"NTree.h";
// Inorder Traversal
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left_child = temp->right_sibling = NULL;
    return temp;
}
void inorder(struct node* root) {
    if (root != NULL) {
        // Traverse left_child
        inorder(root->left_child);

        // Traverse root
        cout << root->key << " -> ";

        // Traverse right_sibling
        inorder(root->right_sibling);
    }
};
void print2DUtil(node* root, int space)
{
    // Base case 
    if (root == NULL)
        return;

    // Increase distance between levels 
    space += 10;

    // Process right_sibling child first 
    print2DUtil(root->right_sibling, space);

    // Print current node after space 
    // count 
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    // Process left_child child 
    print2DUtil(root->left_child, space);
};

// Wrapper over print2DUtil() 
void print2D(node* root)
{
    // Pass initial space count as 0 
    print2DUtil(root, 0);
}

// Insert a node
struct node* insert(struct node* node, int key) {
    // Return a new node if the tree is empty
    if (node == NULL) return newNode(key);

    // Traverse to the right_sibling place and insert the node
    if (key < node->key)
        node->left_child = insert(node->left_child, key);
    else
        node->right_sibling = insert(node->right_sibling, key);

    return node;
}

// Find the inorder successor
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // Find the left_childmost leaf
    while (current && current->left_child != NULL)
        current = current->left_child;

    return current;
}

// Deleting a node
node* deleteNode(struct node* root, int key) {
    // Return if the tree is empty
    if (root == NULL) return root;

    // Find the node to be deleted
    if (key < root->key)
        root->left_child = deleteNode(root->left_child, key);
    else if (key > root->key)
        root->right_sibling = deleteNode(root->right_sibling, key);
    else {
        // If the node is with only one child or no child
        if (root->left_child == NULL) {
            struct node* temp = root->right_sibling;
            free(root);
            return temp;
        }
        else if (root->right_sibling == NULL) {
            struct node* temp = root->left_child;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node* temp=minValueNode(root->right_sibling);

        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;

        // Delete the inorder successor
        root->right_sibling = deleteNode(root->right_sibling, temp->key);
    }
    return root;
}

