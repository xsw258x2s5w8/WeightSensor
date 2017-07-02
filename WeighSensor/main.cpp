#include "index.h"
#include "shipin.h"
#include "shiboqi.h"
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

//    Shipin b;
//    b.show();

    Shiboqi c;
    c.show();
    
    return a.exec();
}
