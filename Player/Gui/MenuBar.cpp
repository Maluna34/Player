/*************************************
 * @file    MenuBar.cpp
 * @date    14/09/15
 * @author  Manuel
 *
 * Définitions de la classe MenuBar.
 *************************************
*/

#include "MenuBar.h"
#include "Constants.h"
#include "../Util/Tools.h"


MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    setStyleSheet("background-color: grey;");

    QMenu *fileMenu = addMenu("Fichier");
    QMenu *helpMenu = addMenu("Aide");

    mp_AddingSongAction = fileMenu->addAction(QIcon(Tools::loadImage(Constants::MENU_SUBDIR + "adding.png")), "Ajouter un son");
    mp_OpenAction = fileMenu->addAction(QIcon(Tools::loadImage(Constants::MENU_SUBDIR + "open.png")), "Ouvrir");
    mp_QuitAction = fileMenu->addAction(QIcon(Tools::loadImage(Constants::MENU_SUBDIR + "quit.png")), "Quitter");
    mp_AboutAction = helpMenu->addAction(QIcon(Tools::loadImage(Constants::MENU_SUBDIR + "about.png")), "A propos");

    mp_AddingSongAction->setShortcut(QKeySequence("Ctrl+N"));
    mp_OpenAction->setShortcut(QKeySequence("Ctrl+O"));
    mp_QuitAction->setShortcut(QKeySequence("Ctrl+Q"));
    mp_AboutAction->setShortcut(QKeySequence("Ctrl+A"));
}

// ==============================
// ==============================

MenuBar::~MenuBar()
{

}

// ==============================
// ==============================

QAction* MenuBar::getAddingSongAction() const
{
    return mp_AddingSongAction;
}

// ==============================
// ==============================

QAction* MenuBar::getOpenAction() const
{
    return mp_OpenAction;
}

// ==============================
// ==============================

QAction* MenuBar::getQuitAction() const
{
    return mp_QuitAction;
}

// ==============================
// ==============================1

QAction* MenuBar::getAboutAction() const
{
    return mp_AboutAction;
}
