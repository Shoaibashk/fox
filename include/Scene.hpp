#include "Entity.hpp"

namespace Fox
{
    class Scene
    {
    private:
        std::shared_ptr<entt::registry> m_Registry;
        // Fox::Entity m_Entity;

    public:
        std::shared_ptr<entt::registry> GetScene() { return m_Registry; };
        Fox::Entity CreateEntity();

        Scene();
        ~Scene();
    };

    inline Fox::Entity Scene::CreateEntity()
    {
        auto entity = m_Registry->create();

        return Fox::Entity(entity, m_Registry);
    }

    inline Scene::Scene()
    {
        m_Registry = std::make_shared<entt::registry>();
    }

    inline Scene::~Scene()
    {
    }
}