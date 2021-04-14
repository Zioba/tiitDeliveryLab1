// Driver code
#include"NTree.h";
int main() {
    struct node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 2);

    cout << "Inorder traversal: ";
    inorder(root);

    print2D(root);
    root = deleteNode(root, 8);
	cout << "\nAfter deleting \n";
    print2D(root);
	
    cout << endl << endl;
    root = insert(root, 5);
	cout << "\nAfter insertion \n";
    print2D(root);
    //inorder(root);
}