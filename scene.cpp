#include "scene.hpp"

Scene::Scene() : sceneLive(false)
{

}

Scene::~Scene()
{

}

void Scene::addEntity(Entity *entity)
{
	entities.push_back(entity);
	if(sceneLive)
	{
		entity->entityAdded();
	}
}

void Scene::addRenderable(Renderable *renderable)
{
	renderables.push_back(renderable);
}

void Scene::removeRenderable(Renderable *renderable)
{
	for(int i = 0; i < renderables.size(); i++)
	{
		if(renderables[i] == renderable)
		{
			renderables.erase(renderables.begin()+i);
			return;
		}
	}
}

void Scene::sceneAdded()
{
	sceneLive = true;
	for(int i = 0; i < entities.size(); i++)
	{
		entities[i]->entityAdded();
	}
}

void Scene::sceneRemoved()
{

}

void Scene::update()
{
	for(int i = 0; i < entities.size();)
	{
		if(!entities[i]->update())
		{
			entities[i]->entityRemoved();
			delete entities[i];
			entities.erase(entities.begin()+i);
		}
		else
		{
			++i;
		}
	}

	for(int i = 0; i < entities.size();)
	{
		for(int k = 0; k < entities.size(); )
		{
			if(i == k || !entities[i]->isAlive() || !entities[k]->isAlive())
			{
				k++;
				continue;
			}

			entities[i]->checkCollision(entities[k]);

			k++;
		}
		i++;
	}
}

void Scene::render()
{
	for(int i = 0; i < renderables.size();)
	{
		if(!renderables[i]->render())
		{
			renderables.erase(renderables.begin()+i);
		}
		else
		{
			++i;
		}
	}
}


Entity *Scene::findEntityByName(const string &name)
{
	for(int i = 0; i<entities.size(); i++)
	{
		if(entities[i]->getName() == name)
		{
			return entities[i];
		}
	}

	return 0;
}
