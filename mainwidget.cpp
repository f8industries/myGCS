#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent)
{

    styleIt();

    QPushButton *videoButton = new QPushButton("temporary video switcher", this);
    QPushButton *mapButton = new QPushButton("temporary map switcher", this);


    stackWidget = new QStackedWidget(this);

    //QWidget *videoPage = new QWidget(stackWidget);
    //QWidget *mapPage = new QWidget(stackWidget);
      //QLineEdit *edit2 = new QLineEdit(mapPage);
      //QVBoxLayout *mapPageLayout = new QVBoxLayout(mapPage);
      //mapPageLayout->addWidget(edit2);

    videoView = new VideoView(stackWidget);
    mapView = new MapView(stackWidget);


    stackWidget->addWidget(videoView);
    stackWidget->addWidget(mapView);
    //stackWidget->addWidget(videoPage);
    //stackWidget->addWidget(mapPage);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(mapButton);
    layout->addWidget(videoButton);
    layout->addWidget(stackWidget);

    connect(videoButton, SIGNAL(clicked()), this, SLOT(setVideoView()));
    connect(mapButton, SIGNAL(clicked()), this, SLOT(setMapView()));
}

void mainWidget::setVideoView()
{
    changeCurrent(0);
}

void mainWidget::setMapView()
{
    changeCurrent(1);
}

void mainWidget::changeCurrent(int idx)
{
    if (stackWidget->currentWidget() !=0) {
        stackWidget->currentWidget()->setSizePolicy(QSizePolicy::Ignored,
                                                    QSizePolicy::Ignored);
    }
    stackWidget->setCurrentIndex(idx);
    stackWidget->currentWidget()->setSizePolicy(QSizePolicy::Expanding,
                                                QSizePolicy::Expanding);
    //adjustSize();
}

void mainWidget::styleIt()
{
    this->setStyleSheet(QString::fromUtf8(
                            "QPushButton {\n"
                            "font-size: 24px;\n"
                            "font: bold;\n"
                            "min-width: 45px;\n"
                            "min-height: 48px;\n"
                            "max-height: 48px;\n"
                            "background-color: rgb(10, 10, 10);\n"
                            "border: 2px solid #232;\n"
                            "border-radius: 8px;\n"
                            "padding: 5px;\n"
                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #111, stop: 0.6 #222, stop: 0.7 #333, stop:1 #444);\n"
                            "color: rgb(255, 255, 255);}\n"
                            "QPushButton:pressed {\n"
                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #555, stop: 0.6 #666, stop: 0.7 #777, stop:1 #888);}\n"
                            "GraphWidget {border: 3px solid #000;}\n"
                            "QLabel {\n"
                            "qproperty-alignment: AlignCenter;\n"
                            "font-size: 24px;\n"
                            "font: bold;\n"
                            "min-width: 80px;\n"
                            "min-height: 48px;\n"
                            "max-width: 160px;\n"
                            "max-height: 48px;\n"
                            "background-color: rgb(10, 10, 10);\n"
                            "border: 2px solid #444;\n"
                            "border-radius: 8px;\n"
                            "padding: 5px;\n"
                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #222, stop: 0.6 #333, stop: 0.7 #444, stop:1 #555);\n"
                            "color: rgb(255, 255, 255);}\n"
                            "QSpinBox {\n"
                            "qproperty-alignment: AlignCenter;\n"
                            "font-size: 24px;\n"
                            "font: bold;\n"
                            "min-width: 80px;\n"
                            "min-height: 48px;\n"
                            "max-width: 160px;\n"
                            "max-height: 48px;\n"
                            "background-color: rgb(10, 10, 10);\n"
                            "border: 2px solid #444;\n"
                            "border-radius: 8px;\n"
                            "padding: 5px;\n"
                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #222, stop: 0.6 #333, stop: 0.7 #444, stop:1 #555);\n"
                            "color: rgb(255, 255, 255);}\n"
                            "QDoubleSpinBox {\n"
                            "qproperty-alignment: AlignCenter;\n"
                            "font-size: 24px;\n"
                            "font: bold;\n"
                            "min-width: 80px;\n"
                            "min-height: 48px;\n"
                            "max-width: 160px;\n"
                            "max-height: 48px;\n"
                            "background-color: rgb(10, 10, 10);\n"
                            "border: 2px solid #444;\n"
                            "border-radius: 8px;\n"
                            "padding: 5px;\n"
                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #222, stop: 0.6 #333, stop: 0.7 #444, stop:1 #555);\n"
                            "color: rgb(255, 255, 255);}\n"
                            "QCheckBox {\n"
                            "font-size: 24px;\n"
                            "font: bold;\n"
                            "font-size: 24px;\n"
                            "font: bold;\n"
                            "min-width: 80px;\n"
                            "min-height: 48px;\n"
                            "max-width: 160px;\n"
                            "max-height: 48px;\n"
                            "background-color: rgb(10, 10, 10);\n"
                            "border: 2px solid #444;\n"
                            "border-radius: 8px;\n"
                            "padding: 5px;\n"
                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #111, stop: 0.6 #222, stop: 0.7 #333, stop:1 #444);\n"
                            "color: rgb(255, 255, 255);}\n"
                            "QGroupBox {border: 0px solid #000;}"
                            ));
}
