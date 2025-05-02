#include "core/scene.h"
#include "core/input.h"
#include <GL/glew.h>
#include "core/time.h"

struct TestScene : public Scene {
    void ready() override {
        printf("hello");
    }
    void process() override {
        float dt = time_get_delta();
        printf("delta: %f\n", dt);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void exit() override {}
};



Scene* create_test_scene() {
    return new TestScene();
}
