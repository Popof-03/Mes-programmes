#pragma once
#include <QGraphicsView>
#include<QGraphicsRectItem>
class FillableRect : public QObject, public QGraphicsRectItem
{
	Q_OBJECT;
public:
	FillableRect(int abscisses, int ordo, int largeur, int taille, QGraphicsItem* parent = nullptr);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	bool getEtat() const;
	bool switchEtat();
	bool setEtat(bool newValue);
	void getBlack();
 signals:
	 void click() const;
private:
	bool etat = false;
};
