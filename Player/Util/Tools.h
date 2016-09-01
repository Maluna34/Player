/*************************************
 * @file    Tools.h
 * @date    11/06/15
 * @author  Manuel
 *
 * Déclarations de la classe Tools contenant
 * des fonctionnalités annexes.
 *************************************
*/

#ifndef __TOOLS_H_
#define __TOOLS_H__

#include <QString>
#include <QPixmap>


namespace util {


class Tools
{
    public:

        /**
         * @brief Convertit le temps passé en ms dans le format mm:ss ou hh:mm:ss.
         * @param ms Temps à afficher en ms
         */
        static QString msToString(int ms);

        /**
         * @brief Charge l'image du chemin passé en paramètre et vérifie le chargement.
         * @param fileName Chemin de l'image à charger
         * @return Image chargée
         */
        static QPixmap loadImage(const QString& fileName);

        /**
         * @brief Retourne le nom du type mime associé au fichier passé en paramètre.
         * @param filename Chemin du fichier
         * @return Nom du type mime
         */
        static QString getMimeType(const QString& filename);
};


} // util

#endif  // __TOOLS_H__
