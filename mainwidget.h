#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "videoview.h"
#include "mapview.h"

class mainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainWidget(QWidget *parent = 0);

signals:

public slots:

public slots:
    void setMapView();
    void setVideoView();

private:
    QStackedWidget *stackWidget;
    void           changeCurrent(int idx);

    VideoView      *videoView;
    MapView        *mapView;

    void           styleIt();



};

#endif // MAINWIDGET_H
