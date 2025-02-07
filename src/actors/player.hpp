#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

enum class PlayerState {
    IDLE,
    MOVE,
    ATTACK,
    ATTACK_MOVING,
};

class Player {
    Camera* mCamera;
    Vector3 mPosition;
    Vector3 mTargetPosition;
    float mMovementSpeed;
    float mCooldown;
    PlayerState mState;

public:
    Player(Camera& c);
    void Update(float dt);
    void Draw();
    void SetState(PlayerState);

private:
    void Stop();
    void UpdateCamera();
    void UpdateStateIdle();
    void UpdateStateAttack(float dt);
    void UpdateStateAttackMoving(float dt);
    // Updates the Actor position so that it moves to the target by the speed.
    // Returns true when the Actor reaches the target.
    bool UpdatePosition(Vector3 target, float speed);
    // Fires a Ray from the mouse position and returns
    // the collision point in the (x, 0, z) axis.
    Vector3 GetMouseTargetPosition();
    // Moves the Actor to the position.
    void MoveTo(Vector3);
};

#endif
