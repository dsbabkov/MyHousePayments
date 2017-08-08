#include <QApplication>
#include <dialogs/MainWindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("myhousepayments");
    a.setOrganizationName("Dmitriy Babkov");

    MainWindow w;
    w.show();

    return a.exec();
}
