
#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory>
#include <gtest/gtest.h>
#include "ListeDeCases.h"
#include "Case.h"
#include <stdexcept>
#include <cassert>


using namespace std;
using namespace tp1;

TEST(ListeDeCases, ConstructeurValide)
{
    ListeDeCases listeTest;
}

class UneListe : public::testing::Test
{
    public:

    UneListe () : t_liste(){};
    ListeDeCases t_liste;
};

TEST_F(UneListe, reqTaille)
{
    ASSERT_EQ(t_liste.taille(), 0);
}

TEST_F(UneListe, EstVide)
{
    ASSERT_TRUE(t_liste.estVide());
}

TEST_F(UneListe, ajouterCaseQuandVide)
{
    Case uneCase;//case par défaut
    //Ajoute case quand vide
    t_liste.ajouterCase(uneCase, 1);
    ASSERT_EQ(t_liste.taille(), 1);
    ostringstream os;
    os<<t_liste;
    ASSERT_EQ(os.str(), "(2,A)");
}

TEST_F(UneListe, ajouterPlusieursCase)
{
    //Ajoute case quand vide
    Case uneCase;
    t_liste.ajouterCase(uneCase, 1);
    //Ajouter case avec 1
    t_liste.ajouterCase(uneCase, 1);
    ASSERT_EQ(t_liste.taille(), 2);
    //Ajouter case à la position 1
    Case uneCase3(Case::Vert, Case::Echelle);
    t_liste.ajouterCase(uneCase3,1);
    ASSERT_EQ(t_liste.taille(), 3);
    //Ajouter à la fin
    Case uneCase4(Case::Jaune, Case::Aucune);
    t_liste.ajouterCase(uneCase4, t_liste.taille()+1);
    ASSERT_EQ(t_liste.taille(), 4);
    ostringstream os;
    os<<t_liste;
    ASSERT_EQ(os.str(), "(1,E); (2,A); (2,A); (3,A)");

    /*auto ptr = t_liste.debut();
    ++ptr;
    cout<<ptr.estADerniereCase()<<endl;*/
}
TEST_F(UneListe, ajouterCasePositionPrecise)
{
    Case uneCase;
    t_liste.ajouterCase(uneCase, 1);
    t_liste.ajouterCase(uneCase, 1);
    t_liste.ajouterCase(uneCase, 1);
    //Ajouter à la position 2
    Case uneCase4(Case::Jaune, Case::Aucune);
    t_liste.ajouterCase(uneCase4,2);
    ostringstream os;
    os<<t_liste;
    ASSERT_EQ(os.str(), "(2,A); (3,A); (2,A); (2,A)");
}

TEST_F(UneListe, ajouterCaseFin)
{
    Case uneCase;
    t_liste.ajouterCase(uneCase, 1);
    t_liste.ajouterCase(uneCase, 1);
    t_liste.ajouterCase(uneCase, 1);
    //Ajouter à la fin
    Case uneCase4(Case::Jaune, Case::Aucune);
    t_liste.ajouterCaseALaFin(uneCase4);
    ASSERT_EQ(t_liste.taille(), 4);
    ostringstream os;
    os<<t_liste;
    ASSERT_EQ(os.str(), "(2,A); (2,A); (2,A); (3,A)");
}
TEST_F(UneListe, ajouterCaseInvalide)
{
    Case uneCase;
    ASSERT_THROW(t_liste.ajouterCase(uneCase,0), std::range_error);

}

TEST_F(UneListe, enleverUneCase)
{
    Case uneCase;
    t_liste.ajouterCase(uneCase,1);
    Case uneCase2(Case::Bleu, Case::Echelle);
    t_liste.ajouterCase(uneCase2,1);
    Case uneCase4(Case::Jaune, Case::Aucune);
    t_liste.ajouterCaseALaFin(uneCase4);
    t_liste.ajouterCaseALaFin(uneCase);
    ostringstream os;
    os<<t_liste;
    ASSERT_EQ(os.str(), "(2,E); (2,A); (3,A); (2,A)");
    int pos = 3;
    t_liste.enleverCase(pos);
    ASSERT_EQ(t_liste.taille(),3);
    ostringstream os2;
    os2<<t_liste;
    ASSERT_EQ(os2.str(),"(2,E); (2,A); (2,A)");
}

TEST_F(UneListe, enleverCaseInvalide)
{
    Case uneCase;
    ASSERT_THROW(t_liste.enleverCase(0), std::logic_error);
}

TEST_F(UneListe,recupererCase)
{
    Case uneCase;
    t_liste.ajouterCase(uneCase,1);
    Case uneCase2(Case::Bleu, Case::Echelle);
    t_liste.ajouterCase(uneCase2,1);
    Case uneCase4(Case::Jaune, Case::Aucune);
    t_liste.ajouterCaseALaFin(uneCase4);
    t_liste.ajouterCaseALaFin(uneCase);
    int pos = 3;
    Case caseTest = t_liste.caseA(pos);
    ostringstream osCaseTest;
    osCaseTest<<caseTest;
    ostringstream osCase2;
    osCase2<<uneCase4;
    ASSERT_EQ(osCaseTest.str(), osCase2.str());
}

TEST_F(UneListe, recuperCaseInvalide)
{
    Case uneCase;
    t_liste.ajouterCase(uneCase,1);
    ASSERT_THROW(t_liste.caseA(10), std::range_error);
}