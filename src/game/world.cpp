#include "world.h"
#include "engine/textnode.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <algorithm>
#include <cmath>
#include <limits>

World::World(sf::RenderWindow& window, FontHolder& fonts) :
    mWindow(window),
    mWorldView(window.getDefaultView()),
    mTextures(),
    mFonts(fonts),
    mSceneGraph(),
    mSceneLayers()
{
    loadTextures();
    buildScene();
}

void World::update(sf::Time dt)
{
    handleCollisions();
    
    mPlayer.handleRealtimeInput(mCommandQueue);

    mPlayerCharacter->setVelocity(0.f, 0.f);

    while (!mCommandQueue.isEmpty())
            mSceneGraph.onCommand(mCommandQueue.pop(), dt);

    // Remove all destroyed entities, create new ones
    mSceneGraph.removeWrecks();

    // Regular update step, adapt position (correct if outside view)
    mSceneGraph.update(dt, mCommandQueue);
}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::handleEvent(const sf::Event &event)
{
    mPlayer.handleEvent(event, mCommandQueue);
}

CommandQueue& World::getCommandQueue()
{
    return mCommandQueue;
}

void World::loadTextures()
{

}

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
    unsigned int category1 = colliders.first->getCategory();
    unsigned int category2 = colliders.second->getCategory();

    // Make sure first pair entry has category type261 and second has type2
    if (type1 & category1 && type2 & category2)
    {
        return true;
    }
    else if (type1 & category2 && type2 & category1)
    {
        std::swap(colliders.first, colliders.second);
        return true;
    }
    else
    {
        return false;
    }
}

void World::handleCollisions()
{

}

void World::buildScene()
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        Category::Type category = (i == Air) ? Category::SceneAirLayer : Category::None;

        SceneNode::Ptr layer(new SceneNode(category));
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Add the player
    std::unique_ptr<Character> player(new Character(Character::RealPlayer, mTextures, mFonts));
    mPlayerCharacter = player.get();
    mPlayerCharacter->setPosition(64, 64);
    mSceneLayers[Air]->attachChild(std::move(player));
}

sf::FloatRect World::getViewBounds() const
{
    return sf::FloatRect(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
}
