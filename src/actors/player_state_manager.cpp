#include "player_state_manager.hpp"

PlayerStateManager::PlayerStateManager(Player* p)
{
    mStateIdle = new PlayerStateIdle(this, p);
    mStateMoving = new PlayerStateMoving(this, p);
    mState = mStateIdle;
}

PlayerStateManager::~PlayerStateManager()
{
    delete mStateIdle;
    delete mStateMoving;
}

void PlayerStateManager::Idle()
{
    ChangeState(mStateIdle);
}

void PlayerStateManager::Moving()
{
    ChangeState(mStateMoving);
}

void PlayerStateManager::Update(float dt)
{
    mState->Update(dt);
}

void PlayerStateManager::ChangeState(PlayerState* v)
{
    auto next = v;
    auto prev = mState;

    // if (prev == next) {
    //     return;
    // }

    prev->OnExit();
    next->OnEnter();

    mState = next;
}
