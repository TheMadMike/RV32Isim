#include "sim.h"
#include "logs.h"

void run() {
    log_info("Hello, world! %d", 2137);
}

int main(void) {
    run();
    return 0;
}