#include "mainwindow.h"
#include "ui_mainwindow.h"
int valeur=-1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // launch the connection to arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }

  QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); //allows to

     //launch the update_label slot following the reception of the readyRead signal (reception of data).


}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update_label()
{

    data= A.read_from_arduino() ;


       bool test= A.updateScenario(data.toInt()) ;
       if(test) qDebug() << "success" ;
       else   qDebug() << " NO success" ;
       ui->label->setText("Ambulance is on"+ data) ;


       int read = A.getpos() ;
       switch(read)
       {
       case 1:      A.write_to_arduino("1");

           break ;
       case 2 :     A.write_to_arduino("2");
           break;
       case 3 :     A.write_to_arduino("3");

           break;
       case  4:     A.write_to_arduino("4");  //send 0 to arduino

           break;

       }



}



