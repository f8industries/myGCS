#include "mapview.h"

MapView::MapView(QWidget *parent) :
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


    map = new LightMaps(this);
    scene->addWidget(map);
    //setCentralWidget(map);
    map->setFocus();
    map->setCenter(52.215729, 21.014671);

    networkConf();

}

void MapView::onNewData(int i)
{
    i=0;
}

void MapView::networkConf()
{
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id =
            settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system
        // default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        networkSession->open();
    } else {
        networkSession = 0;
    }
}

void MapView::sessionOpened()
{
    // Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice) {
        id = networkSession->sessionProperty(
                QLatin1String("UserChoiceConfiguration")).toString();
    } else {
        id = config.identifier();
    }

    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();
}


