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
 * @author 2B键盘
 */
#pragma once

namespace zenith
{
    class Light
    {
    protected:
        float intensity;
        glm::vec3 color;

    public:
        Light(float intensity, glm::vec3 color)
        {
            this->intensity = intensity;
            this->color = color;
        }

        ~Light()
        {

        }

        //Functions
        virtual void update(Shader &program) = 0;
    };

    class PointLight : public Light
    {
    protected:
        glm::vec3 position;
        float constant;
        float linear;
        float quadratic;

    public:
        PointLight(glm::vec3 position, float intensity = 1.f, glm::vec3 color = glm::vec3(1.f),
                   float constant = 1.f, float linear = 0.045f, float quadratic = 0.0075f)
                : Light(intensity, color)
        {
            this->position = position;
            this->constant = constant;
            this->linear = linear;
            this->quadratic = quadratic;
        }

        ~PointLight()
        {

        }

        void setPosition(const glm::vec3 position)
        {
            this->position = position;
        }

        void update(Shader &program)
        {
            program.setVec3f(this->position, "pointLight.position");
            program.set1f(this->intensity, "pointLight.intensity");
            program.setVec3f(this->color, "pointLight.color");
            program.set1f(this->constant, "pointLight.constant");
            program.set1f(this->linear, "pointLight.linear");
            program.set1f(this->quadratic, "pointLight.quadratic");
        }
    };
}