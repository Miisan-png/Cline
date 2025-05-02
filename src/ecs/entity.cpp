#include "entity.h"
#include <vector>

static int next_id = 1;
static std::vector<Entity> pool;

Entity entity_create() {
    return next_id++;
}

void entity_destroy(Entity id) {
}
