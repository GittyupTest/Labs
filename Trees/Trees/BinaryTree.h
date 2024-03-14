#pragma once

class BinaryTree
{
public:
    class Node;

public:
    BinaryTree() = default;
    BinaryTree(const BinaryTree &other);
    ~BinaryTree();

    void clear();
    void clear(Node* root);
    BinaryTree clone() const;
    BinaryTree clone(Node *root) const;

    bool isIdeal() const;
    bool isBalanced() const;

    Node *addNode(int key);

    void printHorizontal(int levelSpacing = 4) const;
    void printHorizontal(Node *root, int marginLeft, int levelSpacing) const;

private:
    Node *_addNode(Node *root, int key);
    Node *_clone() const;
    Node *_clone(Node *root) const;

private:
    Node *m_root = nullptr;
};

class BinaryTree::Node
{
public:
    Node(int key = 0, Node* left = nullptr, Node* right = nullptr);
    ~Node() = default;

    int getKey() const;
    void setKey(int key);

    Node* getLeft();
    Node* getRight();
    void setLeft(Node* left);
    void setRight(Node* right);

private:
    int m_key = 0;
    Node* m_left = nullptr;
    Node* m_right = nullptr;

};
