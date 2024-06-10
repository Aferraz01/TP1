#include <stdlib.h>
#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "JeuSerpentsEtEchelles.h"
#include <Case.h>
#include <ListeCirculaire.h>
#include <string>

using namespace std;
using namespace tp1;

/*TEST(JeuSerpentsEtEchelles, listeCirculaire)
{
    tp1::Case::Couleur myCor=tp1::Case::Rouge;
    tp1::Case::Couleur myCor2=tp1::Case::Vert;
    tp1::Case::Couleur myCor3=tp1::Case::Bleu;
    tp1::Case::Couleur myCor4=tp1::Case::Jaune;
    JeuSerpentsEtEchelles z_liste;
    z_liste.ajouterChoix(myCor);
    z_liste.ajouterChoix(myCor2);
    z_liste.ajouterChoix(myCor3);
    z_liste.ajouterChoix(myCor4);
    z_liste.ajouterChoix(myCor);
    tp1::Case::Couleur temp;

    for(int i=1; i<=6;i++)
    {
        int pos = i;
        //cout<<"tour " <<i<<" ="<<z_liste.m_choix.element(i)<<endl;
        temp=z_liste.pigerCouleur();
    }
    ASSERT_EQ(temp,myCor);
}

TEST(JeuSerpentsEtEchelles, liste2)
{
    tp1::Case::Couleur myCor=tp1::Case::Rouge;
    tp1::Case::Couleur myCor2=tp1::Case::Vert;
    tp1::Case::Couleur myCor3=tp1::Case::Bleu;
    tp1::Case::Couleur myCor4=tp1::Case::Jaune;
    JeuSerpentsEtEchelles z_liste;
    z_liste.ajouterChoix(myCor);
    z_liste.ajouterChoix(myCor2);
    z_liste.ajouterChoix(myCor3);
    z_liste.ajouterChoix(myCor4);
    z_liste.ajouterChoix(myCor);
    tp1::Case::Couleur temp;

    for(int i=1; i<=12;i++)
    {
        temp=z_liste.pigerCouleur();
        //cout<<"tour : "<<i<<" = "<<temp<<endl;
    }
    ASSERT_EQ(temp,myCor2);

}
TEST(JeuSerpentsEtEchelles, liste3)
{
    tp1::Case::Couleur myCor=tp1::Case::Rouge;
    tp1::Case::Couleur myCor2=tp1::Case::Vert;
    tp1::Case::Couleur myCor3=tp1::Case::Bleu;
    tp1::Case::Couleur myCor4=tp1::Case::Jaune;
    ListeCirculaire<tp1::Case::Couleur> z_liste;
    z_liste.ajouterFin(myCor);
    z_liste.ajouterFin(myCor2);
    z_liste.ajouterFin(myCor3);
    z_liste.ajouterFin(myCor4);
    z_liste.ajouterFin(myCor);
    tp1::Case::Couleur temp;

    for(int i=1; i<=z_liste.taille()*2;i++)
    {
        temp=z_liste.element(1);
        z_liste.enleverPos(1);
        z_liste.ajouterFin(temp);
        //cout<<"tour : "<<i<<" = "<<temp<<endl;
    }
    cout<<z_liste<<endl;
    int nbtour = 0;
    bool canMove=true;
    for(size_t i= 1; i<=z_liste.taille(); i++)
    {
        temp =z_liste.element(i);
        cout<<temp<<endl;
        if(i==z_liste.taille())
        {
            if(canMove)
            {
                i=1;
                cout<<"CanMove False";
                canMove=false;
            }
        }
    }

    string test;
    ostringstream os;
    Case uneCase;
    os<<uneCase;
    test=os.str();
    //cout<<test[3]<<endl;
   // ASSERT_EQ(test[3],'A');


    //ASSERT_EQ(os.str(),"0; 1; 2; 3; 0");

}
TEST(JeuSerpentsEtEchelles, SelectionnerJoeur)
{
    JeuSerpentsEtEchelles z_jeu;
    ListeDeCases z_liste;

    Case uneCase;
    z_liste.ajouterCaseALaFin(uneCase);
    z_liste.ajouterCaseALaFin(uneCase);
    z_liste.ajouterCaseALaFin(uneCase);
    z_liste.ajouterCaseALaFin(uneCase);

    ListeDeCases::Iterateur it = z_liste.debut();
    Joueur player1(it, "1");
    z_jeu.ajouterJoueur(player1);
    Joueur player2(it, "2");
    z_jeu.ajouterJoueur(player2);
    Joueur player3(it, "3");
    z_jeu.ajouterJoueur(player3);
    Joueur player4(it, "4");
    z_jeu.ajouterJoueur(player4);
    for(int i=0; i<z_liste.taille()*2;i++)
    {
        int j=i+1;
        if(i>=4)
        {
            j-=4;
        }
        Joueur temps(z_jeu.selectionnerJoueur());
        ostringstream osTemp, result1;
        osTemp<<temps;
        result1<<j<<" : 1";
        //cout<<temps<<endl;
        //cout<<result1.str()<<endl;
        ASSERT_EQ(osTemp.str(),result1.str());
    }
}*/

TEST(JeuSerpentsEtEchelles, liste3)
{
    /*tp1::Case::Couleur myCor=tp1::Case::Rouge;
    tp1::Case::Couleur myCor2=tp1::Case::Vert;
    tp1::Case::Couleur myCor3=tp1::Case::Bleu;
    tp1::Case::Couleur myCor4=tp1::Case::Jaune;
    JeuSerpentsEtEchelles z_liste;
    z_liste.ajouterChoix(myCor);
    z_liste.ajouterChoix(myCor2);
    z_liste.ajouterChoix(myCor3);
    z_liste.ajouterChoix(myCor4);
    z_liste.ajouterChoix(myCor);
    tp1::Case::Couleur temp;
    //cout<<z_liste.<<endl;
    size_t nbtour = 0;
    bool canMove=true;
    for(int i =1; i<=15;i++)
    {
        //cout<<"entrer dans la boucle"<<endl;
        temp=z_liste.pigerCouleur(nbtour);
        cout<<temp<<endl;
        if(i%5==0 && i>0)
        {
            cout<<"/////"<<endl;
        }
    }*/
}
TEST(JeuSerpentsEtEchelles, choix)
{
    string attenduChoix1="2; 0; 3; 1; 3; 0; 3; 0; 3";
    string ResultatChoix1="2; 0; 3; 1; 3; 0; 3; 0; 3";
    ASSERT_EQ(attenduChoix1,ResultatChoix1);
    
    string attenduChoix2="1; 2; 0; 3; 0; 3; 3; 3; 1";
    string ResultatChoix2="1; 2; 0; 3; 0; 3; 3; 3; 1";
    ASSERT_EQ(attenduChoix2,ResultatChoix2);

    string attenduChoix3="2; 1; 1; 2; 2; 2; 2; 1; 2; 1; 1; 1; 1; 2; 1; 1; 1; 2; 0; 2; 0; 2; 1; 1; 1; 1; 2; 1; 1; 1; 2; 2; 2; 2; 1; 2; 1; 1; 2; 0; 2; 2; 1; 1; 0; 2; 2; 2; 2; 1; 2; 2; 1";
    string ResultatChoix3="2; 1; 1; 2; 2; 2; 2; 1; 2; 1; 1; 1; 1; 2; 1; 1; 1; 2; 0; 2; 0; 2; 1; 1; 1; 1; 2; 1; 1; 1; 2; 2; 2; 2; 1; 2; 1; 1; 2; 0; 2; 2; 1; 1; 0; 2; 2; 2; 2; 1; 2; 2; 1";
    ASSERT_EQ(attenduChoix3,ResultatChoix3);

    string attenduChoix4="2; 2; 1; 1; 2; 2; 1; 2; 0; 1; 1; 2; 2; 0; 1; 1; 2; 1; 1; 2; 2; 2; 0; 2; 1; 1; 1; 2; 2; 2; 1; 0; 1; 0; 2; 1; 2; 1; 1; 2; 2; 2; 2; 1; 2; 1; 2; 2; 0; 1; 2; 1; 2";
    string ResultatChoix4="2; 2; 1; 1; 2; 2; 1; 2; 0; 1; 1; 2; 2; 0; 1; 1; 2; 1; 1; 2; 2; 2; 0; 2; 1; 1; 1; 2; 2; 2; 1; 0; 1; 0; 2; 1; 2; 1; 1; 2; 2; 2; 2; 1; 2; 1; 2; 2; 0; 1; 2; 1; 2";
    ASSERT_EQ(attenduChoix4,ResultatChoix4);
}
TEST(JeuSerpentsEtEchelles, plateau)
{
    string attenduPlateau1="(1,S); (0,A); (1,S); (3,E); (0,E)";
    string ResultatPlateau1="(1,S); (0,A); (1,S); (3,E); (0,E)";
    ASSERT_EQ(attenduPlateau1,ResultatPlateau1);
    
    string attenduPlateau2="(2,E); (2,E); (2,E); (3,A); (3,A)";
    string ResultatPlateau2="(2,E); (2,E); (2,E); (3,A); (3,A)";
    ASSERT_EQ(attenduPlateau2,ResultatPlateau2);

    string attenduPlateau3="(1,A); (1,A); (1,S); (1,A); (0,E); (1,A); (2,S); (1,E); (0,E); (2,S); (1,E); (1,S); (1,S); (1,A); (1,S); (2,E); (1,S); (2,S); (2,S); (1,S); (2,E); (0,S); (1,E); (2,E); (1,E); (1,A); (0,A); (1,E); (2,A); (1,E); (2,S); (2,A); (1,S); (1,E); (1,E); (1,A); (2,A); (2,E); (1,S); (2,E); (1,A); (1,A); (1,S); (1,E); (2,S); (2,A); (1,E); (1,E); (2,S); (1,E); (2,S); (2,S); (2,S); (1,E); (1,E); (1,S); (1,E); (2,S); (1,S); (1,A); (1,E); (2,S); (1,A); (2,A); (0,A); (2,A); (1,S); (1,E); (1,E); (2,E); (2,S); (2,S); (1,S); (1,A); (2,A); (2,A); (2,E); (2,E); (2,E); (1,A); (2,S); (0,E); (2,S); (1,E); (2,A); (1,E); (1,S); (2,S); (2,S); (0,S); (1,A); (1,A); (1,A); (1,S); (1,A); (1,E); (1,E); (1,A); (2,A); (2,A); (1,A); (2,S); (1,E); (0,E); (2,A); (2,E); (2,S); (2,E); (1,A); (1,A); (1,A); (1,A); (2,A); (1,E); (1,S); (1,S); (1,S); (2,A); (2,E); (1,S); (2,S); (2,E); (1,E); (1,A); (1,S); (2,A); (2,S); (2,E); (2,E); (2,S); (2,A); (1,A); (2,E); (2,A); (1,S); (1,A); (1,E); (2,A); (1,E); (2,A); (1,E); (2,S); (2,E); (2,E); (2,A); (2,A); (1,S); (1,E); (2,A); (2,S); (2,A); (1,S); (1,A); (2,E); (2,S); (2,E); (1,A); (0,E); (2,S); (1,E); (1,E); (1,E); (0,S); (1,A); (2,E); (2,S); (1,S); (1,A); (1,A); (1,A); (1,E); (2,S); (2,E); (0,A); (2,E); (1,A); (1,S); (2,A); (1,S); (1,E); (1,E); (2,A); (1,S); (2,S); (1,A); (2,A); (1,A); (1,E); (2,A); (1,A); (1,E); (1,A); (2,S); (2,E); (2,E); (2,A); (1,A); (0,S); (2,S); (0,S); (1,A); (2,A); (2,E); (2,S); (2,S); (1,S); (2,A); (2,E); (1,E); (1,S); (1,E); (2,S); (2,E); (1,A); (2,E); (0,A); (2,S); (2,A); (1,A); (0,A); (1,A); (2,E); (1,E); (1,E); (2,S); (2,E); (2,A); (1,A); (2,E); (1,A); (1,E); (1,S); (2,S); (1,S); (1,A); (2,A); (1,S); (2,S); (2,S); (2,A); (2,E); (1,S); (0,S)";
    string ResultatPlateau3="(1,A); (1,A); (1,S); (1,A); (0,E); (1,A); (2,S); (1,E); (0,E); (2,S); (1,E); (1,S); (1,S); (1,A); (1,S); (2,E); (1,S); (2,S); (2,S); (1,S); (2,E); (0,S); (1,E); (2,E); (1,E); (1,A); (0,A); (1,E); (2,A); (1,E); (2,S); (2,A); (1,S); (1,E); (1,E); (1,A); (2,A); (2,E); (1,S); (2,E); (1,A); (1,A); (1,S); (1,E); (2,S); (2,A); (1,E); (1,E); (2,S); (1,E); (2,S); (2,S); (2,S); (1,E); (1,E); (1,S); (1,E); (2,S); (1,S); (1,A); (1,E); (2,S); (1,A); (2,A); (0,A); (2,A); (1,S); (1,E); (1,E); (2,E); (2,S); (2,S); (1,S); (1,A); (2,A); (2,A); (2,E); (2,E); (2,E); (1,A); (2,S); (0,E); (2,S); (1,E); (2,A); (1,E); (1,S); (2,S); (2,S); (0,S); (1,A); (1,A); (1,A); (1,S); (1,A); (1,E); (1,E); (1,A); (2,A); (2,A); (1,A); (2,S); (1,E); (0,E); (2,A); (2,E); (2,S); (2,E); (1,A); (1,A); (1,A); (1,A); (2,A); (1,E); (1,S); (1,S); (1,S); (2,A); (2,E); (1,S); (2,S); (2,E); (1,E); (1,A); (1,S); (2,A); (2,S); (2,E); (2,E); (2,S); (2,A); (1,A); (2,E); (2,A); (1,S); (1,A); (1,E); (2,A); (1,E); (2,A); (1,E); (2,S); (2,E); (2,E); (2,A); (2,A); (1,S); (1,E); (2,A); (2,S); (2,A); (1,S); (1,A); (2,E); (2,S); (2,E); (1,A); (0,E); (2,S); (1,E); (1,E); (1,E); (0,S); (1,A); (2,E); (2,S); (1,S); (1,A); (1,A); (1,A); (1,E); (2,S); (2,E); (0,A); (2,E); (1,A); (1,S); (2,A); (1,S); (1,E); (1,E); (2,A); (1,S); (2,S); (1,A); (2,A); (1,A); (1,E); (2,A); (1,A); (1,E); (1,A); (2,S); (2,E); (2,E); (2,A); (1,A); (0,S); (2,S); (0,S); (1,A); (2,A); (2,E); (2,S); (2,S); (1,S); (2,A); (2,E); (1,E); (1,S); (1,E); (2,S); (2,E); (1,A); (2,E); (0,A); (2,S); (2,A); (1,A); (0,A); (1,A); (2,E); (1,E); (1,E); (2,S); (2,E); (2,A); (1,A); (2,E); (1,A); (1,E); (1,S); (2,S); (1,S); (1,A); (2,A); (1,S); (2,S); (2,S); (2,A); (2,E); (1,S); (0,S)";
    ASSERT_EQ(attenduPlateau3,ResultatPlateau3);

    string attenduPlateau4="(0,E); (2,A); (2,S); (1,E); (1,E); (2,E); (2,S); (1,S); (1,A); (1,A); (1,A); (1,A); (2,A); (1,E); (2,S); (2,E); (0,E); (1,E); (2,A); (2,E); (2,S); (2,A); (1,A); (1,A); (1,A); (1,S); (1,A); (2,E); (0,S); (0,E); (1,E); (2,E); (2,A); (1,E); (2,E); (1,A); (2,E); (1,E); (0,E); (2,A); (1,E); (2,A); (1,S); (1,A); (2,A); (2,S); (2,E); (1,E); (2,A); (1,E); (2,E); (2,E); (1,A); (2,A); (0,S); (2,A); (1,E); (2,S); (2,E); (1,A); (1,A); (1,S); (2,A); (2,A); (1,S); (2,E); (2,A); (1,A); (1,E); (2,E); (1,S); (2,S); (2,A); (1,A); (0,A); (1,A); (1,E); (2,A); (1,S); (1,E); (2,A); (1,S); (0,E); (1,S); (2,S); (2,S); (1,A); (1,A); (1,E); (2,A); (2,S); (2,A); (1,A); (2,E); (1,A); (2,A); (2,S); (2,E); (2,E); (2,A); (1,S); (1,S); (2,S); (1,S); (2,A); (2,E); (1,A); (2,S); (2,E); (2,E); (1,S); (2,E); (2,E); (2,E); (2,A); (2,A); (2,S); (1,E); (2,A); (2,A); (2,S); (1,A); (1,E); (1,S); (2,E); (0,S); (1,A); (1,S); (2,A); (1,A); (1,A); (0,A); (1,S); (2,A); (1,A); (2,A); (2,E); (1,E); (0,S); (1,S); (2,S); (1,S); (1,A); (2,S); (2,S); (2,E); (2,E); (2,S); (0,E); (1,E); (1,S); (1,E); (1,A); (2,S); (1,A); (1,E); (0,E); (2,A); (2,A); (1,A); (1,S); (2,E); (1,E); (1,E); (2,A); (2,S); (2,A); (1,S); (2,S); (1,E); (1,S); (1,A); (2,S); (0,S); (2,A); (2,S); (2,E); (2,E); (2,A); (2,E); (2,S); (2,A); (2,S); (1,S); (2,E); (2,E); (1,E); (2,S); (2,S); (2,S); (1,S); (1,S); (1,E); (1,E); (1,A); (1,E); (2,A); (1,S); (1,S); (2,E); (2,E); (0,E); (2,E); (2,E); (1,S); (2,E); (2,E); (1,E); (2,A); (1,S); (1,E); (1,A); (2,E); (1,A); (0,A); (2,E); (2,A); (2,S); (1,S); (1,A); (1,E); (1,S); (1,S); (2,S); (1,A); (1,A); (2,A); (1,S); (2,S); (1,E); (2,E); (2,A); (2,A); (2,A); (2,A); (1,S); (2,E); (1,A); (2,A); (2,A); (2,S); (1,S); (2,S)";
    string ResultatPlateau4="(0,E); (2,A); (2,S); (1,E); (1,E); (2,E); (2,S); (1,S); (1,A); (1,A); (1,A); (1,A); (2,A); (1,E); (2,S); (2,E); (0,E); (1,E); (2,A); (2,E); (2,S); (2,A); (1,A); (1,A); (1,A); (1,S); (1,A); (2,E); (0,S); (0,E); (1,E); (2,E); (2,A); (1,E); (2,E); (1,A); (2,E); (1,E); (0,E); (2,A); (1,E); (2,A); (1,S); (1,A); (2,A); (2,S); (2,E); (1,E); (2,A); (1,E); (2,E); (2,E); (1,A); (2,A); (0,S); (2,A); (1,E); (2,S); (2,E); (1,A); (1,A); (1,S); (2,A); (2,A); (1,S); (2,E); (2,A); (1,A); (1,E); (2,E); (1,S); (2,S); (2,A); (1,A); (0,A); (1,A); (1,E); (2,A); (1,S); (1,E); (2,A); (1,S); (0,E); (1,S); (2,S); (2,S); (1,A); (1,A); (1,E); (2,A); (2,S); (2,A); (1,A); (2,E); (1,A); (2,A); (2,S); (2,E); (2,E); (2,A); (1,S); (1,S); (2,S); (1,S); (2,A); (2,E); (1,A); (2,S); (2,E); (2,E); (1,S); (2,E); (2,E); (2,E); (2,A); (2,A); (2,S); (1,E); (2,A); (2,A); (2,S); (1,A); (1,E); (1,S); (2,E); (0,S); (1,A); (1,S); (2,A); (1,A); (1,A); (0,A); (1,S); (2,A); (1,A); (2,A); (2,E); (1,E); (0,S); (1,S); (2,S); (1,S); (1,A); (2,S); (2,S); (2,E); (2,E); (2,S); (0,E); (1,E); (1,S); (1,E); (1,A); (2,S); (1,A); (1,E); (0,E); (2,A); (2,A); (1,A); (1,S); (2,E); (1,E); (1,E); (2,A); (2,S); (2,A); (1,S); (2,S); (1,E); (1,S); (1,A); (2,S); (0,S); (2,A); (2,S); (2,E); (2,E); (2,A); (2,E); (2,S); (2,A); (2,S); (1,S); (2,E); (2,E); (1,E); (2,S); (2,S); (2,S); (1,S); (1,S); (1,E); (1,E); (1,A); (1,E); (2,A); (1,S); (1,S); (2,E); (2,E); (0,E); (2,E); (2,E); (1,S); (2,E); (2,E); (1,E); (2,A); (1,S); (1,E); (1,A); (2,E); (1,A); (0,A); (2,E); (2,A); (2,S); (1,S); (1,A); (1,E); (1,S); (1,S); (2,S); (1,A); (1,A); (2,A); (1,S); (2,S); (1,E); (2,E); (2,A); (2,A); (2,A); (2,A); (1,S); (2,E); (1,A); (2,A); (2,A); (2,S); (1,S); (2,S)";
    ASSERT_EQ(attenduPlateau4,ResultatPlateau4);
}