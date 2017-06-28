#include "index.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("../WeighSensor/WeighSensor.qm");
    a.installTranslator(&translator);

    Index w;
    w.show();
    
    return a.exec();
}
