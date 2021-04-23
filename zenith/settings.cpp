/*! ************************************************************************
 *
 * Copyright (C) 2020 dahan All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/4/23. <=== */

/*!
 * @author 2B键盘
 */
#include "settings.h"

namespace zenith
{
    struct settings_t
    {
        bool CAN_BE_RELOAD      = false;           // 是否重新加载
        bool multisample        = false;           // 多重采样抗锯齿
        bool depthtest          = false;           // 多重采样抗锯齿
    };

    settings_t *settings = new settings_t();

    void __value(int k, bool v)
    {
        switch (k)
        {
            case KEY_MULTISAMPLE: settings->multisample     = v; break;
            case KEY_DEPTHTEST:   settings->depthtest       = v; break;
            default: return;
        }

        settings->CAN_BE_RELOAD = true;
    }

    /**
     * 加载配置
     */
    void reload_settings()
    {
        if (settings->CAN_BE_RELOAD)
        {
            if (settings->multisample)
            {
                GLAPI_EnableMultisample();
            } else
            {
                GLAPI_DisableMultisample();
            }

            if (settings->depthtest)
            {
                GLAPI_EnableDepthTest();
            } else
            {
                GLAPI_DisableDepthTest();
            }

            settings->CAN_BE_RELOAD = false;
        }
    }
}