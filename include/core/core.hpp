#ifndef CORE_H
#define CORE_H

namespace core
{
    class Core
    {
    private:
        struct state state_;

    public:
        Core(struct state &state) : state_(state)
        {}

        virtual bool start()      const = 0;
        virtual bool getData()    const = 0;
        virtual bool sendAction() const = 0;
        virtual bool stop()       const = 0;
    };
}

#endif
