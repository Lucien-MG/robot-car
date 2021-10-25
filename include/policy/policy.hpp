#ifndef POLICY_H
#define POLICY_H

namespace policy
{
    class Policy
    {
    private:
        struct state state_;

    public:
        Policy(struct state &state) : state_(state)
        {}

        virtual bool start() const = 0;
        virtual bool step()  const = 0;
        virtual bool stop()  const = 0;
    };
}

#endif
