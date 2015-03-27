#include "videoview.h"

VideoView::VideoView(QWidget *parent) :
    QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff ); // wyl;acza ewentual przewijanie

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);//musi byc
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(SmartViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);

    horizontalLayout = new QHBoxLayout(this);

    button1 = new QPushButton("button1", this);
    button2 = new QPushButton("button2", this);

    horizontalLayout->addWidget(button1);
    horizontalLayout->addWidget(button2);

    scene->addWidget(button1);
    //scene()->addWidget(button1);
    scene->addWidget(button2);

}

void VideoView::onNewData(int i)
{
    i=0;
}
