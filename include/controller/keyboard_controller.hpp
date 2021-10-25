#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include <cstddef>
#include <fstream>
#include <iostream>
#include <linux/input.h>
#include "controller/controller_interface.hpp"

namespace controller
{
    class DirectionController : public ControllerInterface
    {
        // See possible keyboard listener.
        private:
            static constexpr float direction_[]    = {   -1, -0.8, -0.6, -0.4, -0.2,   0, 0.2, 0.4, 0.6, 0.8, 1 };
            static constexpr float acceleration_[] = { -0.2, -0.1,    0,  0.1,  0.2, 0.3, 0.4, 0.5              };
            int direction_index_;
            int acceleration_index_;
            int stop_;

        public:
            DirectionController() : direction_index_{5},
                                    acceleration_index_{2},
                                    stop_{0}
            {}

        virtual void set_state(int data) { (void) data; return ; }

        float getThrottle(void) const override { return direction_[direction_index_]; }

        float getSteer(void) const override { return acceleration_[acceleration_index_]; }

        int getStop(void) const { return stop_; };

        friend int updateKeyboard(DirectionController &cont);
    };

    int
    updateKeyboard(DirectionController &cont)
    {
        struct input_event event;
        std::string filename = "/dev/input/event3";
        std::ifstream file(filename);

        if (file.is_open())
        {
            while (!cont.stop_)
            {
                file.read((char *) &event, sizeof(event));

                if (event.type == EV_KEY && event.value == 1)
                {
                    if (event.code == KEY_ESC)
                        cont.stop_ = 1;
                    else
                    {
                        // Update acceleration and direction
                        switch(event.code)
                        {
                            // Use booleans to stay within bounds
                            case KEY_LEFT:
                                cont.direction_index_ -= (cont.direction_index_ > 0);
                                break;
                            case KEY_RIGHT:
                                cont.direction_index_ += (cont.direction_index_ < 10);
                                break;
                            case KEY_UP:
                                cont.acceleration_index_ += (cont.acceleration_index_ < 7);
                                break;
                            case KEY_DOWN:
                                cont.acceleration_index_ -= (cont.acceleration_index_ > 0);
                                break;
                        }
                    }
                }
            }

            file.close();
            return 0;
        }

        std::cout << "Could not open" << filename << '\n';
        return 1;
    }
}

#endif
