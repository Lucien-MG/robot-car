#include <iostream>
#include <fstream>
#include <future>
#include <linux/input.h>
#include <unistd.h>

#include "controller/keyboard_controller.hpp"

#include "communication/communication.hpp"
#include "core/core.hpp"
#include "policy/policy.hpp"
#include "recorder/recorder.hpp"
#include "robocar/robocar.hpp"


int
main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    // Handle args

    // Define controller
    auto cont = controller::DirectionController();

    // Start getting controller inputs
    auto async = std::async(std::launch::async, [&cont]{ controller::updateKeyboard(cont); });

    // Check if controller could be setup
    auto status = async.wait_for(std::chrono::seconds(1));
    if (status == std::future_status::ready)
        return 1;

    while (!cont.getStop())
    {
        std::cout << "Throttle: " << cont.getThrottle() << '\n';
        std::cout << "Steer: " << cont.getSteer() << '\n';
        usleep(50000);
    }

    return 0;
}
