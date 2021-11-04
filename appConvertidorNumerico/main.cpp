#include <QApplication>
#include "convertidornumerico.h"
#include "convertidornumericodialogo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    convertidornumericodialogo dialogo;
    dialogo.setAttribute(Qt::WA_QuitOnClose);
    dialogo.show();
    return app.exec();
}
