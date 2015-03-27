#ifndef LIGHTMAPS_H
#define LIGHTMAPS_H

#include <QBasicTimer>
#include <QWidget>

class SlippyMap;

class LightMaps: public QWidget
{
    Q_OBJECT

public:
    LightMaps(QWidget *parent = 0);
    void setCenter(qreal lat, qreal lng);

public slots:
    void toggleNightMode();

protected:
    void activateZoom();
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void updateMap(const QRect &r);

private:
    SlippyMap *m_normalMap;
    SlippyMap *m_largeMap;
    bool pressed;
    bool snapped;
    QPoint pressPos;
    QPoint dragPos;
    QBasicTimer tapTimer;
    bool zoomed;
    QPixmap zoomPixmap;
    QPixmap maskPixmap;
    bool invert;
};

#endif
