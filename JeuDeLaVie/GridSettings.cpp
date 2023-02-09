#include"GridSettings.h"//faut detetcter de ou a ou il y a le patern(grace a translate versiopn modifié sachant qu on connait nb fillablrect ds lign et colo) et insert des false 
#include"Grille.h"
#include<ios>
#include<cctype>
#include <math.h>  

void GridSettings::fileLoader(QString fileNameToLoad)
{
	if (fs::is_directory(pathe))
	{
		for (const auto& entry : fs::directory_iterator(pathe))
		{
			/*hashValue.push_back(fs::hash_value(entry.path()));*/
			if (fileNameToLoad == QString::fromStdString(((entry.path()).stem()).fs::path::generic_string()) && entry.path().filename().extension() == ".rle")
			{
				verificationFileLoader = true;
				std::string forOpen = entry.path().filename().string();
				std::ios_base::openmode mode; mode = std::ios_base::in;
				file.open(forOpen.std::string::c_str(), mode);
				std::string line;
				
			}
		}
	}
}
GridSettings::GridSettings()
{
	view->setScene(scene);
	leGrand->addLayout(leHaut);
	leGrand->addLayout(leBas);
	leGrand->addLayout(lePlusBas);
	finished->setText("End of config");
	box->setFixedSize(size);
	QString b = "nothing";
	box->addItem(b);
	for (const auto& entry : fs::directory_iterator(pathe))
	{
		if ((entry.path()).extension() == ".rle")
		{
			QString a = QString::fromStdString(((entry.path()).stem()).fs::path::generic_string());
			box->addItem(a);
		}
	}
	QWidget::setLayout(leGrand);
	setLayout(lePlusBas);
	setLayout(leHaut);
	setLayout(leBas);
	leHaut->addWidget(box);
	leBas->addWidget(TextBoxL);
	leBas->addWidget(TextBoxC);
	lePlusBas->addWidget(finished);
	QObject::connect(box, SIGNAL(currentTextChanged(QString)), this, SLOT(fileLoader(QString)));
	QObject::connect(TextBoxL, SIGNAL(editingFinished()), this, SLOT(initL()));
	QObject::connect(TextBoxC, SIGNAL(editingFinished()), this, SLOT(initC()));
	QObject::connect(finished, SIGNAL(released()), this, SLOT(goodConstruction()));
	scene->addWidget(box);
	scene->addWidget(TextBoxC);
	scene->addWidget(TextBoxL);
	wdg = new Grille(2, 2);
}
char GridSettings::min(char o, char b, char $,std::string line, int index)
{
	if (line.find($, index) < line.find(b, index) && line.find($, index) < line.find(o, index)&& line.find($, index) < line.find('!', index))//$prems?
	{
		return '$';
	}
	else if (line.find(b, index) < line.find($, index) && line.find(b, index) < line.find(o, index) && line.find(b, index) < line.find('!', index))//b prems?
	{
		return'b';
	}
	else if (line.find(o, index) < line.find($, index) && line.find(o, index) < line.find(b, index) && line.find(o, index) < line.find('!', index))//o prems?
	{
		return'o';
	}
	else if (line.find('!', index) < line.find($, index) && line.find('!', index) < line.find(b, index)&& line.find('!', index) < line.find(o, index))//fin?
	{
		return '!';
	}
	else
	{
		return 'v';
	}
}
int GridSettings::getConfigGridC()
{
	return configGridC;
}
void GridSettings::setAfter(long long int nb, char BorO)
{
	
	
		if (BorO == 'o')
		{
			for (size_t i = 0; i < nb; i++)
			{
				this->wdg->getAfterVB().push_back(true);
				debug += 1;
			}
			checkeol += nb;
			check += nb;
		}
		else if (BorO == 'b')
		{
			for (size_t i = 0; i < nb; i++)
			{
				this->wdg->getAfterVB().push_back(false);
				debug += 1;
			}
			checkeol += nb;
			check += nb;
		}
		else if (BorO == '$')
		{
			
			if (numC==-1 && numL==-1)
			{
				int length = configGridC - checkeol;
				for (size_t i = 0; i < length; i++)
				{
					this->wdg->getAfterVB().push_back(false);
				}
				check += length;
				
				checkeol = 0;

			}
			else
			{
				
				while (checkeol!= configGridC+floor((numC - configGridC) / 2))//comble jusqu a la fin de la lim pattern, regarde si checkeol possede deja le floor(il a deja) COLOONNE
				{
					this->wdg->getAfterVB().push_back(false);
					checkeol += 1;
					check += 1;
				}
				while (checkeol != numC)//comble jusqu a la fin de la grille COLOONNE, // il faut check s il est inferieur à!: check < (numL*numC)-((numL-configGridl)/2)
				{
					this->wdg->getAfterVB().push_back(false);
					checkeol += 1;
					check += 1;
				}
				checkeol = 0;
				while (checkeol!= floor((numC - configGridC) / 2)-1)
				{
					this->wdg->getAfterVB().push_back(false);
					checkeol += 1;
					check += 1;
				}
			

				



			}
			
		}
				

				
				
		
		else if (BorO=='!')
		{
				while (check != numC*numL)
				{
					this->wdg->getAfterVB().push_back(false);
					check += 1;
				}
	
		}
	
}
void GridSettings::fillAterVB()
{
	if (this->wdg->getAfterVB().size()<(configGridC*configGridL))
	{
		for (int i = 0; this->wdg->getAfterVB().size() < (configGridC * configGridL); i++)
		{
			this->wdg->getAfterVB().push_back(false);

		}
	}
}

void GridSettings::readFile()
{
	if (file.is_open())
	{
		while (configGridC == 0 && configGridL == 0)
		{
			getline(file, data);
			if (data[0] == '#')
			{
				continue;
			}
			else if (data[0] == 'x')
			{
				std::string accurateLine = data.substr(data.find('=') + 1, data.find(',') - 3);
				configGridC = std::stoi(accurateLine);
				accurateLine = data.substr(data.find('=', data.find(',')) + 1, data.find(',') - 3);
				configGridL = std::stoi(accurateLine);
			}
		}


		while (getline(file, data))
		{
			line += data;
		}
		std::string accurateLine = line;
		if (numC != -1 && numL != -1)//decalage du debut 
		{
			while (check!=floor((numL-configGridL)/2)*numC)
			{
				this->wdg->getAfterVB().push_back(false);
				check += 1;
			}
			int length = floor((numC - configGridC) / 2);//COLONNE
			for (size_t i = 0; i < length - 1; i++)//comble le 1 er; ecart entre tt debut et debut pattern AU MAUVAISE ENDROIT LUI FAUT LE METTRE AU TT DEBUT
			{
				this->wdg->getAfterVB().push_back(false);
			}
			check += length - 1;
			checkeol += length - 1;


		}
		while (min('o', 'b', '$', line, currentIndex) != '!')
		{
			numC;
			if (line[0] == 'o' && currentIndex == 0)
			{
				setAfter(1, 'o');
				currentIndex += 1;
			}
			else if (line[0] == 'b' && currentIndex == 0)
			{
				setAfter(1, 'b');
				currentIndex += 1;
			}
			else if (min('o', 'b', '$', line, currentIndex) == 'o' && (currentIndex - 1 >= 0 && std::isdigit(line[line.find('o', currentIndex) - 1]) == 0))
			{
				setAfter(1, 'o');
				currentIndex += 1;
			}
			else if (min('o', 'b', '$', line, currentIndex) == 'b' && (currentIndex - 1 >= 0 && std::isdigit(line[line.find('b', currentIndex) - 1]) == 0))
			{
				setAfter(1, 'b');
				currentIndex += 1;
			}
			else if (min('o', 'b', '$', line, currentIndex) == 'o')
			{
				accurateLine = line.substr(currentIndex, line.find('o', currentIndex) - currentIndex);
				int o = std::stoi(accurateLine);
				setAfter(o, 'o');
				currentIndex += (1 + line.find('o', currentIndex) - currentIndex);
			}
			else if (min('o', 'b', '$', line, currentIndex) == 'b')//si b est prem
			{
				accurateLine = line.substr(currentIndex, line.find('b', currentIndex) - currentIndex);
				int b = std::stoi(accurateLine);
				setAfter(b, 'b');
				currentIndex += (1 + line.find('b', currentIndex) - currentIndex);
			}
			else if (min('o', 'b', '$', line, currentIndex) == '$')
			{
				if (std::isdigit(line[currentIndex]) == 0)//si lettre pas translate en cghiffre
				{
				
					
					setAfter(1, '$');
					currentIndex += 1;
					


				}
				else
				{
					accurateLine = line.substr(currentIndex, line.find('$', currentIndex) - currentIndex);
					int $ = std::stoi(accurateLine);
					setAfter($, '$');
					currentIndex += (1 + line.find('$', currentIndex) - currentIndex);
				}
			}

		}
		
	}
}


void GridSettings::goodConstruction()
{
	if (numC != -1 && numL != -1 && verificationFileLoader==false)//check si box a changé 
	{
		 Grille* wdig = new Grille(numC, numL); runOnce = true;
		 wdg->assignV2(wdig);
		 wdig->check();
		 wdig->show();
		 hide();
	}
	else if (verificationFileLoader == true && numC !=-1  && numL !=-1 )
	{
		Grille* wdig = new Grille(numC, numL); runOnce = true;
		readFile();
		wdg->assignV2(wdig);//tab after de wdig se fait initialiser
		wdig->check();
		wdig->show();
		hide();
	}
	else if (verificationFileLoader)
	{
		
		readFile();
		Grille* wdig = new Grille(configGridC, configGridL); runOnce = true;
		this->fillAterVB();
		wdg->assignV2(wdig);//tab after de wdig se fait initialiser
		wdig->check();
		wdig->show();
		this->hide();
	}
}

void GridSettings::initL()
{
	QString temp;
	temp=TextBoxL->displayText();
	numL = temp.toInt();
}

void GridSettings::initC()
{
	QString temp;
	temp = TextBoxC->displayText();
	numC = temp.toInt();
}




