#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QGraphicsView>
#include <QtNetwork>
#include "lightmaps.h"


class MapView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent = 0);
    QGraphicsScene *scene;

signals:

public slots:
    void onNewData(int);
    void sessionOpened();

private:
    LightMaps *map;
    QNetworkSession *networkSession;

    void networkConf();
};

#endif // MAPVIEW_H
