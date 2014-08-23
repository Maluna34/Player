/*************************************
 * @file    Interface.hpp
 * @date    02/08/14
 * @author  Manuel
 *
 * Déclarations de la classe Interface
 * contenant la gestion de l'interface
 * de l'application.
 *************************************
*/

#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

/** SFML Graphics includes **/
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Spectrum.hpp"
#include "CircleButton.hpp"
#include "ProgressBar.hpp"
#include "ProgressBackground.hpp"


class Interface
{
  private:

    sf::Font m_Font;
    sf::Text m_SongTitle;

    Spectrum m_Spectrum;

    std::vector<sf::Texture> m_Textures;
    std::vector<CircleButton> m_Buttons;

    ProgressBackground *mp_ProgressBackground;
    ProgressBar *mp_ProgressBar;

    std::vector<Clickable*> mp_ClickableObjects;
    std::vector<Movable*>   mp_MovableObjects;

  public:

    Interface();
    virtual ~Interface();

    virtual Clickable& button(Clickable_t index) const;

    virtual Movable& button(Movable_t index) const;

    /**
     * Charge les polices et créé
     * l'ensemble des textes.
    */
    virtual void loadTexts();

    /**
     * Charge les textures et créé
     * l'ensemble des sprites/shapes.
    */
    virtual void loadImages();

    /**
     * Dessine l'ensemble des éléments de l'application
     * (sprites, shapes, textes et vertices).
     * @param target Surface sur laquelle afficher le contenu
     * @param stopped Etat stop du player
    */
    virtual void drawContent(sf::RenderTarget& target, bool stopped);

    /**
     * Change le titre du son courant.
     * @param title Titre à afficher
    */
    virtual void setTitle(const std::string& title);

    /**
     * Modifie la texture du bouton
     * play/pause.
     * @param play Etat du player
    */
    virtual void setPlayButtonTexture(bool play);

    /**
     * Modifie la taille de la barre de
     * progression.
     * @param x Nouvelle taille
    */
    virtual void setProgressBar(int x);

    /**
     * Actualise le spectre du son.
     * @param id Identifiant du canal
    */
    virtual void updateSpectrum(SoundID_t id);
};

#endif  // __INTERFACE_HPP__
