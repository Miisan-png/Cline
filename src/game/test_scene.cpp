#include "core/scene.h"
#include "core/input.h"
#include <GL/glew.h>
#include "core/time.h"
#include "core/draw.h"

struct TestScene : public Scene {
    void ready() override {
        printf("hello");
    }
    void process() override {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        draw_rect(-0.2f, -0.2f, 0.4f, 0.4f, 0.9f, 0.3f, 0.3f);
    }
    void exit() override {}
};



Scene* create_test_scene() {
    return new TestScene();
}
