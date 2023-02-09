#include"Rect.h"
#include <QGraphicsItem>
#include<qgraphicsview.h>
FillableRect::FillableRect(int abscisses, int ordo, int largeur, int taille,QGraphicsItem* parent ):QGraphicsRectItem::QGraphicsRectItem(abscisses, ordo, largeur, taille,parent)
{
}
//FullableRect::FullableRect() 
//{
//
//
//}
void FillableRect::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	emit click();
	QGraphicsRectItem::mousePressEvent(event);	
}
bool FillableRect::getEtat() const
{
	return etat;
}
bool FillableRect::switchEtat()
{
	etat = !etat;
	return etat;
}
bool FillableRect::setEtat(bool newValue)
{
	if (newValue)
	{
		etat = true;
	}
	else
	{
		etat = false;
	}
	return etat;
}
void FillableRect::getBlack()
{
	if (etat==true)
	{
		this->setBrush(QBrush(Qt::GlobalColor::black));
	}
	else
	{
		this->setBrush(QBrush(Qt::GlobalColor::white));
	}
}
