#include "core/scene.h"
#include "core/input.h"
#include <GL/glew.h>

struct TestScene : public Scene {
    void ready() override {
        printf("hello");
    }
    void process() override {
        if (input_is_action_pressed("jump")) {
            glClearColor(0.6f, 0.2f, 0.2f, 1.0f); // red when holding space
        } else {
            glClearColor(0.1f, 0.1f, 0.15f, 1.0f); // default
        }
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void exit() override {}
};



Scene* create_test_scene() {
    return new TestScene();
}
