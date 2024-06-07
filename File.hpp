/////////////////////////////////////////////////////////////////////////////
//Fichier File.hpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file File.hpp
 * \brief Ce fichier contient une implémentation générique de la classe File
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2024
 */

#include <stdexcept>

namespace tp1
{

    /**
     * \fn File<T>::File()
     * \brief Constructeur de la file
     */
    template<typename T>
    File<T>::File():liste()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    /**
     * \fn void File<T>::enfiler (const T& element)
     * \brief Ajoute un élément à la fin de la file
     * \param[in] element element a ajouter
     */
    template<typename T>
    void File<T>::enfiler ( const T& element )
    {
        liste.ajouterFin(element);//ajoute element à la fin de la file
    }

    /**
     * \fn T File<T>:: defiler ()throw(logic_error)
     * \return L'élément au début de la file
     */
    template<typename T>
    T File<T>::defiler ()
    {
        if(taille()<=0)
            throw std::logic_error("La liste est vide");
        T valeur = liste.element(1);//copie element de la liste au début
        liste.enleverPos(1);//retire l'élément de la liste au début
        return valeur;//retourne la valeur
    }

    /**
     * \fn unsigned int File<t>::taille() const
     * \brief Permet d'obtenir la taille de la file
     * \return unsigned int
     */
    template<typename T>
    unsigned int File<T>::taille () const
    {
       
       return liste.taille();
    }

    //Ne touchez pas à cette fonction.
    template< typename T >
    std::ostream& operator<<(std::ostream& os, const File<T> & file)
    {
       os << file.liste;
       return os;
    }

}
