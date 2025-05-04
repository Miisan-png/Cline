
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "core/scene.h"
#include "core/time.h"
#include "core/vec2.h"
#include "core/input.h"

#include "ecs/entity.h"
#include "ecs/components/transform.h"
#include "ecs/components/velocity.h"
#include "ecs/components/player_controller.h"
#include "ecs/components/collider.h"
#include "ecs/components/area.h"
#include "ecs/components/sprite.h"
#include "ecs/components/filter.h"

#include "ecs/systems/player_input.h"
#include "ecs/systems/movement.h"
#include "ecs/systems/world_bounds.h"
#include "ecs/systems/collision_check.h"
#include "ecs/systems/draw_sprites.h"
#include "ecs/systems/collision_draw.h"



Entity player;
std::vector<Entity> coins;
int score = 0;
float gameTimer = 0.0f;
bool win = false;

struct TestScene : public Scene {
    void ready() override {
        std::srand((unsigned)std::time(nullptr));
        glEnable(GL_TEXTURE_2D);

        player = entity_create();
        transform_add(player);
        transform_get(player)->position = Vec2(0.0f, 0.0f);
        velocity_add(player);
        player_controller_add(player);
        collider_add(player);
        sprite_add(player, "assets/robot.png");
        filter_add(player, FILTER_NEAREST);


        for (int i = 0; i < 5; ++i) {
            Entity coin = entity_create();
            transform_add(coin);
            float x = -0.7f + static_cast<float>(std::rand()) / RAND_MAX * 1.4f;
            float y = -0.7f + static_cast<float>(std::rand()) / RAND_MAX * 1.4f;
            transform_get(coin)->position = Vec2(x, y);
            collider_add(coin);
            area_add(coin);
            coins.push_back(coin);
        }

        input_bind("left", GLFW_KEY_A);
        input_bind("right", GLFW_KEY_D);
        input_bind("up", GLFW_KEY_W);
        input_bind("down", GLFW_KEY_S);
    }

    void process() override {
        float dt = time_get_delta();
        gameTimer += dt;

        if (win) {
            glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
        } else {
            glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        }
        glClear(GL_COLOR_BUFFER_BIT);

        system_player_input();
        system_movement(dt);
        system_world_bounds();
        system_collision_check();

        Vec2 ppos = transform_get(player)->position;
        for (int i = (int)coins.size() - 1; i >= 0; --i) {
            Entity c = coins[i];
            Vec2 cpos = transform_get(c)->position;
            Vec2 d = ppos - cpos;
            if (d.x*d.x + d.y*d.y < 0.05f*0.05f) {
                score++;
                transform_remove(c);
                collider_remove(c);
                area_remove(c);
                entity_destroy(c);
                coins.erase(coins.begin() + i);
                std::cout << "Coin collected! Score: " << score << std::endl;
            }
        }
        if (!win && coins.empty()) {
            win = true;
            std::cout << "All coins collected in " << gameTimer << " seconds! You win!" << std::endl;
        }

        system_draw_sprites();
        system_collision_draw();
    }

    void exit() override {
        sprite_remove(player);
        transform_remove(player);
        velocity_remove(player);
        player_controller_remove(player);
        collider_remove(player);
        entity_destroy(player);

        for (auto c : coins) {
            transform_remove(c);
            collider_remove(c);
            area_remove(c);
            entity_destroy(c);
        }
        coins.clear();
    }
};

Scene* create_test_scene() {
    return new TestScene();
}
