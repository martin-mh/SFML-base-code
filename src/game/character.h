#ifndef CHARACTER_H
#define CHARACTER_H

#include "engine/entity.h"
#include "resourceidentifiers.h"
#include "engine/command.h"
#include "engine/commandqueue.h"

#include <SFML/Graphics.hpp>

#include <string>


class Character : public Entity
{
public:
    enum Type
    {
        RealPlayer,
        TypeCount
    };

public:
    Character(Type type, const TextureHolder& textures, const FontHolder& fonts);

    virtual unsigned int getCategory() const;
    virtual sf::FloatRect getBoundingRect();
    virtual bool isMarkedForRemoval() const;

    float getMaxSpeed() const;

    bool isMoveAccepted(sf::Vector2f velocity, sf::Time dt);

private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt, CommandQueue& commands);

private:
    Type mType;
    sf::CircleShape mSprite;
    bool mIsMarkedForRemoval;
};

#endif // CHARACTER_H
