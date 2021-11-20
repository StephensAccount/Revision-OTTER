#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"
#include "Gameplay/GameObject.h"

struct GLFWwindow;

/// <summary>
/// A simple behaviour that applies an impulse along the Z axis to the 
/// rigidbody of the parent when the space key is pressed
/// </summary>
class InteractSystem : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<InteractSystem> Sptr;

	InteractSystem();
	virtual ~InteractSystem();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;

	void interact();

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(InteractSystem);
	virtual nlohmann::json ToJson() const override;
	static InteractSystem::Sptr FromJson(const nlohmann::json& blob);

	Gameplay::GameObject::Sptr _player;
	float _distance = 0;
	float _interactDistance = 0;

	bool _requiresKey = false;
	int _requiredKey = 0;

	GLFWwindow* _window;

protected:

	//int _keys;

	
};