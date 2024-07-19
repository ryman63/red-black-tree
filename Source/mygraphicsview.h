#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <iostream>
#include "rbtree.h"

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT;
public:
    explicit MyGraphicsView(QWidget* parent = nullptr);

    ~MyGraphicsView();
private:
    QGraphicsScene* scene;

    RBTree<int>* tree;

    void resizeEvent(QResizeEvent *event);
};

#endif // MYGRAPHICSVIEW_H
