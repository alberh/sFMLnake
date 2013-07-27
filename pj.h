#ifndef PJ_H
#define PJ_H

#include <SFML/Graphics.hpp>
#include <deque>

class Pj {
    class BodyPiece;
public:
    typedef std::deque<BodyPiece> Body;
    enum Direction {UP, RIGHT, LEFT, DOWN};

    Pj(int x, int y);
    void update();
    const Body& getBody() const;
    void draw(sf::RenderWindow& window) const;
    void setDirection(const Direction& dir);
    void grow();
private:
    class BodyPiece {
    public:
        BodyPiece(int x, int y);
        const sf::Vector2i& coords() const;
        sf::Vector2i& coords();
    private:
        sf::Vector2i _coords;
    };

    Direction direction;
    Body body;

    void moveUp();
    void moveRight();
    void moveLeft();
    void moveDown();
};

inline Pj::BodyPiece::BodyPiece(int x, int y) : _coords(x, y) {}
inline const sf::Vector2i& Pj::BodyPiece::coords() const { return _coords; }
inline       sf::Vector2i& Pj::BodyPiece::coords()       { return _coords; }

inline const Pj::Body& Pj::getBody() const { return body; }
inline void  Pj::setDirection(const Direction& dir) {
    direction = dir;
}

#endif
