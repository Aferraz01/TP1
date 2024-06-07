/////////////////////////////////////////////////////////////////////////////
//Fichier ListeDeCases.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeDeCases.cpp
 * \brief Ce fichier contient une implémentation de la classe ListeDeCases
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2024
 */

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "ListeDeCases.h"

#include <cassert>

using std::string;
using std::ostringstream;
using std::out_of_range;
using std::range_error;

namespace tp1
{

    ListeDeCases::ListeDeCases() : m_debut(nullptr), m_fin(nullptr), m_taille(0)
    {
        assert(invariant());
    }

    ListeDeCases::~ListeDeCases()
    {
        clear();
    }

    int ListeDeCases::taille() const
    {
        return m_taille;
    }

    bool ListeDeCases::estVide() const
    {
        return (taille()==0);
    }

    void ListeDeCases::ajouterCase(const Case& uneCase, int position)
    {

        assert(position>=1 and position<=taille()+1);
        /*try
        {erreurPosition(position);}
        catch(std::logic_error& e)
        {
         std::cout<<e.what();
        }*/

        //Si la liste est vide
        if(taille() ==0)
        {
         m_debut = m_fin = new Noeud(uneCase);
        }
        //Si l'insertion se fait au début
        else if (position==1)
        {
         ajouterCaseAuDebut(uneCase);
        }
        //Si l'insertion se produit à la fin
        else if(position==taille()+1)
        {
         m_fin = new Noeud(uneCase, nullptr, m_fin);
         m_fin->m_precedent->m_suivant = m_fin;
        }
        //Les autres positions
        else
        {
         Noeud* sentinelle = noeudAt(position-1);
         sentinelle = new Noeud(uneCase, sentinelle->m_suivant, sentinelle);
         sentinelle->m_suivant->m_precedent=sentinelle;
         sentinelle->m_precedent->m_suivant = sentinelle;
        } 
        m_taille++;
        assert(invariant());
    }

    void ListeDeCases::ajouterCaseAuDebut(const Case& uneCase)
    {
       m_debut = new Noeud(uneCase, m_debut);
       m_debut->m_suivant->m_precedent = m_debut;
    }
    void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
    {
         m_fin = new Noeud(uneCase, nullptr, m_fin);
         m_fin->m_precedent->m_suivant = m_fin;
         ++m_taille;
         assert(invariant());   
    }

    void ListeDeCases::enleverCase(int position)
    {
        assert(position>=1 and position<=taille());
        Noeud* sentinelle = noeudAt(position);

        //Edge case : if la liste a un seul élément
        if (taille()==1)
        {
         m_debut = m_fin = nullptr;
        }
        //Edge case : si la position est au dubét
        else if (m_debut==sentinelle)
        {
         m_debut=m_debut->m_suivant;
         m_debut->m_precedent=nullptr;
        }
        //Edge case : si la position est à la fin
        else if (m_fin==sentinelle)
        {
         m_fin=m_fin->m_precedent;
         m_fin->m_suivant=nullptr;
        }
        //Situation autres
        else
        {
         sentinelle->m_precedent->m_suivant = sentinelle->m_suivant;
         sentinelle->m_suivant->m_precedent=sentinelle->m_precedent;
        }
        sentinelle->m_suivant=nullptr;
        sentinelle->m_suivant=nullptr;
        delete sentinelle;

        int tailleTemp = taille();
        m_taille--;
        assert(tailleTemp>taille());
        assert(invariant());

    }

    const Case& ListeDeCases::caseA(int position) const
    {
      Noeud* sentinelle = noeudAt(position);
      return sentinelle->m_case;
    }

    ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const
    {
        Noeud* sentinelle = m_debut;
        for (int i =1; i<position;i++)
        {
         sentinelle = sentinelle->m_suivant;

        }
        return sentinelle;
    }


    void ListeDeCases::clear()
    {
      Noeud* sentinelle = m_debut;
      while(sentinelle!=nullptr)
      {
         m_debut=sentinelle;
         sentinelle=sentinelle->m_suivant;
         m_debut->m_suivant=nullptr;
         m_debut->m_precedent=nullptr;
         delete m_debut;
      }
      m_debut=nullptr;
      m_fin=nullptr;
      m_taille=0;
   
    }

    /**
     * \brief Fonction pour vérifier si les invariants sont respectés
    */
    bool ListeDeCases::invariant() const
    {
        return (taille()>-1);
    }
    // Le reste du code qui utilise surtout l'itérateur est fourni.
    // Ajoutez simplement les balises Doxygen.

    ListeDeCases::Iterateur ListeDeCases::debut() const
    {
       return Iterateur(*this);
    }

    ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste) :
       m_liste(liste), m_courant(liste.m_debut)
    {
    }

    ListeDeCases::Iterateur::~Iterateur()
    {
       m_courant = 0;
    }

    const Case& ListeDeCases::Iterateur::caseCourante() const
    {
       return m_courant->m_case;
    }

    bool ListeDeCases::Iterateur::existeCaseSuivante() const
    {
       return (m_courant != 0 && m_courant->m_suivant != 0);
    }

    ListeDeCases::Iterateur& ListeDeCases::Iterateur::operator ++()
    {
       if (existeCaseSuivante())
       {
          m_courant = m_courant->m_suivant;
       }
       else
       {
          m_courant = 0;
          throw out_of_range("L'iterateur ne peut pas aller à une case suivante.");
       }
       return *this;
    }

    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const
    {
       distance = 0;
       if (m_courant == 0)
       {
          return 0;
       }

       ListeDeCases::Noeud* suivant = m_courant->m_suivant;
       while (noeudMauvaiseCouleur(suivant, couleur))
       {
          suivant = suivant->m_suivant;
          distance++;
       }
       return suivant;
    }

    bool ListeDeCases::Iterateur::noeudMauvaiseCouleur(ListeDeCases::Noeud *noeud,
          Case::Couleur couleur) const
    {
       return (noeud != 0 && noeud->m_case.couleur != couleur);
    }

    void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur)
    {
       int distance = 0;
       m_courant = noeudSuivant(couleur, distance);
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case suivante de couleur " << couleur << ".";
          throw out_of_range(message.str());
       }
    }

    bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudSuivant(couleur, distance) != 0;
    }

    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const
    {
       distance = 0;
       if (m_courant == 0)
       {
          return 0;
       }

       ListeDeCases::Noeud* precedent = m_courant->m_precedent;
       while (noeudMauvaiseCouleur(precedent, couleur))
       {
          precedent = precedent->m_precedent;
          distance++;
       }
       return precedent;
    }

    void ListeDeCases::Iterateur::casePrecedente(Case::Couleur couleur)
    {
       int distance;
       m_courant = noeudPrecedent(couleur, distance);
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case precedente de couleur " << couleur
                << ".";
          throw out_of_range(message.str());
       }
    }

    bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudPrecedent(couleur, distance) != 0;
    }

    int ListeDeCases::Iterateur::positionCourante() const
    {
       Noeud *courant = m_liste.m_debut;
       if (courant == 0)
          throw range_error("positionCourante: La liste est vide");

       int i = 1;
       while (courant != m_courant)
       {
          courant = courant->m_suivant;
          i++;
       }
       return i;
    }

    bool ListeDeCases::Iterateur::estADerniereCase() const
    {
       return m_courant == m_liste.m_fin && m_courant != 0;
    }

    //Ne touchez surtout pas à cette fonction.
    std::ostream& operator<<(std::ostream& os, const ListeDeCases & liste)
    {
       if (liste.estVide())
       {
          os << "Liste de cases vide";
       }
       else
       {
          ListeDeCases::Iterateur iter = liste.debut();
          while (!iter.estADerniereCase())
          {
             os << iter.caseCourante() << "; ";
             ++iter;
          }
          os << iter.caseCourante();
       }

       return os;
    }

}
