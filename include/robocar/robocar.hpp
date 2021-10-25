#ifndef ROBOCAR_H
#define ROBOCAR_H

namespace robocar
{
    template <typename Comm, typename Core, typename Pol, typename Rec>
    class Robocar
    {
    private:
        Comm communication_; // Template for Communication abstract class
        Core core_;          // Template for Core          abstract class
        Pol  policy_;        // Template for Policy        abstract class
        Rec  recorder_;      // Template for Recorder      abstract class

    public:
        Robocar(Comm& communication,
                Core& core,
                Pol&  policy,
                Rec&  recorder)
              : communication_{communication},
                core_{core},
                policy_{policy},
                recorder_{recorder}
        {}
    };
}

#endif
