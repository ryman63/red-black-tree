#include "rbtree.h"
#define NIL &sentinel<Key> //макрос NIL

template <class Key>
Node<Key> sentinel{ NIL, NIL, NIL, 0, BLACK }; //защитник-ограничитель дерева


template <class Key>
RBTree<Key>::RBTree()
{
    root = NIL;
}

template <class Key>
RBTree<Key>::~RBTree()
{
    delete sentinel<Key>;
    delete root;
}

//функция вставки в дерево по ключу
template<class Key>
void RBTree<Key>::Insert(Key keyValue)
{
    Node<Key>* ptr = { NIL, NIL, NIL, keyValue, RED }; //создание узла с текущим ключом для осуществления вставки
    Insert(ptr);
}

//функция вставки узла в дерево
template <class Key>
void RBTree<Key>::Insert(Node<Key>* node)
{
    Node<Key>* ptr = root;
    Node<Key>* ptr_prev = nullptr;
    while (ptr != NIL)
    {
        ptr_prev = ptr;
        if (node->keyValue < ptr->keyValue)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (ptr_prev)
    {
        if (node->keyValue < ptr->keyValue)
            ptr_prev->left = node;
        else
            ptr_prev->right = node;
    }
    else
        root = node;
    node->color = RED;
    insertFixup(node);
}

template<class Key>
Node<Key>::Node(const Node& parent, const Key& keyValue, const Color& color)
{
    this->left = NIL;
    this->right = NIL;
    this->parent = parent;
    this->keyValue = keyValue;
    this->color = color;
}

//функция левого поворота дерева
template<class Key>
void RBTree<Key>::leftRotate(Node<Key>* x)
{
    Node<Key>* y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;
    if (y != NIL) y->parent = x->parent;
    if (x->parent == NIL)
        root = y;
    else
    {
        if (x == x->parent->left)
            x->parent->left = y;
        else x->parent->right = y;
    }
    y->left = x;
    if (x != NIL) x->parent = y;
}

//функция правого поворота дерева
template <class Key>
void RBTree<Key>::rightRotate(Node<Key>* x)
{
    Node<Key>* y = x->left;
    x->left = y->right;
    if (y->right != NIL)
        y->right->parent = x;
    if (y != NIL) y->parent = x->parent;
    if (x->parent == NIL)
        root = y;
    else
    {
        if (x->parent->right == x)
            x->parent->right = y;
        else x->parent->left = y;
    }
    y->right = x;
    if (x != NIL) x->parent = y;
}

//функция балансировки дерева после вставки узла
template <class Key>
void RBTree<Key>::insertFixup(Node<Key>* node)
{
    //проверяем свойства дерева
    while (node != root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left)
        {
            Node<Key>* y = node->parent->parent->right;		//устанавливаем дядю узла node
            if (y->color == RED) //если дядя - красный
            {
                //смена цветов
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                //
                node = node->parent->parent;		//поднимаемся на 2 уровня вверх
            }
            else  //если дядя - темнокожий
            {
                if (node == node->parent->right)
                {
                    //делаем node левым ребёнком
                    node = node->parent;
                    leftRotate(node);
                }
                //перекраска и поворот
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(node->parent->parent);
            }
        }
        else
        {
            Node<Key>* y = node->parent->parent->left;		//устанавливаем дядю узла node
            if (y->color == RED) //если дядя - красный
            {
                //смена цветов
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                //
                node = node->parent->parent;		//поднимаемся на 2 уровня вверх
            }
            else  //если дядя - темнокожий
            {
                if (node == node->parent->left)
                {
                    //делаем node правым ребёнком
                    node = node->parent;
                    rightRotate(node);
                }
                //перекраска и поворот
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

template <class Key>
Node<Key>* RBTree<Key>::getRoot()
{
    return root;
}
