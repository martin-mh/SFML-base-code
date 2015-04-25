#include "character.h"

#include "engine/utility.h"
#include "datatables.h"
#include "engine/commandqueue.h"
#include "engine/resourceholder.h"

#include <cmath>

namespace
{
    const std::vector<CharacterData> Table = initializeCharacterData();
}

Character::Character(Type type, const TextureHolder& textures, const FontHolder& fonts) :
    Entity(Table[type].hitpoints),
    mType(type),
    mSprite(30, 30),
    mIsMarkedForRemoval(false)
{
}

unsigned int Character::getCategory() const
{
    return Category::PlayerCharacter;
}

sf::FloatRect Character::getBoundingRect()
{
    return getWorldTransform().transformRect(mSprite.getLocalBounds());
}

bool Character::isMarkedForRemoval() const
{
    return mIsMarkedForRemoval;
}

float Character::getMaxSpeed() const
{
    return Table[mType].speed;
}

bool Character::isMoveAccepted(sf::Vector2f velocity, sf::Time dt)
{
    // In the case you need to deny some moves

    return true;
}

void Character::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Character::updateCurrent(sf::Time dt, CommandQueue &commands)
{
    Entity::updateCurrent(dt, commands);
}
