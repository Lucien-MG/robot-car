#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "utils/state.hpp"

namespace communication
{
    class Communication
    {
    private:
        struct state state_;

    public:
        Communication(struct state &state) : state_(state)
        {}

        virtual bool start()    const = 0;
        virtual bool recv()     const = 0;
        virtual bool sendData() const = 0;
    };
}

#endif
