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


struct settings_t
{
    bool   CAN_BE_RELOAD = false;                 // 是否重新加载
    bool   Flags_MultiSample = false;             // 多重采样抗锯齿
    bool   Flags_DepthTest = false;               // 多重采样抗锯齿
    bool   Flags_CursorMoveCamera = true;         // 鼠标移动相机
    float  Camera_Move_Speed = 3.0f;              // 相机移动速度
};

settings_t *settings = new settings_t();

void set_value(int k, bool v)
{
    switch (k)
    {
        case KEY_MULTISAMPLE:
            settings->Flags_MultiSample = v;
            break;
        case KEY_DEPTHTEST:
            settings->Flags_DepthTest = v;
            break;
        case KEY_CURSOR_MOVE_CAMER:
            settings->Flags_CursorMoveCamera = v;
            break;
        default:
            return;
    }

    settings->CAN_BE_RELOAD = true;
}

void set_value(int k, float v)
{
    switch (k) {

        case KEY_CAMERA_MOVE_SPEED:
            settings->Camera_Move_Speed = v;
            break;
        default:
            return;
    }
}

/**
 * 加载配置
 */
void reload_setting()
{
    if (settings->CAN_BE_RELOAD)
    {
        if (settings->Flags_MultiSample)
        {
            GLAPI_EnableMultisample();
        } else
        {
            GLAPI_DisableMultisample();
        }

        if (settings->Flags_DepthTest)
        {
            GLAPI_EnableDepthTest();
        } else
        {
            GLAPI_DisableDepthTest();
        }

        settings->CAN_BE_RELOAD = false;
    }
}

bool get_bool(int k)
{
    switch (k)
    {
        case KEY_MULTISAMPLE:
            return settings->Flags_MultiSample;
        case KEY_DEPTHTEST:
            return settings->Flags_DepthTest;
        case KEY_CURSOR_MOVE_CAMER:
            return settings->Flags_CursorMoveCamera;
    }

    return false;
}

float get_float(int k)
{
    switch (k)
    {
        case KEY_CAMERA_MOVE_SPEED:
            return settings->Camera_Move_Speed;
    }

    return 0.0f;
}