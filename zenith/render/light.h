#pragma once

#include "shader/shader.h"

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
        virtual void update(ShaderProgram *program) = 0;
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

        void update(ShaderProgram* program)
        {
            program->set_float3("pointLight.position", position);
            program->set_int("pointLight.intensity", intensity);
            program->set_float3("pointLight.color", color);
            program->set_int("pointLight.constant", constant);
            program->set_int("pointLight.linear", linear);
            program->set_int("pointLight.quadratic", quadratic);
        }
    };
}