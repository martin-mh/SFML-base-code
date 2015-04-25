#ifndef DATATABLES_H
#define DATATABLES_H

#include "resourceidentifiers.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>
#include <functional>

struct Direction
{
    Direction(float angle, float distance) :
        angle(angle),
        distance(distance)
    {

    }

    float angle;
    float distance;
};


struct CharacterData
{
    int hitpoints;
    float speed;

    /*
     * Textures::ID texture;
     */
};

std::vector<CharacterData> initializeCharacterData();

#endif // DATATABLES_H

