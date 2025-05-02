#include <GLFW/glfw3.h>

static float last = 0.0f;
static float delta = 0.0f;

void time_update() {
    float now = glfwGetTime();
    delta = now - last;
    last = now;
}

float time_get_delta() {
    return delta;
}
