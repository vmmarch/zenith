#include "zenith.h"

class launcher : public zenith::application
{
public:
    launcher()
    {
    }

    ~launcher()
    {
    }

};

zenith::app zenith::createApplication()
{
    return new launcher();
}