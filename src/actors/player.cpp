#include "player.hpp"

#include <raymath.h>
#include <rcamera.h>

#include <limits>

Player::Player(Camera& c)
{
    c.target = Vector3(0.0f, 0.0f, 0.0f);
    c.position = Vector3(0.0f, 12.0f, 12.0f);
    c.up = Vector3(0.0f, 1.0f, 0.0f);
    c.fovy = 60.0f;
    c.projection = CAMERA_PERSPECTIVE;
    mCamera = &c;

    mMovementSpeed = 5.0f;
    mPosition = Vector3();
    mTargetPosition = Vector3();

    mStateManager = new PlayerStateManager(this);
}

Player::~Player()
{
    delete mStateManager;
}

void Player::Update(float dt)
{
    UpdateCamera();

    mStateManager->Update(dt);

    UpdatePosition(mTargetPosition, dt * mMovementSpeed);
}

void Player::UpdateCamera()
{
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        auto sensibility = 0.003f;
        auto mouseDelta = GetMouseDelta();
        CameraYaw(mCamera, -mouseDelta.x * sensibility, true);
    }
}

void Player::MoveTo(Vector3 target)
{
    if (Vector3Length(target - mTargetPosition) >= 0.5f) {
        mTargetPosition = target;
    }
}

bool Player::UpdatePosition(Vector3 target, float speed)
{
    auto diff = target - mPosition;
    if (Vector3Length(diff) <= speed) { // Stop condition.
        mPosition += diff;
        mCamera->target += diff;
        mCamera->position += diff;
        return true;
    }
    auto disp = Vector3Normalize(diff) * speed;
    mPosition += disp;
    mCamera->target += disp;
    mCamera->position += disp;
    return false;
}

Vector3 Player::GetMouseTargetPosition()
{
    auto inf = std::numeric_limits<float>::infinity();
    auto ray = GetScreenToWorldRay(GetMousePosition(), *mCamera);
    auto col = GetRayCollisionBox(ray, (BoundingBox) { (Vector3) { -inf, 0, -inf }, (Vector3) { +inf, 0, +inf } });
    return col.point;
}

void Player::Stop()
{
    mTargetPosition = mPosition;
}

void Player::Draw()
{
    DrawCube(mPosition, 1.0f, 1.0f, 1.0f, RED);
    DrawSphere(mTargetPosition, 0.15f, BLUE);
    // if (mState == PlayerState::ATTACK || mState == PlayerState::ATTACK_MOVING) {
    //     DrawSphereWires(mPosition, 1.5f, 4, 8, GREEN);
    // }
}
