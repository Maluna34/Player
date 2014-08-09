/*************************************
 * @file    Fmod.hpp
 * @date    29/07/14
 * @author  Manuel
 *
 * Déclarations de la classe Fmod
 * contenant l'ensemble de la gestion
 * des fonctions fmodex.
 *************************************
*/

#ifndef __FMOD_HPP__
#define __FMOD_HPP__

#include <fmodex/fmod.h>
#include <fmodex/fmod_errors.h>
#include <vector>
#include <string>

#include "constants.hpp"

typedef unsigned int  SoundID_t;

class Fmod
{
  private:

    FMOD_SYSTEM  *mp_System;

    std::vector<FMOD_CHANNEL*>  mp_Channels;

    FMOD_SOUND *mp_Sound;


    /* Instance du singleton */
    static Fmod *mp_Instance;


    /**
     * Libère la mémoire du son chargé.
    */
    virtual void releaseSound();

  public:

    Fmod(int maxChannels = MAX_CHANNELS_NB);
    virtual ~Fmod();

    /**
     * Créé le singleton s'il n'existe pas
     * et retourne l'instance correspondante.
     * @return instance du singleton
    */
    static Fmod* getInstance();

    /**
     * Détruit le singleton alloué dynamiquement.
    */
    static void deleteInstance();

    /**
     * Charge le fichier son passé en paramètre.
     * @param soundFile Fichier à ouvrir
     * @return identifiant du canal associé
    */
    virtual SoundID_t openSound(const std::string& soundFile);

    /**
     * Joue le son chargé.
    */
    virtual void playSound();

    /**
     * Arrête le son joué sur le canal id.
     * @param id Identifiant du canal à stopper
    */
    virtual void stopSound(SoundID_t id) const;

    /**
     * Met ou retire la pause du canal id.
     * @param id Identifiant du canal à modifier.
     * @param paused Etat pause à positionner.
    */
    virtual void pauseSound(SoundID_t id, bool paused) const;

    /**
     * @return durée de la musique
    */
    virtual unsigned int getSoundLength() const;

    /**
     * @return position courante de la musique jouée.
    */
    virtual unsigned int getSoundPosition() const;

    /**
     * @param id Identifiant du canal à tester
     * @return true si le canal id est en train de jouer.
    */
    virtual bool isPlaying(SoundID_t id) const;

    /**
     * Récupère le spectre du son joué dans le canal.
     * @param id Identifiant du canal à tester
     * @param values Tableau dans lequel sont stockées
     *               les valeurs.
     * @return Tableau dans lequel sont stockées les valeurs.
    */
    virtual float* getChannelSpectrum(SoundID_t id, float *values) const;

};

#endif  // __FMOD_HPP__
