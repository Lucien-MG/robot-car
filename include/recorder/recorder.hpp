#ifndef RECORDER_H
#define RECORDER_H

namespace recorder
{
    class Recorder
    {
    private:
        struct state state_;

    public:
        Recorder(struct state &state) : state_(state)
        {}

        virtual bool start()  const = 0;
        virtual bool record() const = 0;
        virtual bool stop()   const = 0;
    };
}

#endif
