#ifndef PJ_H
#define PJ_H

#include <SFML/Graphics.hpp>
#include <deque>
#include "globals.h"

class Food;
class Score;

class Pj {
public:
    typedef sf::Sprite BodyPiece;
    typedef std::deque<BodyPiece*> Body;
    enum Direction {UP, RIGHT, LEFT, DOWN};

    Pj(float x = BPIECE, float y = BPIECE);

    void readInput(const sf::Event& event);
    bool update(Food& food, Score& score);
    const Body& getBody() const;
    void draw(sf::RenderWindow& window) const;
    void setDirection(const Direction& dir);
    void grow();
    bool checkCollisions(const sf::Vector2f& v) const;

    ~Pj();
private:
    Direction direction;
    Body body;
    sf::Texture texture;

    bool moveUp();
    bool moveRight();
    bool moveLeft();
    bool moveDown();
};

inline const Pj::Body& Pj::getBody() const { return body; }
inline void  Pj::setDirection(const Direction& dir) {
    direction = dir;
}

#endif
