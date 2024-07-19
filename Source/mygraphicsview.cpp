#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget* parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);

    this->setAlignment(Qt::AlignCenter);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setScene(scene);

    this->scene->addEllipse(QRectF(-50.0, -50.0, 50.0, 50.0 ));



}

MyGraphicsView::~MyGraphicsView()
{

}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
}


