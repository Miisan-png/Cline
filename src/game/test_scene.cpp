#include <GL/glew.h>
#include "core/scene.h"
#include "core/time.h"
#include "core/vec2.h"
#include "core/draw.h"
#include "ecs/entity.h"
#include "ecs/components/transform.h"
#include "ecs/components/velocity.h"
#include "ecs/systems/movement.h"
#include "ecs/systems/draw_transforms.h"

Entity test;

struct TestScene : public Scene {
    void ready() override {
        test = entity_create();
        transform_add(test);
        transform_get(test)->position = Vec2(-0.5f, 0.0f);

        velocity_add(test);
        velocity_get(test)->velocity = Vec2(0.2f, 0.0f); // move right
    }

    void process() override {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        system_movement(time_get_delta());
        system_draw_transforms();
    }

    void exit() override {
        transform_remove(test);
        velocity_remove(test);
        entity_destroy(test);
    }
};

Scene* create_test_scene() {
    return new TestScene();
}
