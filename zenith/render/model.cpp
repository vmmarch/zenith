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

/*! ===> Creates on 2021/5/9. <=== */

/*!
 * @author 2B键盘
 */
#include "model.h"
#include "model/loader.h"

namespace zenith
{
    void Model::draw()
    {
        for(const auto& mesh : meshes)
        {
            mesh.draw();
        }
    }

    void Model::load_model(zenith_char path)
    {
        ZENITH_DEBUG(LOAD_MODEL_DEBUG, path);

        STRING _path(path);
        STRING ext = _path.substring(_path.find_last_of(".") + 1);

        // 解析Obj
        if(ext.eq("obj"))
        {
            load_obj(path);
        }

        success_flag += CAUSE_MODEL;
    }

    /**
     * 重新加载整个模型，用于动态加载或是错误加载修正。
     */
    void Model::reload()
    {
        // TODO now do nothing...
    }

}