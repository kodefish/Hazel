#pragma once

#ifdef  HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Init log!");
	HZ_INFO("Hello!");
	int i = 5;
	HZ_INFO("Hello! Var: {0}", i);

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif //  HZ_PLATFORM_WINDOWS

