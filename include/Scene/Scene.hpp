#include "Entity.hpp"

namespace Fox
{
    class Scene
    {
    private:
        std::shared_ptr<entt::registry> m_Registry;

    public:
        std::shared_ptr<entt::registry> GetScene() { return m_Registry; };
        std::shared_ptr<Entity> CreateEntity();
        void Update(float ts);

        Scene();
        ~Scene();
    };

    inline std::shared_ptr<Entity> Scene::CreateEntity()
    {
        auto entity = m_Registry->create();
        return std::make_shared<Entity>(entity, m_Registry);
    }

    inline void Scene::Update(float ts)
    {
        for (auto [entity, pos, scale] : m_Registry->view<Components::Position, Components::Scale>().each())
        {
            std::cout << pos.x << std::endl;
            std::cout << pos.y << std::endl;
            std::cout << pos.z << std::endl;
            std::cout << scale.x << std::endl;
            std::cout << scale.y << std::endl;
            std::cout << scale.z << std::endl;
        }
    }

    inline Scene::Scene()
    {
        m_Registry = std::make_shared<entt::registry>();
    }

    inline Scene::~Scene()
    {
    }

}