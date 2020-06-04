#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer() 
		: Layer("ExampleLayer") 
	{
	}

	void OnUpdate() override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_TRACE("Tab key is pressed! (poll)");
	}

	void OnEvent(Hazel::Event& e) override
	{
		if (e.GetEventType() == Hazel::EventType::KeyPressed) {
			Hazel::KeyPressedEvent& keyPressed = (Hazel::KeyPressedEvent&)e;
			if (keyPressed.GetKeyCode() == static_cast<int32_t>(HZ_KEY_TAB));
				HZ_TRACE("Tab key is pressed! (event)");
		}

	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
