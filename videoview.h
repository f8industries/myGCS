#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <QGraphicsView>
#include <QPushButton>
#include <QHBoxLayout>


class VideoView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit VideoView(QWidget *parent = 0);
    QGraphicsScene *scene;

signals:

public slots:
    void onNewData(int);

private:
    QPushButton *button1;
    QPushButton *button2;

    QHBoxLayout *horizontalLayout;




};

#endif // VIDEOVIEW_H
