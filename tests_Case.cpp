
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "Case.h"

using namespace std;
using namespace tp1;


TEST (Case, ConstructeurValide)
{
    Case::Couleur myCor = Case::Couleur::Vert;

    Case caseTest (Case::Rouge, Case::Serpent);
    Case caseTest2;
    Case caseTest3 (myCor, Case::Echelle);
    EXPECT_EQ(caseTest.couleur, 0);
    ASSERT_NE(caseTest2.couleur,0);
    ASSERT_EQ(caseTest3.couleur,1);
    ASSERT_EQ(caseTest2.decoration,0);
}

