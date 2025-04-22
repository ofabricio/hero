#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

#include "player_state_manager.hpp"

class PlayerStateManager;
class Player {
    Camera* mCamera;
    Vector3 mPosition;
    Vector3 mTargetPosition;
    float mMovementSpeed;
    float mCooldown;
    PlayerStateManager* mStateManager;

public:
    Player(Camera& c);
    ~Player();
    void Update(float dt);
    void Draw();
    // Moves the Actor to the position.
    void MoveTo(Vector3);
    // Fires a Ray from the mouse position and returns
    // the collision point in the (x, 0, z) axis.
    Vector3 GetMouseTargetPosition();

private:
    void Stop();
    void UpdateCamera();
    void UpdateStateIdle();
    void UpdateStateAttack(float dt);
    void UpdateStateAttackMoving(float dt);
    // Updates the Actor position so that it moves to the target by the speed.
    // Returns true when the Actor reaches the target.
    bool UpdatePosition(Vector3 target, float speed);
};

#endif
