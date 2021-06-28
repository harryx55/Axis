#include "pch.h"
#include "ImguiLayer.h"

#include "imgui.h"
#include "platform/OpenGL/ImGuiRenderer.h"

#include "GLFW/glfw3.h"
#include "Application.h"

namespace Axis
{
	ImguiLayer::ImguiLayer()
		: Layer("Axis Layer")
	{
	}

	ImguiLayer::~ImguiLayer()
	{
	}

	void ImguiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;

		ImGui_ImplOpenGL3_Init("#version 130");
	}

	void ImguiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show_window = true;
		ImGui::ShowDemoWindow(&show_window);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImguiLayer::OnDetach()
	{
		ImGui::DestroyContext();
		ImGui_ImplOpenGL3_Shutdown();
	}
}