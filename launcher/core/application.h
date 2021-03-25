//
// Created by aorus on 2021/3/25.
//

#ifndef AFTERLIFE_APPLICATION_H
#define AFTERLIFE_APPLICATION_H

#include "core.h"


namespace zenith
{
    class ZENITH_API application
    {
    public:
        application();
        virtual ~application();
        void startup();
    };

    typedef application *app;

    app createApplication();

}

#endif // AFTERLIFE_APPLICATION_H
