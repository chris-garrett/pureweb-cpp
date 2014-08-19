#include <QCoreApplication>
#include "standardexamples.h"
#include "typelessexamples.h"
#include "statemanagerexamples.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	StandardExamples se;

	TypelessExamples te;

	StateManagerExamples sm;
    sm.UpdateStringValue();

    return a.exec();
}
