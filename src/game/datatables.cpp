#include "datatables.h"

#include "character.h"

std::vector<CharacterData> initializeCharacterData()
{
    std::vector<CharacterData> data(Character::TypeCount);

    data[Character::RealPlayer].hitpoints = 100;
    data[Character::RealPlayer].speed = 5.f;

    return data;
}
