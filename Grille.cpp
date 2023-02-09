#include<qgraphicsscene.h>
#include <qpainter.h>
#include <QKeyEvent>
#include<filesystem>
#include<string>
#include "Grille.h"
#include "Rect.h"
#include"qgraphicsview.h"
#include <fstream>
Grille::Grille(ulli  horizontal,ulli vertical ) :ligne(vertical), colonne(horizontal)
{
	sceneGrille = new QGraphicsScene();
	QVBoxLayout* layout = new QVBoxLayout();
	QGraphicsView* view = new QGraphicsView();
	FillableRect* rect = new FillableRect(10, 10, 10, 10);
	tailleTableau = horizontal * vertical;
	for (j = 0; j < vertical * 10; j += 10)
	{
		for (k = 0; k < horizontal * 10; k += 10)
		{
			FillableRect* rect = new FillableRect(k, j, 10, 10);
			QObject::connect(rect, SIGNAL(click()), this, SLOT(colorChange()));
			sceneGrille->addItem(rect);
			JDVtableauxAfter.push_back(rect);
		}
	}
	layout2->addLayout(layout);
	layout->addWidget(view);
	view->setScene(sceneGrille);
	setLayout(layout2);
	setLayout(layout1);
	setLayout(layout);
	timer->setInterval(intervalle);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(naitra()));
	QObject::connect(this, SIGNAL(speedUp()), this, SLOT(increaseSpeed()));
	QObject::connect(this, SIGNAL(slowDown()), this, SLOT(decreaseSpeed()));
	QObject::connect(this, SIGNAL(clear()), this, SLOT(cleare()));
	QObject::connect(box, SIGNAL(currentTextChanged(QString)), this, SLOT(fileLoader(QString)));
}

void Grille::colorChange()
{
	if (((FillableRect*)sender())->getEtat() == false)
	{
		((FillableRect*)(sender()))->setBrush(QBrush(Qt::GlobalColor::black));
		((FillableRect*)(sender()))->switchEtat();
	}
	else
	{
		((FillableRect*)(sender()))->setBrush(QBrush(Qt::GlobalColor::white));
		((FillableRect*)(sender()))->switchEtat();
	}
}
int Grille::getHorizontal()
{
	return colonne;
}
int Grille::getVertical()
{
	return ligne;
}
std::vector<FillableRect*> Grille::getAfter()
{
	return JDVtableauxAfter;
}
std::vector<bool>& Grille::getAfterVB()
{
	return afterVB;
}
void Grille::increaseSpeed()
{
	timer->setInterval(intervalle -= 30);
}
void Grille::decreaseSpeed()
{
	timer->setInterval(intervalle += 30);
}
void Grille::droite(ulli const & i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i, h + 1)])) {++cpt;}
}
void Grille::basDroite(ulli const& i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i + 1, h + 1)])) { ++cpt; }
}
void Grille::bas(ulli const& i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i + 1, h)]))  {++cpt;}
}
void Grille::basGauche(ulli const& i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i + 1, h - 1)])) { ++cpt; }
}
void Grille::gauche(ulli const& i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i, h - 1)])) { ++cpt; }
}
void Grille::hautGauche(ulli const& i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i - 1, h - 1)])) { ++cpt; }
}
void Grille::haut(ulli const& i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i - 1, h)])) { ++cpt; }
}
void Grille::hautDroite(ulli const& i, ulli const& h, int& cpt)
{
	if ((JDVtableauxBefore[translate(i - 1, h + 1)])) { ++cpt; }
}
Grille::ulli Grille::translate(ulli const& i,ulli const& h)
{
	return i * colonne + h;
}
void Grille::keyPressEvent(QKeyEvent* event)
{/*RAPPEL voir si i est etat==true, voir pour les conditon si il fat pas verifier h //faire un systeme comme la souris pour marche arret// xompte le nombre de space fait*/
	if (event->key()== Qt::Key_A)
	{
		emit slowDown();
	}
	else if (event->key() == Qt::Key_Z)
	{
		emit speedUp();
	}
	else if (event->key()==Qt::Key_C)
	{
		emit clear();
	}
	else if (event->key() == Qt::Key::Key_Space)
	{
		if (cptspace)
		{
			timer->setInterval(intervalle);
			timer->start();
			cptspace = !cptspace;
		}
		else
		{
			timer->stop();
			cptspace = !cptspace;
		}
	}
	else { }
}

std::vector<bool> Grille::assign(std::vector<FillableRect*>& a, std::vector<bool>& b)//b=recepteur
{
	if (std::size(a)!=std::size(b))
	{
		for (ulli z = 0; z < std::size(a); z++)
	    {
		   b.push_back(a[z]->getEtat());
	    }
	}
	else
	{
		for (ulli z = 0; z < std::size(a); z++)
		{
			b[z] = a[z]->getEtat();
		}
	}
	return   b;
}
void Grille::assignV2(Grille* &a)//afterVB est mal initialisé THIS c est bien wdg?????? Et aussi PK after VB plus grand que taille maximal d un tab normal
{
	for (size_t i = 0; i < afterVB.size(); i++)
	{
		a->JDVtableauxAfter[i]->setEtat(this->afterVB[i]);
	}
}
void Grille::assignV3(std::vector<FillableRect*> a, std::vector<FillableRect*> b)
{/*b.clear()*/
	for (size_t i = 0; i < a.size(); i++)
	{
		b[i] = a[i];
	}
}
void Grille::check()
{
	for (size_t i = 0; i < JDVtableauxAfter.size(); i++)
	{
		
			JDVtableauxAfter[i]->getBlack();
		
	}
}
void Grille::cleare()
{
	for (unsigned long long int i = 0; i < std::size(JDVtableauxAfter); i++)
	{
		JDVtableauxAfter[i]->setEtat(false);
		JDVtableauxAfter[i]->getBlack();
	}
}
void Grille::naitra()
{
	assign(JDVtableauxAfter, JDVtableauxBefore);
	static int debug = 0; ++debug;
	for (ulli i = 0; i < ligne ; i++)
	{
		for (ulli h = 0; h < colonne ; h++)
		{
			if (i==0 && h == 0 && JDVtableauxBefore[(translate(i, h))] == false)//coin haut gauche
			{
				droite(i, h, cpt); basDroite(i, h, cpt); bas(i, h, cpt);
				if (cpt==3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			else if (i == ligne - 1 && h == 0 && JDVtableauxBefore[(translate(i, h))] == false)//coin bas gauche
			{
				haut(i, h, cpt); hautDroite(i, h, cpt); droite(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			else if (i == ligne - 1 && h == colonne - 1 && JDVtableauxBefore[(translate(i, h))] == false)//bas droite
			{
				gauche(i, h, cpt); hautGauche(i, h, cpt); haut(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			else if (i == 0 && h == colonne - 1 && JDVtableauxBefore[translate(i, h)] == false)//haut droite
			{
				bas(i, h, cpt); basGauche(i, h, cpt); gauche(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			//Fin check up coins
			////debut check up ligne et colonne
			else if (JDVtableauxBefore[translate(i,h)] == false && i == 0 && h>0 && h<colonne - 1)//ligne haut
			{
				basGauche(i, h, cpt); bas(i, h, cpt); basDroite(i, h, cpt); gauche(i, h, cpt); droite(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}		
				cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)] == false && h == 0 && i > 0 && i < ligne - 1)//colonne gauche
			{
				hautDroite(i, h, cpt); droite(i, h, cpt); basDroite(i, h, cpt); haut(i, h, cpt); bas(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)] == false && i == ligne-1 && h > 0 && h < colonne - 1)//ligne du bas
			{
				hautGauche(i, h, cpt); haut(i, h, cpt); hautDroite(i, h, cpt); droite(i, h, cpt); gauche(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)] == false && h == colonne - 1 && i > 0 && i < ligne - 1)//colonne droite
			{
				hautGauche(i, h, cpt); gauche(i, h, cpt); basGauche(i, h, cpt); haut(i, h, cpt); bas(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)]== false)//tout les autres cas
			{
				gauche(i, h, cpt); hautGauche(i, h, cpt); haut(i, h, cpt); hautDroite(i, h, cpt); droite(i, h, cpt); basDroite(i, h, cpt); bas(i, h, cpt); basGauche(i, h, cpt);
				if (cpt == 3)
				{
					JDVtableauxAfter[translate(i, h)]->switchEtat();
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
				cpt = 0;
			}
			//LA MOOOOOOOOOOOOORT
			else if (i == 0 && h == 0 && JDVtableauxBefore[(translate(i, h))] == true)//coin haut gauche
			{
				droite(i, h, cpt); basDroite(i, h, cpt); bas(i, h, cpt);
				if (cpt<2)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			}
			else if (i == ligne - 1 && h == 0 && JDVtableauxBefore[(translate(i, h))] == true)//bas gauche
			{
			 haut(i, h, cpt); hautDroite(i, h, cpt); droite(i, h, cpt);
				if (cpt < 2)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			  cpt = 0;
			}
			else if (i == ligne - 1 && h == colonne - 1 && JDVtableauxBefore[(translate(i, h))] == true)//bas droite
			{
			 gauche(i, h, cpt); hautGauche(i, h, cpt); haut(i, h, cpt);
				if (cpt < 2)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			 cpt = 0;
			}
			else if (i == 0 && h == colonne - 1 && JDVtableauxBefore[translate(i, h)] == true)//haut droite
			{
			 bas(i, h, cpt); basGauche(i, h, cpt); gauche(i, h, cpt);
				if (cpt < 2)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			 cpt = 0;
			}
			//ligne
			else if (JDVtableauxBefore[translate(i, h)] == true && i == 0 && h > 0 && h < colonne - 1)//ligne haut
			{
			basGauche(i, h, cpt); bas(i, h, cpt); basDroite(i, h, cpt); droite(i, h, cpt); gauche(i, h, cpt);
				if (cpt < 2||cpt>3)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			 cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)] == true && h == 0 && i > 0 && i < ligne - 1)//colonne gauche
			{
			hautDroite(i, h, cpt); droite(i, h, cpt); basDroite(i, h, cpt); bas(i, h, cpt); haut(i, h, cpt);
				if (cpt < 2 || cpt>3)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			 cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)] == true && h == colonne - 1 && i > 0 && i < ligne - 1)//colonne droite
			{
			hautGauche(i, h, cpt); gauche(i, h, cpt); basGauche(i, h, cpt); haut(i, h, cpt); bas(i, h, cpt);
				if (cpt < 2 || cpt>3)
				{
				 JDVtableauxAfter[translate(i, h)]->setEtat(false);
				 JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)] == true && i == ligne - 1 && h > 0 && h < colonne - 1)//ligne du bas
			{
			hautGauche(i, h, cpt); haut(i, h, cpt); hautDroite(i, h, cpt); droite(i, h, cpt); gauche(i, h, cpt);
				if (cpt < 2 || cpt>3)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			 cpt = 0;
			}
			else if (JDVtableauxBefore[translate(i, h)] == true)//tout les autres cas
			{
			 gauche(i, h, cpt); hautGauche(i, h, cpt); haut(i, h, cpt); hautDroite(i, h, cpt); droite(i, h, cpt); basDroite(i, h, cpt); bas(i, h, cpt); basGauche(i, h, cpt);
				if (cpt <2 || cpt>3)
				{
					JDVtableauxAfter[translate(i, h)]->setEtat(false);
					JDVtableauxAfter[translate(i, h)]->getBlack();
				}
			cpt = 0;
			}
		}
	}
}
