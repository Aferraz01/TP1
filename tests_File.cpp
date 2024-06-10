#include <stdlib.h>
#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "File.h"
#include <stdexcept>
#include "Case.h"
#include "ListeDeCases.h"
#include "ListeCirculaire.h"

using namespace std;
using namespace tp1;

class FileTest: public ::testing::Test
{
    public:
    
    //UneFile () : t_file(){};
    File <Case> t_file;

};

TEST_F(FileTest, videOk)
{
    ASSERT_TRUE(t_file.taille()==0);
}

TEST_F(FileTest,EnfilerOK)
{
    Case uneCase;
    t_file.enfiler(uneCase);
    ASSERT_TRUE(t_file.taille()==1);
}

TEST_F(FileTest, DefilerValide)
{
    Case uneCase(Case::Couleur::Rouge,Case::Decoration::Echelle);
    Case uneCase2;
    t_file.enfiler(uneCase);
    t_file.enfiler(uneCase2);
    auto x = t_file.defiler();
    ASSERT_TRUE(t_file.taille()==1);
    ostringstream os;
    os<<x;
    ASSERT_EQ(os.str(), "(0,E)");
}

TEST_F(FileTest,DefilerInvalide)
{
    ASSERT_THROW(t_file.defiler(),logic_error);
}

TEST_F(FileTest,Liste)
{
    tp1::Case::Couleur myCor=tp1::Case::Rouge;
    tp1::ListeCirculaire<tp1::Case::Couleur> z_liste;
    z_liste.ajouterFin(myCor);
    z_liste.ajouterFin(myCor);
    z_liste.ajouterFin(myCor);
    z_liste.ajouterFin(myCor);
    z_liste.ajouterFin(myCor);
    std::cout<<z_liste.taille()<<std::endl;
    for(int i = 0; i<2;i++)
    {
      int cpt=0;
      std::cout<<"Start"<<std::endl;
      for (int j=1; j<=z_liste.taille(); j++)
      {
         std::cout<<z_liste.element(j)<<std::endl;
         if(j==z_liste.taille())
         {
            std::cout<<"///////"<<std::endl;
            if(cpt!=3)
            {
               cpt++;
               j=1;
               std::cout<<"return to 0"<<std::endl;
            }
         }
      }
    }

}