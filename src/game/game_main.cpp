extern void ready();
extern void process();
extern bool should_close();
extern void update();
extern void shutdown();

int main() {
    ready();
    while (!should_close()) {
        process();
        update();
    }
    shutdown();
    return 0;
}
