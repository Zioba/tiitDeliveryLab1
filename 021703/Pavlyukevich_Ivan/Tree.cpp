#include <iostream>
#include "Tree.h"


void BTree::deletenode(Node* node) {
    if (node != nullptr)
    {
        for (int i = 0; i < (2 * t); i++)
        {
            if (node->children[i] != nullptr)
            {
                deletenode(node->children[i]);
            }
            else
            {
                delete(node); break;
            }
        }
    }
}//Удаление узла - рекурсивное удаление всех детей, потом удаление узла

void BTree::insert_to_node(int key, Node* node)
{
    node->keys[node->keycount] = key;
    node->keycount = node->keycount++;
    sort(node);
}
//Добавление ключа в узел

void BTree::sort(Node* node)
{
    int reserve;
    for (int i = 0; i < (2 * t - 1); i++)
    {
        for (int j = i + 1; j < 2 * t; j++)
        {
            if ((node->keys[i] != 0) && (node->keys[j] != 0))
            {
                if ((node->keys[i]) > (node->keys[j]))
                {
                    reserve = node->keys[i];
                    node->keys[i] = node->keys[j];
                    node->keys[j] = reserve;
                }
            }
            else break;
        }
    }
}
//Сортировка ключи по возрастанию

void BTree::insert(int key)
{
    if (this->search(key)) { std::cout << "\nThis element is already present at the tree\n"; return; }
    if (root == nullptr)
    {
        Node* newRoot = new Node;
        newRoot->keys[0] = key;
        for (int j = 1; j < 2 * t; j++)
        {
            newRoot->keys[j] = 0;
        }
        for (int i = 0; i < 2 * t + 1; i++)
        {
            newRoot->children[i] = nullptr;
        }

        newRoot->keycount = 1;
        newRoot->childrencount = 0;
        newRoot->parent = nullptr;
        newRoot->leaf = true;
        root = newRoot;
    }
    else
    {
        Node* ptr = root;
        while (!ptr->leaf)
        {
            for (int i = 0; i < (2 * t); i++)
            {
                if (ptr->keys[i] != 0)
                {
                    if (key < ptr->keys[i])
                    {
                        ptr = ptr->children[i];
                        break;
                    }
                    if ((ptr->keys[i + 1] == 0) && (key > ptr->keys[i]))
                    {
                        ptr = ptr->children[i + 1];
                        break;
                    }
                }
                else break;
            }
        }
        insert_to_node(key, ptr);


        if (ptr != nullptr)
        {
            while (ptr->keycount == 2 * t)
            {
                if (ptr == root)
                {
                    split(ptr);
                    break;
                }
                else
                {
                    split(ptr);
                    if (ptr != root)
                        ptr = ptr->parent;
                }
            }
        }
    }
}

void BTree::split(Node* node)
{
    if (node->keycount < (2 * t - 1)) return;

    //ЛЕВЫЙ РЕБЁНОК
    Node* child1 = new Node;
    int j, i;
    for (j = 0; j < t - 1; j++) child1->keys[j] = node->keys[j];
    for (j = t - 1; j < 2 * t; j++) child1->keys[j] = 0;
    child1->keycount = t - 1;
    if (node->childrencount != 0)
    {
        for (i = 0; i < t; i++)
        {
            child1->children[i] = node->children[i];
            child1->children[i]->parent = child1;
        }
        for (i = t; i <= (2 * t); i++)
            child1->children[i] = nullptr;
        child1->leaf = false;
        child1->childrencount = t - 1;
    }
    else
    {
        child1->leaf = true;
        child1->childrencount = 0;
        for (i = 0; i < 2 * t + 1; i++) child1->children[i] = nullptr;
    }
    //

    //ПРАВЫЙ РЕБЁНОК
    Node* child2 = new Node;
    for (j = 0; j < t; j++) child2->keys[j] = node->keys[j + t];
    for (j = t; j < 2 * t; j++) child2->keys[j] = 0;
    child2->keycount = t;
    if (node->childrencount != 0)
    {
        for (i = 0; i < t + 1; i++)
        {
            child2->children[i] = node->children[i + t];
            child2->children[i]->parent = child2;
        }
        for (i = t + 1; i < 2 * t + 1; i++) child2->children[i] = nullptr;
        child2->leaf = false;
        child2->childrencount = t;
    }
    else
    {
        child2->leaf = true;
        child2->childrencount = 0;
        for (i = 0; i < 2 * t + 1; i++) child2->children[i] = nullptr;
    }

    //ИЗМЕНЕНИЕ РОДИТЕЛЯ
    if (node->parent == nullptr)
    {
        node->keys[0] = node->keys[t - 1];
        for (j = 1; j < 2 * t; j++) node->keys[j] = 0;
        node->children[0] = child1;
        node->children[1] = child2;
        for (i = 2; i < 2 * t + 1; i++) node->children[i] = nullptr;
        node->leaf = false;
        node->keycount = 1;
        node->childrencount = 2;
        child1->parent = node;
        child2->parent = node;
    }
    else
    {
        insert_to_node(node->keys[t - 1], node->parent);
        for (i = 0; i <= (2 * t); i++)
        {
            if (node->parent->children[i] == node) node->parent->children[i] = nullptr;
        }
        for (i = 0; i <= (2 * t); i++)
        {
            if (node->parent->children[i] == nullptr)
            {
                for (j = (2 * t); j > (i + 1); j--) node->parent->children[j] = node->parent->children[j - 1];
                node->parent->children[i + 1] = child2;
                node->parent->children[i] = child1;
                break;
            }
        }
        child1->parent = node->parent;
        child2->parent = node->parent;
        node->parent->leaf = false;
        //delete node;
    }
}

void BTree::connect(Node* node, Node* othernode, int mode)
{
    if (node == nullptr) return;
    for (int i = 0; i < othernode->keycount; i++)
    {
        node->keys[node->keycount] = othernode->keys[i];
        if (mode == 1)
            node->children[node->keycount] = othernode->children[i];
        if (mode == 2)
            node->children[node->keycount] = othernode->children[i + 1];
        node->keycount = node->keycount + 1;
    }
    if (mode == 1) node->children[node->keycount] = othernode->children[othernode->keycount];

    for (int j = 0; j <= node->keycount; j++)
    {
        if (node->children[j] == nullptr) break;
        node->children[j]->parent = node;
    }
    delete othernode;
}

bool BTree::search(int key)
{
    return searchKey(key, this->root);
}

bool BTree::searchKey(int key, Node* node)
{
    int i;
    if (node != nullptr)
    {
        if (!node->leaf)
        {
            for (i = 0; i < 2 * t; i++)
            {
                if (node->keys[i] != 0)
                {
                    if (key == node->keys[i]) return true;
                    if ((key < node->keys[i]))
                    {
                        return searchKey(key, node->children[i]);
                        break;
                    }
                }
                else break;
            }
            return searchKey(key, node->children[i]);
        }
        else
        {
            for (int j = 0; j < 2 * t; j++)
            {
                if (key == node->keys[j]) return true;
            }
            return false;
        }
    }
    else return false;
}

void BTree::removeFromNode(int key, Node* node)
{
    for (int i = 0; i < node->keycount; i++)
    {
        if (node->keys[i] == key)
        {
            for (int j = i; j < node->keycount; j++)
            {
                node->keys[j] = node->keys[j + 1];
                node->children[j] = node->children[j + 1];
            }
            node->keys[node->keycount - 1] = 0;
            node->children[node->keycount - 1] = node->children[node->keycount];
            node->children[node->keycount] = nullptr;
            break;
        }
    }
    node->keycount--;
}

void BTree::repair(Node* node)
{
    if (node == root && node->keycount == 0)
    {
        if (node->children[0] != nullptr)
        {
            node->children[0]->parent = nullptr;
            root = root->children[0];
        }
        else { delete root; }
        return;
    }
    if (node == root) { return; }
    Node* p = node;
    int position;
    Node* parent = p->parent, *ybr;
    for (int j = 0; j <= parent->keycount; j++)
    {
        if (parent->children[j] == p)
        {
            position = j; break;
        }
    }//записываем, какой по счёту ребёнок заданный узел

    if (position == 0)
    {
        insert_to_node(parent->keys[position], p);
        connect(p, parent->children[position + 1], 1);
        parent->children[position + 1] = p;
        parent->children[position] = nullptr;
        removeFromNode(parent->keys[position], parent);
        if (p->keycount == 2 * t)
        {
            while (p->keycount == 2 * t)
            {
                if (p == root) { split(p); break; }
                else { split(p); p = p->parent; }
            }
        }
        else
        {
            if (parent->childrencount < (t - 1)) repair(parent);
        }
    }
    else
    {
        if (position == parent->keycount)
        {
            ybr = parent->children[position = 1];
            insert_to_node(parent->keys[position - 1], ybr);
            connect(parent->children[position - 1], p, 1);
            parent->children[position] = parent->children[position - 1];
            parent->children[position - 1] = nullptr;
            removeFromNode(parent->keys[position - 1], parent);
            Node* p1 = parent->children[position];
            if (p->keycount == 2 * t)
            {
                while (p1->childrencount == 2 * t)
                {
                    if (p1 == root) { split(p1); break; }
                    else { split(p1); p1 = p1->parent; }
                }
            }
            else
            {
                if (parent->childrencount < (t - 1)) repair(parent);
            }
        }
        else
        {
            insert_to_node(parent->keys[position], p);
            connect(p, parent->children[position + 1], 1);
            parent->children[position + 1] = p;
            parent->children[position] = nullptr;
            removeFromNode(parent->keys[position], parent);
            if (p->keycount == 2 * t)
            {
                while (p->keycount == 2 * t)
                {
                    if (p == root) { split(p); break; }
                    else { split(p); p = p->parent; }
                }
            }
            else
            {
                if (parent->keycount < (t - 1)) repair(parent);
            }
        }
    }
}

void BTree::removeLeaf(int key, Node* node)
{
    if (node->parent == nullptr)
    {
        if (node->keycount == 1)
        {
            removeFromNode(key, node);
            root->children[0] = nullptr;
            delete root;
            root = nullptr;
            return;
        }
        removeFromNode(key, node);
        return;
    }
    if (node->keycount > (t - 1))
    {
        removeFromNode(key, node);
        return;
    }

    Node* p = node, * parent = p->parent;
    int k1, k2, childposition;
    for (int i = 0; i < parent->keycount + 1; i++)
    {
        if (parent->children[i] == p) { childposition = i; break; }
    }

    if (childposition == 0)
    {
        if (parent->children[childposition + 1]->keycount > t - 1)
        {
            k1 = parent->children[childposition + 1]->keys[0];
            k2 = parent->keys[childposition];
            insert_to_node(k2, p);
            removeFromNode(key, p);
            parent->keys[childposition] = k1;
            removeFromNode(k1, parent->children[childposition + 1]);
        }
        else
        {
            removeFromNode(key, p);
            if (p->keycount < (t - 1)) repair(p);
        }
    }
    else
    {
        if (childposition == parent->keycount)
        {
            if (parent->children[childposition - 1]->keycount > (t - 1))
            {
                Node* p1 = parent->children[childposition - 1];
                k1 = p1->keys[p1->keycount - 1];
                k2 = parent->keys[childposition - 1];
                insert_to_node(k2, p);
                removeFromNode(key, p);
                parent->keys[childposition - 1] = k1;
                removeFromNode(k1, p1);
            }
            else
            {
                removeFromNode(key, p);
                if (p->keycount < (t - 1)) repair(p);
            }
        }
        else
        {
            if (parent->children[childposition + 1]->keycount > (t - 1))
            {
                k1 = parent->children[childposition + 1]->keys[0];
                k2 = parent->keys[childposition];
                insert_to_node(k2, p);
                removeFromNode(key, p);
                parent->keys[childposition] = k1;
                removeFromNode(k1, parent->children[childposition + 1]);
            }
            else
            {
                if (parent->children[childposition - 1]->keycount > (t - 1))
                {
                    Node* p1 = parent->children[childposition - 1];
                    k1 = p1->keys[p1->keycount - 1];
                    k2 = parent->keys[childposition - 1];
                    insert_to_node(k2, p);
                    removeFromNode(key, p);
                    parent->keys[childposition - 1] = k1;
                    removeFromNode(k1, p1);
                }
                else
                {
                    removeFromNode(key, p);
                    if (p->keycount < (t - 1)) repair(p);
                }
            }
        }
    }
}

void BTree::remove(int key, Node* node)
{
    Node* p = node;
    if (p->leaf) return;
    int position = 0;
    for (int i = 0; i < node->keycount; i++)
    {
        if (key == node->keys[i]) { position = i; break; }
    }

    //if (p->children[position + 1] == nullptr) return;
    p = p->children[position + 1];
    int newkey = p->keys[0];
    while (!p->leaf) { p = p->children[0]; }
    if (p->keycount > (t - 1))
    {
        newkey = p->keys[0];
        removeFromNode(newkey, p);
        node->keys[position] = newkey;
    }
    else
    {
        p = node->children[position];
        newkey = p->keys[p->keycount - 1];
        while (!p->leaf) p = p->children[p->keycount];
        newkey = p->keys[p->keycount - 1];
        node->keys[position] = newkey;
        if (p->keycount > (t - 1)) removeFromNode(newkey, p);
        else { removeLeaf(newkey, p); }
    }
}

void BTree::remove(int key)
{
    Node* p = root;
    if (!searchKey(key, p)) { std::cout << "\nThis element doesn't exist in the tree\n"; return; }
    else
    {
        removeBody(key, p);
    }
}

void BTree::removeBody(int key, Node* node)
{
    Node* p = node, *pos=nullptr;
    int i;
    if (p != nullptr)
    {
        for (i = 0; i < p->keycount; i++)
        {
            if (p->keys[i] != 0)
            {
                if (key == p->keys[i]) { pos = p; break; }
                if (key < p->keys[i])
                {
                    removeBody(key, p->children[i]);
                }
            }
            else break;
        }
        removeBody(key, p->children[i]);
    }

    if (pos != nullptr) 
    { 
        if (pos->leaf)
        {
            if (pos->keycount > t - 1) removeFromNode(key, pos);
            else
            {
                if (pos == root) { delete(pos); std::cout << "\nThe tree is destroyed\n"; return; }
                else { removeLeaf(key, pos); }
            }
        }
        else remove(key, pos);
    }
}

void BTree::display(Node* node)
{
    int i = 0;
    if (node != nullptr)
    {
        for (i = 0; i < node->keycount; i++)
        {
            display(node->children[i]);
            if (node == root) std::cout << "\n[R]";
            if (node->leaf) std::cout << "\n\t\t[L]";
            else {
                if (node->parent == root) std::cout << "\n    [1]";
                if (node->parent != nullptr) if (node->parent->parent == root) std::cout << "\n        [2]";
                if (node->parent != nullptr) if (node->parent->parent != nullptr) if (node->parent->parent->parent == root) std::cout << "\n            [3]";
                if (node->parent != nullptr) if (node->parent->parent != nullptr) if (node->parent->parent->parent != nullptr) if (node->parent->parent->parent->parent != nullptr) std::cout << "\n                [...]";
            }
            std::cout << node->keys[i];
        }
        display(node->children[i]);
    }
}

void BTree::show()
{
    display(root);
}
