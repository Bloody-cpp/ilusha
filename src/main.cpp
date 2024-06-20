#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>

class Server : public QTcpServer {
    Q_OBJECT
    quint64 firstTime = 0;
public:
    explicit Server(QObject* parent = nullptr) 
    : QTcpServer(parent) {
        qDebug() << this->listen(QHostAddress::Any, 36453);
    }
    ~Server() {}
    
    void incomingConnection(qintptr desc) override {
        qDebug() << "new connection";
        QTcpSocket* socket = new QTcpSocket(this);
        socket->setSocketDescriptor(desc);
        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    }

public slots:
    void readyRead() {
        if (firstTime == 0)
            firstTime = QDateTime::currentMSecsSinceEpoch();
        QString string;
        auto in = QDataStream(qobject_cast<QTcpSocket*>(sender()));
        in.startTransaction();
        in >> string;
        if (!in.commitTransaction())
            return;
        quint64 lastTime = QDateTime::currentMSecsSinceEpoch();
        qDebug() << lastTime - firstTime;
        qDebug() << string.size();
    }
};

int main(int argc, char** args) {
    int64_t f; //32000 -32000
    QApplication app(argc, args);
    Server server;
    QTcpSocket socket;
    socket.connectToHost(QHostAddress("109.111.65.18"), 36453);
    socket.waitForConnected();
    QString string(5000000, 'f');
    QByteArray array;
    QDataStream out(&array, QIODevice::WriteOnly);
    out << string;
    socket.write(array);
    socket.waitForBytesWritten();
    return app.exec();
}

#include "main.moc"