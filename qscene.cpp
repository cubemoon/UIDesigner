#include "qscene.h"
#include <QGraphicsSceneMouseEvent>

QScene::QScene()
{
}

void QScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     QPointF pt = event->scenePos();
     QTransform trans;
     QGraphicsItem* item = this->itemAt(pt, trans);
     if(item != 0)
     {
         qDebug()<<"scene press "<<item->data(1).toString();
         qDebug()<<"scene press "<<item->x()<<item->y();
     }
     QGraphicsScene::mousePressEvent(event);
}

void QScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem* item = this->mouseGrabberItem();
    if (item != 0)
    {
        qDebug()<<"scene move "<<item->data(1).toString();
        qDebug()<<"scene move "<<item->x()<<item->y();
    }
    //emit currentItemPropertyChanged(item);
    QGraphicsScene::mouseMoveEvent(event);
}

void QScene::test()
{
    QGraphicsRectItem* r1 = this->addRect(-25,-25,50,50,QPen(Qt::red),QBrush(QColor(Qt::red)));
    QGraphicsRectItem* r2 = this->addRect(-100,-100,200,200,QPen(Qt::green), QBrush(QColor(Qt::green)));
    QGraphicsRectItem* r3 = new QGraphicsRectItem(-25,-25,50,50, r2);

    r1->setData(1, "r1");
    //r1->setFlag(QGraphicsItem::ItemIsMovable, true);

    r2->setPos(125,125);
    r2->setData(1, "r2");
    //r2->setFlag(QGraphicsItem::ItemIsSelectable, true);
    r2->setFlag(QGraphicsItem::ItemIsMovable, true);

    r3->setPos(100,100);
    r3->setBrush(QBrush(QColor(Qt::blue)));
    r3->setData(1, "r3");
    r3->setFlag(QGraphicsItem::ItemIsMovable, true);
}
