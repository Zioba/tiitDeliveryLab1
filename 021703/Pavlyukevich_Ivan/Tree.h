#pragma once
const int t = 3;

struct Node {
    int keys[2 * t];
    Node* children[(2 * t) + 1];
    Node* parent;
    int keycount;
    int childrencount;
    bool leaf;
};

class BTree
{
private:
    Node* root;
    void insert_to_node(int key, Node* node);
    void split(Node* node);
    void deletenode(Node* node);
    void sort(Node* node);
    bool searchKey(int key, Node* node);
    void remove(int key, Node* node);
    void removeFromNode(int key, Node* node);
    void removeLeaf(int key, Node* node);
    void connect(Node* node, Node* othernode, int mode);
    void repair(Node* node);
    void display(Node* node);
    void removeBody(int key, Node* node);

public:
    BTree() { root = nullptr; } //конструктор
    ~BTree() { if (root != nullptr) deletenode(root); } //деструктор
    void insert(int key);
    bool search(int key);
    void remove(int key);
    void show();
};