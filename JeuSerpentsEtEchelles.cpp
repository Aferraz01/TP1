/////////////////////////////////////////////////////////////////////////////
//Fichier JeuSerpentsEtEchelles.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file JeuSerpentsEtEchelles.cpp
 * \brief Ce fichier contient une implémentation de la classe JeuSerpentsEtEchelles
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2024
 */

#include "JeuSerpentsEtEchelles.h"
#include <cassert>
#include "Case.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

namespace tp1
{

    /**
     * \fn JeuSerpentsEtEchelles::JeuSerpentsEtEchelles()
     * \brief Constructeur par défaut de JeuSerpentsEtEchelles
     */
    JeuSerpentsEtEchelles::JeuSerpentsEtEchelles() : m_cases(), m_choix(), m_joueurs()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    /**
     * \fn Resultat JeuSerpentsEtEchelles::jouer(unsigned int maximumDeTours)
     * \brief Fonction principal de gestion du jeu
     * \param[in] maximumDeTours unsigned int
     * \pre Vérifie que la file m_joueur n'est pas vide
     * \pre Vérifie que la liste m_cases n'est pas vide
     * \pre Vérifie que la liste m_choix n'est pas vide
     */
    Resultat JeuSerpentsEtEchelles::jouer(unsigned int maximumDeTours)
    {
      assert(m_joueurs.taille()!=0);
      assert(!m_cases.estVide());
      assert(!m_choix.estVide());
      size_t nbTour = 0;//compteur de tour
      size_t cpt_ListeChoix = 0;//compteur pour la liste de choix
      for (size_t i = 0; i<maximumDeTours-1; i++)
      {
         nbTour++;
         for (size_t j=1; j<=m_joueurs.taille();j++)//part à 1 car la liste de joueur commence à 1
         {
            Joueur _joueur(m_joueurs.defiler());//retire le joueur au début de la File et transfère sa valeur
            Case::Couleur _couleurInitiale(pigerCouleur(cpt_ListeChoix));
            if(_joueur.position.existeCaseSuivante(_couleurInitiale))//vérifie si une case existe avec la couleur
            {
               _joueur.position.caseSuivante(_couleurInitiale);//Si vrai, le joueur avance vers la case
               Case::Decoration _decoDeplacement(_joueur.position.caseCourante().decoration);//copie la valeur de la case décoration
               switch(_decoDeplacement)
               {
                  case Case::Serpent://Si c'est un serpent
                  {
                     Case::Couleur _couleurSerpent(pigerCouleur(cpt_ListeChoix));//pige nouvelle couleur
                     if(_joueur.position.existeCasePrecedente(_couleurSerpent))//vérifie si une case précédente a la bonne couleur
                     {
                        _joueur.position.casePrecedente(_couleurSerpent);//Recule le joueur
                     }
                     break;//sortir du switch
                  }
                  case Case::Echelle://Si la décoration est une échelle
                  {
                     Case::Couleur _couleurEchelle(pigerCouleur(cpt_ListeChoix));//pige couleur
                     if(_joueur.position.existeCaseSuivante(_couleurEchelle))//vérifie si la case existe
                     {
                        _joueur.position.caseSuivante(_couleurEchelle); //Si oui, avance le joueur
                     }
                     break;
                  }
                  default:
                  {}
               }
            }
            m_joueurs.enfiler(_joueur);//Le joueur retourne à la fin de la liste
            if(_joueur.position.estADerniereCase())//Si la dernière case le joueur gagne
            {
               return Resultat(nbTour, _joueur.nom);
            }
         }
      }

       return Resultat(maximumDeTours);
    }

    //Les quatre méthodes suivantes sont utilisées par le générateur jeu.
    //Normalement, vous ne devriez pas avoir besoin de les appeler.



    //Ne pas modifier cette méthode.
    //Methode utiliser par le generateur de jeu
    /**
     * \fn void JeuSerpentsEtEchelles::effacer()
     * \brief Réinitialise le jeu: efface la liste de case, et les files choix et joueurs
     */
    void JeuSerpentsEtEchelles::effacer()
    {
       while ( m_cases.taille() > 0 )
          m_cases.enleverCase(1);
       while ( m_choix.taille() > 0 )
          m_choix.enleverPos(1);
       while ( m_joueurs.taille() > 0 )
          m_joueurs.defiler();
    }

    //Ne pas modifier cette méthode.
    //Méthode utiliser par le générateur de jeu
    /**
     * \fn void JeuSerpentsEtEchelles::ajouterCase(Case &_case)
     * \brief Ajoute une case à la fin de la liste de case
     * \param[in] _Case Case
     */
    void JeuSerpentsEtEchelles::ajouterCase( Case &_case )
    {
       m_cases.ajouterCaseALaFin( _case );
    }

    //Ne pas modifier cette méthode.
    //Méthode utiliser par le générateur de jeu
    /**
     * \fn void JeuSerpentsEtEchelles::ajouterChoix ( Case::Couleur couleur )
     * \brief Ajoute un choix à la fin de la file de choix
     * \param[in] couleur Case::Couleur
     */
    void JeuSerpentsEtEchelles::ajouterChoix( Case::Couleur couleur )
    {
       m_choix.ajouterFin( couleur );
    }

    //Ne pas modifier cette méthode.
    //Méthode utiliser par le générateur de jeu
    /**
     * \fn void JeuSerpentEtEchelles::ajouterJoueur(Joeur joueur)
     * \brief Ajoute un joueur à la file de joueur
     * \param[in] joueur Joueur
     */
    void JeuSerpentsEtEchelles::ajouterJoueur( Joueur joueur )
    {
       m_joueurs.enfiler( joueur );
    }

    //Ne pas modifier cette méthode.
    /**
     * \fn Iterateur JeuSerpentsEtEchelles::premiereCase()
     * \brief Retourne un iterateur sur la premiere case
     */
    ListeDeCases::Iterateur JeuSerpentsEtEchelles::premiereCase()
    {
       return m_cases.debut();
    }


    //Ne pas modifier cette fonction.
    /**
     * \fn ostream& operator<<(ostream& os, const Joueur & joueur)
     * \brief Surcharge de l'opérateur pour afficher la case dans un flux de sortie
     * \param[in] os Ostream
     * \param[in] joueur Joueur
     */
    ostream& operator<<(ostream& os, const Joueur & joueur)
    {
       os << joueur.nom << " : " << joueur.position.positionCourante();
       return os;
    }

    //Ne pas modifier cette méthode.
    /**
     * \fn void JeuSerpentsEtEchelles::afficherResultats(Resultat gagnant)
     * \brief Affiche le résultat du jeu
     * \param[in] gagnant Resultat
     */
    void JeuSerpentsEtEchelles::afficheResultats(Resultat gagnant)
    {

       if (gagnant.nom != "")
          cout << "Gagnant : " << gagnant.nom << endl;
       else
          cout << "Aucun gagnant" << endl;
       cout << "Nombre de tours realises : " << gagnant.nombreDeTours << endl;
       cout << "Position des joueurs : " << endl;
       cout << m_joueurs << endl;

       cout << "Plateau de jeu:" << endl;
       cout << m_cases << endl;

       cout << "Liste de choix:" << endl;
       cout << m_choix << endl;
    }
    /**
     * \fn Couleur JeuSerpentsEtEchelles::pigerCouleur(size_t& cpt_ListeChoix
     * \brief Fonction qui pige une couleur dans la liste m_choix
     * \param[out] cpt_ListeChoix size_t integer strictement positif passé en référence non constante
     * \return Couleur couleur de la case sélectionnée
     * \pre Lance un assert si m_choix est vide
     */
    Case::Couleur JeuSerpentsEtEchelles::pigerCouleur(size_t& cpt_ListeChoix)
    {
      assert(!m_choix.estVide());
      cpt_ListeChoix++;//incrémente cpt_ListeChoix. La variable est passé par référence. Elle sera incrémentée à la source.
      Case::Couleur myCor=m_choix.element(cpt_ListeChoix);//l'élément sélectionné par la valeur de cpt_ListeChoix
      if(cpt_ListeChoix==m_choix.taille())//Si le compteur a la même valeur que la taille de la liste, on revient à zéro
      {
         cpt_ListeChoix=0;
      }
      return myCor;
    }

}
