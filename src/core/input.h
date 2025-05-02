#pragma once
#include <string>
struct GLFWwindow;

void input_set_window(GLFWwindow* window);
void input_bind(const std::string& action, int key);
bool input_is_action_pressed(const std::string& action);
