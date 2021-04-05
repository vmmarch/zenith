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

/*! ===> Creates on 2021/4/5. <=== */

/*!
 * @author 2B键盘
 */
#pragma once
#include <glm/glm.hpp>

namespace zenith
{
    class OrthoGraphicsCamera
    {
        OrthoGraphicsCamera(float top, float bottom, float left, float right );
        void SetProjection(float top, float bottom, float left, float right );

        [[nodiscard]] float GetRotation() const { return m_Rotation; }
        float SetRotation(float rotation) { return m_Rotation = rotation; }

        [[nodiscard]] const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
        [[nodiscard]] const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
        [[nodiscard]] const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; };

    private:
        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ViewProjectionMatrix;
        glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
        float m_Rotation = 0.0f;

        void RecalculateViewMatrix();
    };
}