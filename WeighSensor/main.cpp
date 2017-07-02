#include "index.h"
#include "shipin.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("../WeighSensor/WeighSensor.qm");
    a.installTranslator(&translator);

    Index w;
    Shipin b;
    b.show();
    w.show();
    
    return a.exec();
}
