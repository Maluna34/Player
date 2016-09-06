/*************************************
 * @file    PlayerWindow.h
 * @date    26/04/15
 * @author  Manuel
 *
 * Déclarations de la classe PlayerWindow
 * correspondant à la fenêtre principale.
 *************************************
*/

#ifndef __PLAYERWINDOW_H__
#define __PLAYERWINDOW_H__

#include <QMainWindow>
#include "../Audio/Player.h"
#include "Spectrum.h"
#include "PlayerLabel.h"
#include "PlayerButton.h"
#include "ProgressBackground.h"
#include "NetworkLoadBar.h"
#include "ProgressBar.h"
#include "VolumeViewer.h"
#include "SongList.h"
#include "ShadowWidget.h"

#include <QTimerEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QVector>
#include <QTimer>
#include "./Network/PlayerSocket.h"
#include "ConnectionBox.h"


namespace gui {


class PlayerWindow : public QMainWindow
{
    Q_OBJECT

    private:

        int m_TimerId;

        QString m_PreviewPath;
        QTimer m_PreviewTimer;

        audio::Player m_Player;

        QWidget *mp_TopPart;
        QWidget *mp_BottomPart;

        PlayerLabel *mp_SongTitle;
        PlayerLabel *mp_SongArtist;
        QLabel *mp_SongPicture;

        Spectrum *mp_Spectrum;
        SongList *mp_SongList;

        PlayerLabel *mp_SongPos;
        PlayerLabel *mp_SongLength;

        ProgressBackground *mp_ProgressBackground;
        NetworkLoadBar *mp_NetworkLoadBar;
        ProgressBar *mp_ProgressBar;

        VolumeViewer *mp_SoundVolume;

        ShadowWidget *mp_ShadowWidget;
        QProgressBar *mp_PreviewBar;

        enum class ButtonId { PLAY, PAUSE, STOP, PREV, NEXT, VOLUME_MORE, VOLUME_LESS };

        QVector<PlayerButton*> mp_Buttons;

        std::unique_ptr<network::PlayerSocket> mp_Socket;

        ConnectionBox *mp_ConnectionBox;


        /**
         * @brief Créé le widget de previsualisation.
         */
        virtual void createPreviewWidget();

        /**
         * @brief Récupère le boutton associé à la valeur de l'énumération passée en paramètre.
         * @param id Identifiant du bouton
         * @return Bouton associé à l'identifiant
         */
        PlayerButton* getButton(ButtonId id) const;

        /**
         * @brief Modifie le volume de l'application avec celui passé en paramètre.
         * @param volume Nouveau volume à appliquer
         */
        virtual void setVolume(int volume);

    private slots:

        /**
         * @brief Actualise l'interface graphique (titre, durée...) à partir du son courant.
         */
        virtual void updateCurrentSong();

        /**
         * @brief Met à jour la liste des musiques du répertoire.
         */
        virtual void refreshSongsList();

        /**
         * @brief Change l'état du player et modifie l'affichage.
         * @param state Nouvel état du player
         */
        virtual void setState(PlayerState state);

        /**
         * @brief Applique l'état play.
         */
        virtual void play();

        /**
         * @brief Applique l'état pause.
         */
        virtual void pause();

        /**
         * @brief Applique l'état stop.
         */
        virtual void stop();

        /**
         * @brief Lance la musique précédente si elle existe.
         */
        virtual void previousSong();

        /**
         * @brief Lance la musique suivante si elle existe.
         */
        virtual void nextSong();

        /**
         * @brief Augmente le volume de l'application.
         */
        virtual void increaseVolume();

        /**
         * @brief Diminue le volume de l'application.
         */
        virtual void decreaseVolume();

        /**
         * @brief Modifie la position du son et met à jour la barre de progression.
         * @param value Nouvelle position de la barre
         */
        virtual void setSongPosition(int value);

        /**
         * @brief Applique ou retire l'état mute à l'application.
         */
        virtual void setMute();

        /**
         * @brief Ouvre le dossier des musiques lues par l'application.
         */
        virtual void openSongsDir() const;

        /**
         * @brief Propose à l'utilisateur d'ajouter une nouvelle musique
         *        et l'enregistre si un fichier a été sélectionné.
         */
        virtual void importSong();

        /**
         * @brief Ouvre la fenêtre contenant les informations sur l'application.
         */
        virtual void openInformation();

        /**
         * @brief Met l'application en écoute de clients.
         */
        virtual void listen();

        /**
         * @brief Se connecte à l'hôte défini.
         * @param host Hôte auquel on essaie de se connecter
         */
        virtual void connectToHost(const QString& host);

        /**
         * @brief Commence la connexion entre les deux hôtes (envoi des musiques).
         */
        virtual void startConnection();

        /**
         * @brief Termine la connexion.
         */
        virtual void closeConnection();

        /**
         * @brief Démarre la preview de la chanson enregistrée.
         */
        virtual void startPreview();

        /**
         * @brief Arrête la preview.
         */
        virtual void stopPreview();

    protected:

        virtual void timerEvent(QTimerEvent *event) override;

        virtual void showEvent(QShowEvent *event) override;

        virtual void hideEvent(QHideEvent *event) override;

        virtual void resizeEvent(QResizeEvent *event) override;

        virtual void paintEvent(QPaintEvent *event) override;

        virtual void dragEnterEvent(QDragEnterEvent *event) override;

        virtual void dragLeaveEvent(QDragLeaveEvent *event) override;

        virtual void dropEvent(QDropEvent *event) override;

    public:

        PlayerWindow(QWidget *parent = nullptr);
        virtual ~PlayerWindow();
};


} // gui

#endif // __PLAYERWINDOW_H__
