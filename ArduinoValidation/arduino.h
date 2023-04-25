#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort> // class gathering functions allowing data exchange
//in a serial link
#include <QtSerialPort/QSerialPortInfo> // class providing information about available ports
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Arduino
{
public:     //methods of the Arduino class
    Arduino();
    int connect_arduino(); // allows to connect the PC to Arduino
    int close_arduino(); //allows you to close the connection
    int write_to_arduino( QByteArray ); // send data to arduino
    QByteArray read_from_arduino();  //receive data from Arduino card
    QSerialPort* getserial();   // accessor
    QString getarduino_port_name();
    bool updateScenario(int pos) ;
    int getpos() ;
private:
QSerialPort * serial; //This object gathers information (speed, data bits, etc.)
//and functions (send, receive playback, etc.) on what is a serial path for Arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;  // containing data read from Arduino

};



#endif // ARDUINO_H
