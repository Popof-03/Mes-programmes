from time import sleep
import requests
import sys
import urllib.request, urllib.error
from PyQt5 import QtGui
from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QApplication, QWidget, QHBoxLayout, QVBoxLayout, QLabel, QPushButton,QCheckBox,QPlainTextEdit,QFrame





class winWithImages(QWidget):
    def __init__(self):
        super(winWithImages, self).__init__()
        self.listeQL = []
        self.listeQP = []
        self.voteJ1=QPushButton()
        self.voteJ2=QPushButton()
        self.voteJ3=QPushButton()
        self.voteJ4=QPushButton()
        self.label=QLabel()
        self.frame=QFrame()
        self.histJ1=[]
        self.histJ2=[]
        self.histJ3=[]
        self.histJ4=[]
        self.background=QLabel()
        self.lePetit0 = QHBoxLayout()
        self.check0=QHBoxLayout()
        self.leGrandJames = QVBoxLayout()
        self.voteeJ1=QHBoxLayout()
        self.voteeJ2=QHBoxLayout()
        self.voteeJ3=QHBoxLayout()
        self.voteeJ4=QHBoxLayout()
        self.score=QVBoxLayout()
        self.checkboxes=[]
        self.player=0
        self.button = QPushButton()
        self.voteJ1.clicked.connect(self.clickMee)
        self.voteJ2.clicked.connect(self.clickMee)
        self.voteJ3.clicked.connect(self.clickMee)
        self.voteJ4.clicked.connect(self.clickMee)
        self.QlabelAMettre=0
        self.scoreJ1=0
        self.scoreJ2=0
        self.scoreJ3=0
        self.scoreJ4=0
        self.scoreJ1G=0
        self.scoreJ2G=0
        self.scoreJ3G=0
        self.scoreJ4G=0
        self.voteJ1.setText("Je vote le joueur 1")
        self.voteJ2.setText("Je vote le joueur 2")
        self.voteJ3.setText("Je vote le joueur 3")
        self.voteJ4.setText("Je vote le joueur 4")
        self.runOnce=False
        self.restart=QPushButton()
        self.restart.setText("restart?????????????????????????????")
        self.restart.setBaseSize(1500,500)
        self.restart.clicked.connect(self.start)
        self.SJ1=QLabel()
        self.SJ2=QLabel()
        self.SJ3=QLabel()
        self.SJ4=QLabel()
        self.start()
        
    def construireHist(self, a):
        for i in range(9):
            if self.player>6:
                continue
            elif self.checkboxes[i]==self.sender() and self.player==0 and a==2:
                self.QlabelAMettre=i
                self.histJ1.append(self.listeQL[i])
            elif self.checkboxes[i]==self.sender() and self.player==1 and a==2:
                self.QlabelAMettre=i
                self.histJ2.append(self.listeQL[i+9])
            elif self.checkboxes[i]==self.sender() and self.player==2 and a==2:
                self.QlabelAMettre=i
                self.histJ3.append(self.listeQL[i+18])
            elif self.checkboxes[i]==self.sender() and self.player==3 and a==2:
                self.QlabelAMettre=i
                self.histJ4.append(self.listeQL[i+27])
            elif self.checkboxes[i]==self.sender() and self.player==0 and a==0:
                self.QlabelAMettre=i
                self.histJ1.remove(self.listeQL[i])
            elif self.checkboxes[i]==self.sender() and self.player==1 and a==0:
                self.QlabelAMettre=i
                self.histJ2.remove(self.listeQL[i+9])
            elif self.checkboxes[i]==self.sender() and self.player==2 and a==0:
                self.QlabelAMettre=i
                self.histJ3.remove(self.listeQL[i+18])
            elif self.checkboxes[i]==self.sender() and self.player==3 and a==0:
                self.QlabelAMettre=i
                self.histJ4.remove(self.listeQL[i+27])
    def clickMee (self) :
        if self.sender()==self.voteJ1:
            self.scoreJ1+=1
            self.scoreJ1G+=1
        elif self.sender()==self.voteJ2:
            self.scoreJ2+=1
            self.scoreJ2G+=1
        elif self.sender()==self.voteJ3:
            self.scoreJ3+=1
            self.scoreJ3G+=1
        elif self.sender()==self.voteJ4:
            self.scoreJ4+=1
            self.scoreJ4G+=1
        if self.scoreJ1+self.scoreJ2+self.scoreJ3+self.scoreJ4>=4:
            self.gagnant()
    def gagnant(self):
        self.button.hide()
        self.frame.hide()
        self.leGrandJames.addWidget(self.restart)
        self.restart.show()
        if self.scoreJ1==self.scoreJ2 and self.scoreJ1==self.scoreJ3 and self.scoreJ1==self.scoreJ4:
            for i in range(3):
                self.histJ1[i].hide()
                self.histJ3[i].hide()
                self.histJ2[i].hide()
                self.histJ4[i].hide()
                self.voteJ1.hide()
                self.voteJ2.hide()
                self.voteJ3.hide()
                self.voteJ4.hide()
            self.label.setText("aucun gagnant, on me baise pas comme ca moi")
            self.label.show()
        elif self.scoreJ1>self.scoreJ2 and self.scoreJ1>self.scoreJ3 and self.scoreJ1>self.scoreJ4:
            for i in range(3):
                self.histJ2[i].hide()
                self.histJ3[i].hide()
                self.histJ4[i].hide()
                self.voteJ1.hide()
                self.voteJ2.hide()
                self.voteJ3.hide()
                self.voteJ4.hide()
                self.scoreDisplay()
            for i in range (3):
                self.voteeJ1.addWidget(self.histJ1[i])
                self.voteeJ1.addWidget(self.voteJ1)
                self.histJ1[i].show()
        elif self.scoreJ2>self.scoreJ1 and self.scoreJ2>self.scoreJ3 and self.scoreJ2>self.scoreJ4:
            for i in range(3):
                self.histJ1[i].hide()
                self.histJ3[i].hide()
                self.histJ4[i].hide()
                self.voteJ1.hide()
                self.voteJ2.hide()
                self.voteJ3.hide()
                self.voteJ4.hide()
                self.scoreDisplay()

            for i in range (3):
                self.voteeJ2.addWidget(self.histJ2[i])
                self.voteeJ2.addWidget(self.voteJ2)
                self.histJ2[i].show()
        elif self.scoreJ3>self.scoreJ1 and self.scoreJ3>self.scoreJ2 and self.scoreJ3>self.scoreJ4:
            for i in range(3):
                self.histJ1[i].hide()
                self.histJ2[i].hide()
                self.histJ4[i].hide()
                self.voteJ1.hide()
                self.voteJ2.hide()
                self.voteJ3.hide()
                self.voteJ4.hide()
                self.scoreDisplay()
            for i in range (3):
             self.lePetit0.addWidget(self.histJ3[i])
             self.lePetit0.addWidget(self.voteJ3)
             self.histJ3[i].show()
        elif self.scoreJ4>self.scoreJ1 and self.scoreJ4>self.scoreJ3 and self.scoreJ4>self.scoreJ2:
            for i in range(3):
                self.histJ1[i].hide()
                self.histJ3[i].hide()
                self.histJ2[i].hide()
                self.voteJ1.hide()
                self.voteJ2.hide()
                self.voteJ3.hide()
                self.voteJ4.hide()
                self.scoreDisplay()
            for i in range (3):
             self.lePetit0.addWidget(self.histJ4[i])
             self.lePetit0.addWidget(self.voteJ4)
             self.histJ4[i].show() 
    def clickMe(self): 

        if self.player ==0 and (self.histJ1.__len__()>3 or self.histJ1.__len__()<3 and self.histJ1.__len__()>1):
                        self.player+=6
                        for i in range (9):
                            self.checkboxes[i].setCheckState(False)
                        self.histJ1.clear()
                        self.player-=6
        elif self.player ==1 and (self.histJ2.__len__()>3 or self.histJ2.__len__()<3 and self.histJ2.__len__()>1):
                        self.player+=6
                        for i in range (9):
                            self.checkboxes[i].setCheckState(False)
                        self.histJ2.clear()
                        self.player-=6
        elif self.player ==2  and (self.histJ3.__len__()>3 or self.histJ3.__len__()<3 and self.histJ3.__len__()>1):
                        self.player+=6
                        for i in range (9):
                            self.checkboxes[i].setCheckState(False)
                        self.histJ3.clear()
                        self.player-=6
        elif self.player ==3 and (self.histJ4.__len__()>3 or self.histJ4.__len__()<3 and self.histJ4.__len__()>1):
                        self.player+=6
                        for i in range (9):
                            self.checkboxes[i].setCheckState(False)
                        self.histJ4.clear()
                        self.player-=6
        elif self.player==0 and self.histJ1.__len__()==3:
                        self.player+=1
                        self.reinitialiser()
        elif self.player==1 and self.histJ2.__len__()==3:
                        self.player+=1
                        self.reinitialiser()
        elif self.player==2 and self.histJ3.__len__()==3:
                        self.player+=1
                        self.reinitialiser()
        elif self.player==3 and self.histJ4.__len__()==3:
                        self.player+=1
                        self.reinitialiser()
        elif self.player==0 :
                if self.runOnce==True:
                    
                    
                    
                
                    for i in range(9):
                        self.button.hide()
                        self.frame.hide()
                        self.leGrandJames.addWidget(self.button)
                        self.button.show()
                        self.leGrandJames.addWidget(self.frame)
                        self.frame.setStyleSheet("background-image: url(background.jpg)")
                        self.frame.show()
                        self.runOnce=True
                        self.leGrandJames.addLayout(self.lePetit0)
                        self.listeQL[i].show()
                        self.lePetit0.addWidget(self.listeQL[i]) 
                        self.player+=6 
                        self.checkboxes[i].setCheckState(False)
                        self.player-=6 
                        self.checkboxes[i].show()
                        self.lePetit0.addWidget(self.checkboxes[i])
                        self.button.setText("j'ai fini,joueur 2 bouge ton fiak")
                        self.runOnce=True
                elif self.runOnce==False:
                    for i in range(9):
                        self.runOnce=True
                        self.listeQL[i].show()
                        self.lePetit0.addWidget(self.listeQL[i]) 
                        self.player+=6 
                        self.checkboxes[i].setCheckState(False)
                        self.player-=6 
                        self.lePetit0.addWidget(self.checkboxes[i])
                        self.button.setText("j'ai fini,joueur 2 bouge ton fiak")
                        self.runOnce=True
    def reinitialiser(self):
        if self.player==1:
            for i in range(9):#le state change et c est co a consthist
                self.player+=6
                self.listeQL[i].hide()
                self.checkboxes[i].setCheckState(False)
                self.checked=0
                self.player-=6
            for i in range(9,18):
                self.button.setText("j'ai fini,joueur 3 bouge ton fiak")
                self.listeQL[i].show()
                self.lePetit0.addWidget(self.listeQL[i])
                self.lePetit0.addWidget(self.checkboxes[i-9])   
        elif self.player==2 :
            for i in range(9,18):
                self.player+=6
                self.listeQL[i].hide()
                self.checkboxes[i-9].setCheckState(False)
                self.checked=0
                self.player-=6
            for i in range(18,27):
                self.button.setText("j'ai fini,joueur 4 bouge ton fiak")
                self.listeQL[i].show()
                self.lePetit0.addWidget(self.listeQL[i])
                self.lePetit0.addWidget(self.checkboxes[i-18])   
        elif self.player==3:
            for i in range(18,27):
                self.player+=6
                self.listeQL[i].hide()
                self.checkboxes[i-18].setCheckState(False)
                self.checked=0
                self.player-=6
            for i in range(27,36):
                self.button.setText("FINITO")
                self.listeQL[i].show()
                self.lePetit0.addWidget(self.listeQL[i])
                self.lePetit0.addWidget(self.checkboxes[i-27])
        elif self.player==4:
            self.button.setText("VOTE!!!!")
            self.button.setBaseSize(1500,500)
            for i in range(27,36):
                self.listeQL[i].hide()
                self.checkboxes[i-27].hide()
                self.checked=0
                self.vote()
    def vote(self):
        for i in range (36):
            self.listeQL[i].hide()
        for i in range (3):#presentation histoire J1
            self.voteeJ1.addWidget(self.histJ1[i])
            self.histJ1[i].show()
        for i in range (3):
            self.voteeJ2.addWidget(self.histJ2[i])
            self.histJ2[i].show()
        for i in range (3):
            self.voteeJ3.addWidget(self.histJ3[i])
            self.histJ3[i].show()
        for i in range (3):
            self.voteeJ4.addWidget(self.histJ4[i])
            self.histJ4[i].show()
        self.frame.hide()
        self.voteeJ1.addWidget(self.voteJ1)
        self.voteeJ2.addWidget(self.voteJ2)
        self.voteeJ3.addWidget(self.voteJ3)
        self.voteeJ4.addWidget(self.voteJ4)
        self.voteJ1.show()
        self.voteJ2.show()
        self.voteJ3.show()
        self.voteJ4.show()
        self.leGrandJames.addLayout(self.voteeJ1)
        self.leGrandJames.addLayout(self.voteeJ2)
        self.leGrandJames.addLayout(self.voteeJ3)
        self.leGrandJames.addLayout(self.voteeJ4)
        self.setLayout(self.leGrandJames)
    def start (self):
     tour=0
     for j in range(12):
        url = "https://explosm.net/api/get-random-panels?"
        requete = requests.get(url)
        requete = requete.text
        image1 = requete[find_nth_overlapping(requete, '.', 1) - 12:find_nth_overlapping(requete, '.', 1)]
        image2 = requete[find_nth_overlapping(requete, '.', 2) - 12:find_nth_overlapping(requete, '.', 2)]
        image3 = requete[find_nth_overlapping(requete, '.', 3) - 12:find_nth_overlapping(requete, '.', 3)]
        image1 = "https://rcg-cdn.explosm.net/panels/"+image1+".png"
        image2 = "https://rcg-cdn.explosm.net/panels/"+image2+".png"
        image3 = "https://rcg-cdn.explosm.net/panels/"+image3+".png"
        images = [image1, image2, image3]
        for i in range(3):
            tour += 1
            URL = images[i]
            filename = "image" + str(tour - 1) + ".png"
            urllib.request.urlretrieve(URL, filename)
        self.player+=6
        
        
        self.restart.hide()
        self.SJ1.hide()
        self.SJ2.hide()
        self.SJ3.hide()
        self.SJ4.hide()

        for i in range (9):
            c=QCheckBox()
            c.stateChanged[int].connect(self.construireHist)
            self.checkboxes.append(c)   
        for i in range(0,36):
                    a = QLabel()
                    b = QPixmap("image" + str(i) + ".png")
                    self.listeQL.append(a)
                    self.listeQP.append(b)
                    self.listeQP[i].setDevicePixelRatio(1.75)
                    self.listeQL[i].setPixmap(self.listeQP[i])
                    self.listeQL[i].hide()
        self.histJ1=[]
        self.histJ2=[]
        self.histJ3=[]
        self.histJ4=[]
        self.player=0
        self.scoreJ1=0
        self.scoreJ2=0
        self.scoreJ3=0
        self.scoreJ4=0
        self.button.setText("Start,Heeeeem zzz est partii let'sss go")
        self.button.clicked.connect(self.clickMe)
        self.leGrandJames.addWidget(self.button)
        self.frame.setStyleSheet("background-image: url(background.jpg)")
        self.leGrandJames.addWidget(self.frame)
        self.leGrandJames.addLayout(self.lePetit0)
        self.leGrandJames.addLayout(self.check0)
        self.leGrandJames.addLayout(self.score)
        self.setLayout(self.leGrandJames)
        self.button.show()
    def scoreDisplay(self):
        self.SJ1.setText("score du J1"+" "+str(self.scoreJ1G))
        self.SJ2.setText("score du J2"+" "+str(self.scoreJ2G))
        self.SJ3.setText("score du J3"+" "+str(self.scoreJ3G))
        self.SJ4.setText("score du J4"+" "+str(self.scoreJ4G))
        self.SJ1.show()
        self.SJ2.show()
        self.SJ3.show()
        self.SJ4.show()
        self.score.addWidget(self.SJ1)
        self.score.addWidget(self.SJ2)
        self.score.addWidget(self.SJ3)
        self.score.addWidget(self.SJ4)


def find_nth_overlapping(haystack, needle, n):
    start = haystack.find(needle)
    while start >= 0 and n > 1:
        start = haystack.find(needle, start + 1)
        n -= 1
    return start
a = QApplication(sys.argv)
win = winWithImages()
win.show()
sys.exit(a.exec())

