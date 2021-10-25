#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

namespace controller
{
    class ControllerInterface
    {
        public:
            virtual void set_state(int data) = 0;

            virtual float getThrottle(void) const = 0;
            virtual float getSteer(void) const = 0;
            virtual int getStop(void) const = 0;
    };
}

#endif
