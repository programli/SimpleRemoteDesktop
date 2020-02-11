#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QObject>
#include <QSize>
#include <QImage>
#include <QTimer>

class DataParser : public QObject
{
    Q_OBJECT
public:
    explicit DataParser(QObject *parent = nullptr);

private:

    QByteArray m_dataTmp;
    QTimer *m_timerClearTmp;

    QList<QByteArray> m_socketsList;

signals:
    void messgage(const QByteArray &data);
    void startGraber();
    void stopGraber();
    void receivedTileNum(quint16 num);
    void changeDisplayNum();
    void setKeyPressed(quint16 keyCode, bool state);
    void setMousePressed(quint16 keyCode, bool state);
    void setWheelChanged(bool deltaPos);
    void setMouseMove(quint16 posX, quint16 posY);
    void setMouseDelta(qint16 deltaX, qint16 deltaY);

public slots:
    void setNewSocket(const QByteArray &uuid);
    void removeSocket(const QByteArray &uuid);

    void setData(const QByteArray &uuid, const QByteArray &data);

    void sendImageParameters(const QSize &imageSize, int rectWidth);
    void sendImageTile(quint16 posX, quint16 posY, const QImage &image, quint16 tileNum);

private slots:
    void newData(const QByteArray &command, const QByteArray &data);
    void debugHexData(const QByteArray &data);
    void timerClearTmpTick();


    QByteArray arrayFromUint16(quint16 number);
    quint16 uint16FromArray(const QByteArray &buf);
};

#endif // DATAPARSER_H
