#include "zenith.h"

class launcher : public zenith::application
{
public:
    launcher() = default;
    ~launcher() override = default;

};

zenith::app zenith::createApplication()
{
    return new launcher();
}