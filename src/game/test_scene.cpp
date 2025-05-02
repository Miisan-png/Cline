#include <GL/glew.h>
#include "core/scene.h"
#include "core/time.h"
#include "core/vec2.h"
#include "core/draw.h"
#include "ecs/entity.h"
#include "ecs/components/transform.h"
#include "ecs/systems/draw_transforms.h"

Entity test;

struct TestScene : public Scene {
    void ready() override {
        test = entity_create();
        transform_add(test);
        transform_get(test)->position = Vec2(-0.2f, -0.2f);
    }

    void process() override {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        system_draw_transforms();
    }

    void exit() override {
        transform_remove(test);
        entity_destroy(test);
    }
};

Scene* create_test_scene() {
    return new TestScene();
}
