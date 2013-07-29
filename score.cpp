#include "score.h"
#include <sstream>

Score::Score()
    : points(0u)
{
    font.loadFromFile("font/alphbeta.ttf");
    text.setFont(font);
    text.setColor(sf::Color::Black);
    text.setPosition(10.f, 10.f);
}

const sf::Text& Score::getText() {
    static std::stringstream ss;
    ss.str(""); ss << points;

    text.setString(ss.str());
    return text;
}
