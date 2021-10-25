#include <iostream>
#include <fstream>
#include <future>
#include <linux/input.h>
#include <unistd.h>

#include "controller/keyboard_controller.hpp"


int
main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    // Handle args

    // Define controller
    auto cont = controller::DirectionController();

    // Start getting controller inputs
    auto res = std::async(std::launch::async, [&cont]{ controller::updateKeyboard(cont); });

    while (!cont.getStop())
    {
        std::cout << "Throttle: " << cont.getThrottle() << '\n';
        std::cout << "Steer: " << cont.getSteer() << '\n';
        usleep(50000);
    }

    return 0;
}
