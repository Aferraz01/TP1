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
#include <new>

#include "ListeDeCases.h"

#include <cassert>

using std::string;
using std::ostringstream;
using std::out_of_range;
using std::range_error;

namespace tp1
{
   /**
    * \fn ListeDeCases::ListeDeCases()
    * \brief Constructeur de ListeDeCases
    * \post Verifie que la liste a bien une taille de zero
    */
    ListeDeCases::ListeDeCases() : m_debut(nullptr), m_fin(nullptr), m_taille(0)
    {
        assert(invariant());
    }

    /**
     * \fn ListeDeCases::~ListeDeCases()
     * \brief Destructeur de la classe. Fait un nettoyage pour s'assurer que la memoire est liberee dans le heap
     */
    ListeDeCases::~ListeDeCases()
    {
      while(!estVide())//Parcours la liste jusqu'à temps qu'elle soit bide
      {
         enleverCase(1);//Appele primitive enleverCase. Toujours à la position 1 car le premier élément est retiré
      }
      delete m_debut;//delete les pointeurs de début et de fin et libère la mémoire
      delete m_fin;
    }

    /**
     * \fn int ListeDeCases::taille() const
     * \brief Retourne la taille de la liste
     * \return int m_taille
     */
    int ListeDeCases::taille() const
    {
        return m_taille;
    }

    /**
     * \fn bool ListeDeCases::estVide() const
     * \brief Verifie si la liste est vide
     * \return Vrai si vide. Faux sinon.
     */
    bool ListeDeCases::estVide() const
    {
        return (taille()==0);
    }

    /**
     * \fn void ListeDeCases::ajouterCase(const Case& uneCase, int position)
     * \brief Permet d'ajouter une case à une position donnee
     * \param[in] uneCase Case a inserer
     * \param[in] position int designant la position
     * \exception verifie si la position est dans la borne. Throw bad_alloc.
     * \post verifie invariant
     */
    void ListeDeCases::ajouterCase(const Case& uneCase, int position)
    {
      //verifie si la position existe
      if(position<1 || position >taille()+1)
      {
         throw range_error("La position n'existe pas. La liste est peut être vide.");
      }
      //Si la liste est vide
      //Edge case permettant de lier tête et queue
      //Ce edge case est du que les sentinelles sont partielles
      if(taille() ==0)
      {
         m_debut = m_fin = new Noeud(uneCase);//Debut et fin ont la meme case
      }
      //Si l'insertion se fait au début
      else if (position==1)
      {
         m_debut = new Noeud(uneCase, m_debut);//La case est au debut. Le pointeur suivant prend l'ancien debut
         m_debut->m_suivant->m_precedent = m_debut;//le pointeur precedent de la prochaine case pointe vers le nouveau debut
      }
      //Si l'insertion se produit à la fin
      else if(position==taille()+1)
      {
         m_fin = new Noeud(uneCase, nullptr, m_fin);//Nouveau fin de queu. Le nouveau noeud aura pour pointeur suivant une valeur nulle et le pointeur precedent l'ancien fin
         m_fin->m_precedent->m_suivant = m_fin;//la case avant a son pointeur suivant mis a jour pour pointer sur la nouvelle node
      }
      //Les autres positions
      else
      {
         Noeud* sentinelle = noeudAt(position-1);//Recupere pointeur a la position -1 puisqu'on veut inserer avant
         sentinelle = new Noeud(uneCase, sentinelle->m_suivant, sentinelle);//La sentinelle a une nouvelle case dont le pointeur suivant est celui de l'ancienne case et le pointeur precedent est la sentinelle
         sentinelle->m_suivant->m_precedent=sentinelle;//Le pointeur precedent de la prochaine case pointe vers la case courrante
         sentinelle->m_precedent->m_suivant = sentinelle;//Le pointeur suivant de la precedente case pointe vers la case courrante
      } 
      m_taille++;//incremente la taille
      assert(invariant());
    }
    /**
     * \fn void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
     * \brief ajoute une case a la fin de la liste
     * \param[in] uneCase Case
     */
    void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
    {
         ajouterCase(uneCase, taille()+1);//+1 pour indiquer qu'on veut insérer après le dernier élément  
    }

    /**
     * \fn void ListeDeCases::enleverCase(int position)
     * \brief Permet d'enlever une case a la position demandee
     * \param[in] position int
     * \exception Verifie si la position est contenue dans la liste. Permet aussi de voir si la liste n'est pas vide. Throw logic_error.
     */
    void ListeDeCases::enleverCase(int position)
    {
        if(position<1 || position>taille())
        {
         throw std::logic_error("La position n'est pas contenu de la liste. Verifier si la liste n'est pas vide.");
        }
        Noeud* sentinelle = noeudAt(position);//recupere le pointeur a la position demande

        //Edge case : if la liste a un seul élément
        if (taille()==1)
        {
         m_debut = m_fin = nullptr;//Les pointeurs de début et de fin doivent être nulle
        }
        //Edge case : si la position est au début
        else if (m_debut==sentinelle)
        {
         m_debut=m_debut->m_suivant;//Le pointeur debut est maintenant le pointeur suivant de la liste
         m_debut->m_precedent=nullptr;//Le pointeur suivant de début est maintenant null
        }
        //Edge case : si la position est à la fin
        else if (m_fin==sentinelle)
        {
         m_fin=m_fin->m_precedent;//Le pointeur de fin devient celui qui etait en avant dernier
         m_fin->m_suivant=nullptr;//Le pointeur suivant de fin est maintenant null
        }
        //Situation autres
        else
        {
         //Faut interchanger les position des pointeurs avant et apres la sentinelle
         sentinelle->m_precedent->m_suivant = sentinelle->m_suivant;//Le pointeur suivant de la case precedente est mis a jour. Pointe maintenant vers la case apres sentinelle
         sentinelle->m_suivant->m_precedent=sentinelle->m_precedent;//Le pointeur precdent de la prochaine case est mis a jour. Pointe maintenant vers la case avant sentinelle
        }
        //Nettoyage du heap
        sentinelle->m_suivant=nullptr;//Le pointeur suivant est null
        sentinelle->m_precedent=nullptr;//Le pointeur precedent est null
        delete sentinelle;//Le contenu de la sentinelle est efface du heap

        int tailleTemp = taille();//enregistre la taille pour assert
        m_taille--;//decroit la taille
        assert(tailleTemp>taille());//assure que la taille decroit de un
        assert(invariant());//assure que liste n'est pas negative

    }

    /**
     * \fn const Case& ListeDeCase::caseA(int position)
     * \brief Retrouve une case a une position precise
     * \param[in] position int : Position de l'element a retrouver
     * \return Case
     * \exception Verifie si la position est hors borne. Throw range_error advenant le cas.
     */
    const Case& ListeDeCases::caseA(int position) const
    {
      if(position<1 || position>taille())
        {
         throw range_error("La position n'est pas contenu de la liste. Verifier si la liste n'est pas vide.");
        }
      Noeud* sentinelle = noeudAt(position);
      return sentinelle->m_case;
    }

    /**
     * \fn Noeud* ListeDeCases::noeudAt(int position) const
     * \brief Retourne une case à la position
     * \param[in] position int
     * \return Noueud* pointeur sur la case
     * \exception verifie si la position est contenue entre 1 et taille de la liste. Throw range_error si faux.
     */
    ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const
    {
        if (position<1 || position>taille())//verifie le range
        {
         throw range_error("La position est hors borne. La liste est peut-être vide");
        }
        Noeud* sentinelle = m_debut;//sentinelle initialisé au debut
        for (size_t i =1; i<position;i++)//
        {
         sentinelle = sentinelle->m_suivant;//passe à la prochaine case

        }
        return sentinelle;
    }

    /**
     * \fn bool ListeDeCases::invariant()
     * \brief Fonction pour vérifier si les invariants sont respectés
    */
    bool ListeDeCases::invariant() const
    {
        return (taille()>-1);
    }
    // Le reste du code qui utilise surtout l'itérateur est fourni.
    // Ajoutez simplement les balises Doxygen.

    /**
     * \fn ListeDeCases:Iterateur ListeDeCases::debut()
     * \brief Produit un iterateur qui commence au debut de la liste
     * \return Iterateur
     */
    ListeDeCases::Iterateur ListeDeCases::debut() const
    {
       return Iterateur(*this);
    }

    /**
     * \fn ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste)
     * \brief Constructeur
     * \param[in] liste ListeDeCases
     */
    ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste) :
       m_liste(liste), m_courant(liste.m_debut)
    {
    }

    /**
     * \fn ListeDeCases::Iterateur::~Iterateur()
     * \brief Destructeur. Assure que le noeud courrant est a zero
     */
    ListeDeCases::Iterateur::~Iterateur()
    {
       m_courant = 0;
    }

    /**
     * \fn const Case& ListeDeCases::Iterateur::caseCourante() const
     * \brief Retour la case courante pointée par l'itérateur
     */
    const Case& ListeDeCases::Iterateur::caseCourante() const
    {
       return m_courant->m_case;//cherche l'information la case dans l'itérateur
    }

    /**
     * \fn bool ListeDeCases::Iterateur::existeCaseSuivante() const
     * \brief Permet de savoir si la case suivante existe
     * \return bool Vrai, si m_courrant et la case suivante sont non null. Sinon, Faux.
     */
    bool ListeDeCases::Iterateur::existeCaseSuivante() const
    {
       return (m_courant != 0 && m_courant->m_suivant != 0);
    }

    /**
     * \fn Iterateur ListeDeCases::Iterateur::operator++()
     * \brief Surcharge de l'opérateur ++ permettant de pointer sur la prochaine case
     * \return ListeDeCases
     * \exception throw out_out_range si la case n'existe pas
     */
    ListeDeCases::Iterateur& ListeDeCases::Iterateur::operator ++()
    {
       if (existeCaseSuivante())//Si une case existe
       {
          m_courant = m_courant->m_suivant;//m_courant pointe maintenant sur la prochaine case
       }
       else
       {
          m_courant = 0;//le pointeur devient null
          throw out_of_range("L'iterateur ne peut pas aller à une case suivante.");
       }
       return *this;
    }

    /**
     * \fn Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const
     * \brief Permet d'avancer le pointeur noeud courant au prochain noeud dont la case a la bonne couleur
     * \param[in] couleur Case::Couleur
     * \param[out] distance int
     * \return Noeud
     */
    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const
    {
       distance = 0;//initialise la distance a 0
       if (m_courant == 0)
       {
          return 0;//retourne null
       }

       ListeDeCases::Noeud* suivant = m_courant->m_suivant;//initialise suivante
       while (noeudMauvaiseCouleur(suivant, couleur))//Tant que c'est la mauvaise couleur avance au suivant
       {
          suivant = suivant->m_suivant;//avance le pointeur a la case suivante
          distance++;//distance est incrémentez
       }
       return suivant;
    }

    /**
     * \fn bool ListeDeCases::Iterateur::noeudMauvaiseCouleur (Noeud *noeud, Couleur couleur ) const
     * \brief Verifie si la case est d'une couleur différente de celle passé en argument
     * \param[in] noeud Noeud
     * \param[in] couleur Case::Couleur
     * \return bool True Si le noeud actuel est non-null et que la couleur de la case est d'une couleur différente. Sinon Faux. 
     */
    bool ListeDeCases::Iterateur::noeudMauvaiseCouleur(ListeDeCases::Noeud *noeud,
          Case::Couleur couleur) const
    {
       return (noeud != 0 && noeud->m_case.couleur != couleur);
    }

    /**
     * \fn void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur)
     * \brief Déplace l'itérateur de sur la prochaine case ayant la même couleur que celle passé
     * \param[in] coouleur Case::Couleur
     * \exception Throw out_of_range si le noeud courant est null
     */
    void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur)
    {
       int distance = 0;
       m_courant = noeudSuivant(couleur, distance);//le noeud courant devient le noeud suivant avec la même couleur
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case suivante de couleur " << couleur << ".";
          throw out_of_range(message.str());
       }
    }

    /**
     * \fn bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const
     * \brief Verifie si une case suivante a la couleur desirée
     * \param[in] couleur Case::Couleur
     * \return bool True si une case suivante a la bonne couleur. Sinon faux.
     */
    bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudSuivant(couleur, distance) != 0;
    }

    /**
     * \fn Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const
     * \brief Verifie si un noeud precedent a la meme couleur que celle passée en référence et le retourne si c'est le cas
     * \param[in] couleur Case::Couleur
     * \param[out] distance int
     * \return Noeud*
     */
    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const
    {
       distance = 0;
       if (m_courant == 0)
       {
          return 0;//return un null
       }

       ListeDeCases::Noeud* precedent = m_courant->m_precedent;//initialise un noued et lui est attribué le noeud précédent du noeud courant
       while (noeudMauvaiseCouleur(precedent, couleur))//tant que c'est une mauvaise couleur
       {
          precedent = precedent->m_precedent;//recule le noeud
          distance++;//incremente distance
       }
       return precedent;
    }

    /**
     * \fn void ListeDeCases::Iterateur::casePrecedent(Case::Couleur couleur)
     * \brief Déplace l'itérateur sur la plus proche case ayant une couleur précise
     * \param[in] couleur Case::Couleur
     * \exception Throw out_of_range si le pinteur est null 
     */
    void ListeDeCases::Iterateur::casePrecedente(Case::Couleur couleur)
    {
       int distance;
       m_courant = noeudPrecedent(couleur, distance); // m_courant devient noeudPrecedent
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case precedente de couleur " << couleur
                << ".";
          throw out_of_range(message.str());
       }
    }
    /**
     * \fn bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const
     * \brief Verifie si une case précédente a la couleur recherché
     * \param[in] couleur Case::Couleur
     * \return bool True si une case de même couleur est trouvé.Sinon, faux.
     */
    bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudPrecedent(couleur, distance) != 0;
    }

    /**
     * \fn int ListeDeCases::Iterateur::positionCourante() const
     * \brief Permet de connaître la position courante dans l'index de la liste
     * \return int
     * \exception Throw range_error si la liste est vide
     */
    int ListeDeCases::Iterateur::positionCourante() const
    {
       Noeud *courant = m_liste.m_debut;//initialise un pointeur au debut
       if (courant == 0)//si la liste est vide
          throw range_error("positionCourante: La liste est vide");

       int i = 1;//initialise i à 1
       while (courant != m_courant)//tant que courant n'est pas la position courante
       {
          courant = courant->m_suivant;//courant avance de 1
          i++;//i incrémente
       }
       return i;//nombre de tour nécessaire pour atteindre la position
    }

    /**
     * \fn bool ListeDeCases::Iterateur::estDerniereCase() const
     * \brief Permet de savoir si l'itérateur est sur la dernière case
     * \return bool True si la case courante est la même que celle de fin et n'est pas null. Sinon Faux.
     */
    bool ListeDeCases::Iterateur::estADerniereCase() const
    {
       return m_courant == m_liste.m_fin && m_courant != 0;
    }

    //Ne touchez surtout pas à cette fonction.
    /**
     * \fn ostream& operator<<(std::ostream& os, const ListeDeCases & liste)
     * \brief Fonction pour afficher la liste de case dans un flux de sortie
     * \param[in] os Ostream
     * \param[in] liste ListeDeCases
     * \return ostream
     */
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
