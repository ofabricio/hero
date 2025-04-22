#ifndef PLAYER_STATE_MANAGER_HPP
#define PLAYER_STATE_MANAGER_HPP

class PlayerState;
class PlayerStateIdle;
class PlayerStateMoving;

#include "player.hpp"
#include "player_state.hpp"

#include <memory>

class PlayerStateManager {
    PlayerState* mState;
    PlayerStateIdle* mStateIdle;
    PlayerStateMoving* mStateMoving;

public:
    PlayerStateManager(Player* p);
    ~PlayerStateManager();

    void Idle();
    void Moving();
    void Update(float dt);

private:
    void ChangeState(PlayerState* v);
};

#endif
