#include "zenith.h"

class sandbox : public zenith::application
{
public:
    sandbox()
    {
    }

    ~sandbox()
    {
    }

};

zenith::app zenith::createApplication()
{
    return new sandbox();
}