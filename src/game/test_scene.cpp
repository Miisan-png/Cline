#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "core/scene.h"
#include "core/time.h"
#include "core/vec2.h"
#include "core/draw.h"
#include "core/input.h"
#include "ecs/entity.h"
#include "ecs/components/transform.h"
#include "ecs/components/velocity.h"
#include "ecs/components/player_controller.h"
#include "ecs/systems/player_input.h"
#include "ecs/systems/movement.h"
#include "ecs/systems/world_bounds.h"
#include "ecs/systems/draw_transforms.h"

Entity test;

struct TestScene : public Scene {
    void ready() override {
        test = entity_create();
        transform_add(test);
        transform_get(test)->position = Vec2(0.0f, 0.0f);

        velocity_add(test);
        player_controller_add(test);

        input_bind("left", GLFW_KEY_A);
        input_bind("right", GLFW_KEY_D);
        input_bind("up", GLFW_KEY_W);
        input_bind("down", GLFW_KEY_S);
    }

    void process() override {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        system_player_input();
        system_movement(time_get_delta());
        system_world_bounds();
        system_draw_transforms();
    }

    void exit() override {
        transform_remove(test);
        velocity_remove(test);
        player_controller_remove(test);
        entity_destroy(test);
    }
};

Scene* create_test_scene() {
    return new TestScene();
}
