#pragma once
#include<string>
#include<qstring.h>
#include<filesystem>
#include <fstream>
#include<qboxlayout.h>
#include<qcombobox.h>
#include<qwidget.h>
#include<qlineedit.h>
#include <qpushbutton.h>
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include "Grille.h"
namespace fs = std::filesystem;

class Grille;

class GridSettings : public QWidget
{
	Q_OBJECT;
public:
	
	GridSettings();
	char min(char o, char b, char $, std::string line, int index);
	int getConfigGridC();
	void setAfter(long long int nb, char BorO);//modifie afterVB de wdg
	void fillAterVB();
	void readFile();
	
public slots:
	void fileLoader(QString FileNameToLoad);
	void goodConstruction();
private:
	fs::path pathe = "\\prog\\c++\\solutionsGUI\\JeuDeLaVie\\pattern\\";
	std::vector<size_t> hashValue;
	QVBoxLayout* leGrand = new QVBoxLayout;
	QHBoxLayout* leHaut = new QHBoxLayout;
	QHBoxLayout* leBas = new QHBoxLayout;
	QHBoxLayout* lePlusBas = new QHBoxLayout;
	QComboBox* box = new QComboBox;
	QSize size = QSize(750, 40);
	QLineEdit* TextBoxL = new QLineEdit;
	QLineEdit* TextBoxC = new QLineEdit;
	QGraphicsScene* scene = new QGraphicsScene;
	QGraphicsView* view = new QGraphicsView;
	size_t nbLine = 0;
	size_t nbColumn = 0;
	QPushButton* finished = new QPushButton;
	long int numL = -1;
	long int numC = -1;
	bool verificationFileLoader = false;
	long long int configGridL = 0;
	long long int configGridC = 0;
	std::string line;
	bool runOnce = false;
	size_t currentIndex = 0;
	Grille* wdg = nullptr;
	std::string data;
	std::ifstream file;
	int debug=0;
	
};
