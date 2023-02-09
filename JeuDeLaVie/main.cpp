#include "GridSettings.h"
#include<qapplication.h>


int main(int argc, char* argv[])
{
	QApplication JeuDeLaVie(argc, argv);
	GridSettings gridsettings;
	gridsettings.show();
	return JeuDeLaVie.exec();
}