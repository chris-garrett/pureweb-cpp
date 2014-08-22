#include <QCoreApplication>
#include "standardexamples.h"
#include "typelessexamples.h"
#include "statemanagerexamples.h"
#include "stringexamples.h"
#include "miscexamples.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	StandardExamples().Run();
	StateManagerExamples().Run();
	TypelessExamples().Run();
	StringExamples().Run();
	MiscExamples().Run();

    return a.exec();
}
