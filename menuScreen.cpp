#include "menuScreen.h"

MenuScreen::MenuScreen(sf::RenderWindow& window)
    : window(window), option(0)
{
    font.loadFromFile("font/alphbeta.ttf");
    name.setFont(font); gameStartTxt.setFont(font); scoresTxt.setFont(font); exitTxt.setFont(font);

    selectBuff.loadFromFile("sound/selectSnd.ogg");
    selectSnd.setBuffer(selectBuff);
    confirmBuff.loadFromFile("sound/confirmSnd.ogg");
    confirmSnd.setBuffer(confirmBuff);
    backBuff.loadFromFile("sound/backSnd.ogg");
    backSnd.setBuffer(backBuff);
}

int MenuScreen::run() {
    name.setString("sFMLnake");
    name.setColor(sf::Color::Black);
    name.scale(3.f, 3.f);
    name.setPosition(120.f, 20.f);

    gameStartTxt.setString("Play");
    gameStartTxt.setPosition(290.f, 200.f);

    scoresTxt.setString("High scores");
    scoresTxt.setPosition(235.f, 240.f);

    exitTxt.setString("Exit");
    exitTxt.setPosition(290.f, 280.f);

    bool optSelected = false;
    while(!optSelected) {
        // input
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                option = (option + 2) % 3;
                selectSnd.play();
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                option = (option + 1) % 3;
                selectSnd.play();
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                optSelected = true;
                confirmSnd.play();
            }
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

        // logic
        window.clear(sf::Color::Green);

        window.draw(name);
        window.draw(gameStartTxt);
        window.draw(scoresTxt);
        window.draw(exitTxt);

        window.display();
    }

    return option;
}