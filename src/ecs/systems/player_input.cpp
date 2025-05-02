#include "ecs/components/player_controller.h"
#include "ecs/components/velocity.h"
#include "core/input.h"
#include "core/vec2.h"

void system_player_input() {
    for (Entity e = 1; e < 10000; ++e) {
        if (player_controller_has(e) && velocity_has(e)) {
            Vec2 dir(0, 0);
            if (input_is_action_pressed("left")) dir.x -= 1.0f;
            if (input_is_action_pressed("right")) dir.x += 1.0f;
            if (input_is_action_pressed("up")) dir.y += 1.0f;
            if (input_is_action_pressed("down")) dir.y -= 1.0f;
            velocity_get(e)->velocity = dir * 1.0f;
        }
    }
}
