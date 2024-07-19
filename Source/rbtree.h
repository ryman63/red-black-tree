#ifndef RBTREE_H
#define RBTREE_H

typedef enum Color{BLACK, RED};

template<class Key>
struct Node
{
    Node* left;
    Node* right;
    Node* parent;
    Key* keyValue;

    Color color;

    Node(const Node& parent, const Key& keyValue, const Color& color);

};

template <class Key>
class RBTree {
public:

    RBTree();
    ~RBTree();

    void Insert(Node<Key>* node);
    void Insert(Key keyValue);
    Node<Key>* getRoot();

private:
    Node<Key>* root;
    void leftRotate(Node<Key>* x);
    void rightRotate(Node<Key>* x);
    void insertFixup(Node<Key>* node);
};



#endif // RBTREE_H
