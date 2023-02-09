#pragma once
#include <QVBoxLayout>
#include"GridSettings.h"
#include "Rect.h"
#include<vector>
#include<qtimer.h>
#include <qcombobox.h>
#include<filesystem>
#include<string>
#include <iostream>
#include<array>
namespace fs = std::filesystem;
class Grille : public QWidget
{
	Q_OBJECT;
	typedef unsigned long long int ulli;
public:
	Grille(ulli horizontal ,ulli vertical );
	int getHorizontal();
	int getVertical();
	std::vector<FillableRect*> getAfter();
	std::vector<bool>& getAfterVB();

	void droite(ulli const& i,ulli const& h, int & cpt);
	void basDroite(ulli const& i, ulli const& h, int & cpt);
	void bas(ulli const& i, ulli  const& h, int & cpt);
	void basGauche(ulli const& i, ulli const& h, int & cpt);
	void gauche(ulli const& i, ulli const& h, int & cpt);
	void hautGauche(ulli const& i, ulli const& h, int & cpt);
	void haut(ulli const& i, ulli const& h, int & cpt);
	void hautDroite(ulli const& i, ulli const& h, int & cpt);
	ulli translate(ulli const& i, ulli const& j);
	void keyPressEvent(QKeyEvent* event);//add a thirs arg to copy the vectorAFTER to the wdg.after, initialise a fileloader et construction a good construct
	std::vector<bool> assign(std::vector<FillableRect*>& a, std::vector<bool>& b);
	void assignV2(Grille* &a);//retourne le AFTER avec les etats cool
	void assignV3(std::vector<FillableRect*> a, std::vector<FillableRect*> b);//1 er donne au deuxieme
	void check();
	//CHECK S IL FAUT COLORIER(SI JDV AFTER A UN TRUE, SI OUI LE COLORIER)
signals:
	void slowDown();
	void speedUp();
	void clear();
	void activated();
public slots:
	void colorChange();
	void naitra();
	void increaseSpeed();
	void decreaseSpeed();
	void cleare();
private:
	QGraphicsScene* sceneGrille = nullptr;
	int j;
	int k;
	int i=0;
	ulli colonne;
	ulli ligne;
	ulli tailleTableau{0};
	std::vector<FillableRect*> JDVtableauxAfter;
	std::vector<bool> JDVtableauxBefore;
	QHBoxLayout* layout1=new QHBoxLayout;
	QVBoxLayout* layout2 = new QVBoxLayout;
	QGraphicsView* fileView = new QGraphicsView;
	QComboBox* box = new QComboBox;
	QSize size=QSize (1500, 40) ;
	size_t taille=1;
	double verification{0};
	QTimer* timer=new QTimer;
	int intervalle=10;
	bool cptspace = true;
	unsigned long long int a = 20;
	std::vector<bool> afterVB;
	int cpt = 0;
};
