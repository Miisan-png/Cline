#include "scene.h"

static Scene* current = nullptr;

void scene_set(Scene* newScene) {
    if (current) current->exit();
    current = newScene;
    if (current) current->ready();
}

void scene_process() {
    if (current) current->process();
}

void scene_shutdown() {
    if (current) {
        current->exit();
        delete current;
        current = nullptr;
    }
}
