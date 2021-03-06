/*
    sFMLnake: A simple Snake clone made with SFML 2.
    Copyright (C) 2013  Alberto Garc�a Gonz�lez

    This file is part of sFMLnake.

    sFMLnake is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sFMLnake is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with sFMLnake.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "menuScreen.h"

#include "globals.h"

MenuScreen::MenuScreen(sf::RenderWindow& window)
    : Screen(window), option(0)
{
    font.loadFromFile("fonts/alphabeta.ttf");
    name.setFont(font);
    gameStartTxt.setFont(font);
    scoresTxt.setFont(font);
    exitTxt.setFont(font);

    name.setString("sFMLnake");
    name.setColor(sf::Color::Black);
    name.scale(3.f, 3.f);
    name.setPosition(120.f, 40.f);

    gameStartTxt.setString("Play");
    gameStartTxt.setPosition(WIDTH / 2 - gameStartTxt.getLocalBounds().width / 2, 220.f);

    scoresTxt.setString("High scores");
    scoresTxt.setPosition(WIDTH / 2 - scoresTxt.getLocalBounds().width / 2, 260.f);

    exitTxt.setString("Exit");
    exitTxt.setPosition(WIDTH / 2 - exitTxt.getLocalBounds().width / 2, 300.f);

    selectBuff.loadFromFile("sounds/selectSnd.ogg");
    selectSnd.setBuffer(selectBuff);
    confirmBuff.loadFromFile("sounds/confirmSnd.ogg");
    confirmSnd.setBuffer(confirmBuff);
}

int MenuScreen::run() {
    bool optSelected = false, cursorMoved = false;
    while(!optSelected) {
        // input
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                return 2;

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && !cursorMoved) {
                option = (option + 2) % 3;
                selectSnd.play();
                cursorMoved = true;
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && !cursorMoved) {
                option = (option + 1) % 3;
                selectSnd.play();
                cursorMoved = true;
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                optSelected = true;
                confirmSnd.play();
            }
            if(event.type == sf::Event::KeyReleased &&
              (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down))
                cursorMoved = false;
        }

        // logic
        gameStartTxt.setColor(sf::Color::Black);
        scoresTxt.setColor(sf::Color::Black);
        exitTxt.setColor(sf::Color::Black);

        if(option == 0)
            gameStartTxt.setColor(sf::Color::White);
        else if(option == 1)
            scoresTxt.setColor(sf::Color::White);
        else
            exitTxt.setColor(sf::Color::White);

        // output
        window.clear(sf::Color(0x9f, 0x6d, 0x47));

        window.draw(name);
        window.draw(gameStartTxt);
        window.draw(scoresTxt);
        window.draw(exitTxt);

        window.display();
    }

    return option;
}
