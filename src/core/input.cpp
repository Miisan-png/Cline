#include <GLFW/glfw3.h>
#include <unordered_map>
#include <string>

static std::unordered_map<std::string, int> actionKeyMap;
static GLFWwindow* inputWindow = nullptr;

void input_set_window(GLFWwindow* window) {
    inputWindow = window;
}

void input_bind(const std::string& action, int key) {
    actionKeyMap[action] = key;
}

bool input_is_action_pressed(const std::string& action) {
    if (!inputWindow) return false;
    auto it = actionKeyMap.find(action);
    if (it == actionKeyMap.end()) return false;
    return glfwGetKey(inputWindow, it->second) == GLFW_PRESS;
}
