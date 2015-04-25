#include "gamestate.h"

GameState::GameState(StateStack& stack, Context context) :
    State(stack, context),
    mWorld(*context.window, *context.fonts),
    mPlayer(*context.player)
{

}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
    mWorld.update(dt);

    // Handle player input ?

    return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
    // Game input handling

    mWorld.handleEvent(event);

    return true;
}
