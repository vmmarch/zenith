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

/*! ===> Creates on 2021/4/30. <=== */

/*!
 *           ----------------
 *           | render group |
 *           ----------------
 *                  |
 *                  | -----------------------
 *                  |                       |
 *                 \_/                     \_/
 *           ----------------       ----------------
 *           | render queue |       |   renderer   |
 *           ----------------       ----------------
 *                  |                       |
 *                  |                       |               Rendering pipeline.
 *                  |                       | --------------------------------------------
 *                  |                                                                    |
 *                 \_/                                                                   |
 *       -----------------------  ----------->  ---------------------------              |
 *       | render object  sort |                | for shader/vertex/other |              |
 *       -----------------------  <-----------  ---------------------------              |
 *                  |                                                                    |
 *                  |                                                                    |
 *                  |                                                                    |
 *       -----------------------                                                         |
 *       | sorted object queue |                                                         |
 *       -----------------------                                                         |
 *                  |                                                                    |
 *                  | -------------------                                                |
 *                                      |                                                |
 *                                      |  Submit Render Mesh.                         |
 *                                      |                                                |
 *                                     \_/                                               |
 *                            ----------------------            Execute Render.          |
 *                            |     GPU Render     | <------------------------------------
 *                            ----------------------
 *
 * @author 2B??????
 */
#pragma once

class RenderGroups
{
};
