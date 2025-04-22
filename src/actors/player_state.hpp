#ifndef PLAYER_STATE_HPP
#define PLAYER_STATE_HPP

#include <raylib.h>

class Player;
class PlayerStateManager;

#include "player.hpp"
#include "player_state_manager.hpp"

class PlayerState {
protected:
    PlayerStateManager* mStateManager;
    Player* mActor;

public:
    PlayerState(PlayerStateManager* sm, Player* p)
        : mStateManager(sm)
        , mActor(p)
    {
    }
    virtual void Update(float dt) = 0;
    virtual void Render() { }
    virtual void OnEnter() { }
    virtual void OnExit() { }
};

class PlayerStateIdle : public PlayerState {
public:
    PlayerStateIdle(PlayerStateManager* sm, Player* p)
        : PlayerState(sm, p)
    {
    }

    void Update(float dt) override;
};

class PlayerStateMoving : public PlayerState {
    Vector3 mTargetPosition;

public:
    PlayerStateMoving(PlayerStateManager* sm, Player* p)
        : PlayerState(sm, p)
    {
    }

    void Update(float dt) override;
    void OnEnter() override;
};

#endif
