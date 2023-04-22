#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort> // class gathering functions allowing data exchange
// in a serial link
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSerialPort/QSerialPortInfo> // class providing information about available ports

class Arduino {
public: // methods of the Arduino class
  Arduino();
  int connect_arduino();            // allows to connect the PC to Arduino
  int close_arduino();              // allows you to close the connection
  int write_to_arduino(QByteArray); // send data to arduino
  QByteArray read_from_arduino();   // receive data from Arduino card
  QSerialPort *getserial();         // accessor
  QString getarduino_port_name();

private:
  QSerialPort
      *serial; // This object gathers information (speed, data bits, etc.)
  // and functions (send, receive playback, etc.) on what is a serial path for
  // Arduino.
  static const quint16 arduino_uno_vendor_id = 9025;
  static const quint16 arduino_uno_producy_id = 67;
  QString arduino_port_name;
  bool arduino_is_available;
  QByteArray data; // containing data read from Arduino

  struct Scenario {
    QString id;
    unsigned int currentPosition;
    unsigned int heartRate;
  };

  static unsigned int createScenario(unsigned int light) {
    QSqlQuery query;
    query.prepare("BEGIN "
                  "INSERT INTO ARDUINO_SCENARIO "
                  "(CURRENT_POSITION) "
                  "VALUES(:CURRENT_POSITION) "
                  "RETURNING ID INTO :ID;"
                  "END;");

    query.bindValue(":CURRENT_POSITION", light);
    query.bindValue(":ID", 0, QSql::Out);

    query.exec();

    return query.boundValue(":S_ID").toInt();
  }

  static Scenario findScenario(const QString &id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM AMBULANCE_SCENARIO WHERE ID= ?");

    query.addBindValue(id);

    query.exec();

    if (!query.first()) {
      return Scenario{};
    }

    return Scenario{.id = id,
                    .currentPosition = query.value("CURRENT_POSITION").toUInt(),
                    .heartRate = query.value("HEART").toUInt()};
  }
};

#endif // ARDUINO_H
