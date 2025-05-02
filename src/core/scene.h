#pragma once

struct Scene {
    virtual void ready() = 0;
    virtual void process() = 0;
    virtual void exit() = 0;
    virtual ~Scene() {}
};

void scene_set(Scene* newScene);
void scene_process();
void scene_shutdown();
