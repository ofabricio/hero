#include "player_state.hpp"

void PlayerStateIdle::Update(float dt)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        mStateManager->Moving();
        return;
    }
    if (IsKeyPressed(KEY_ONE)) {
        return;
    }
    if (IsKeyPressed(KEY_TWO)) {
        return;
    }
}

void PlayerStateMoving::OnEnter()
{
    mTargetPosition = mActor->GetMouseTargetPosition();
}

void PlayerStateMoving::Update(float dt)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        mStateManager->Moving();
        return;
    }
    if (IsKeyPressed(KEY_ONE)) {
        return;
    }
    if (IsKeyPressed(KEY_TWO)) {
        return;
    }

    mActor->MoveTo(mTargetPosition);
}
