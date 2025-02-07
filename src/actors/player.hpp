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
    bool MoveTo(Vector3 target, float speed);
    // Fires a Ray from the mouse position and returns the collision point in the (x,0,z) axis.
    Vector3 GetMouseTargetPosition();
    void SetTargetPosition(Vector3);
};

#endif
