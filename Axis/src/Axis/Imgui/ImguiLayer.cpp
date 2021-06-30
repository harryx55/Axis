#include "pch.h"
#include "ImguiLayer.h"

#include "imgui.h"
#include "platform/OpenGL/ImGuiRenderer.h"
#include "platform/OpenGL/imgui_impl_glfw.h"

#include "GLFW/glfw3.h"
#include "Application.h"
#include "glad/glad.h"

namespace Axis
{
	ImguiLayer::ImguiLayer()
		: ILayer("Axis Layer")
	{
	}

	ImguiLayer::~ImguiLayer()
	{
	}

	void ImguiLayer::OnAttach()
	{
		int status = gladLoadGL();
		if (!status)
			AX_ASSERT(status, "glad not initialzed");
		
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;

		ImGui_ImplOpenGL3_Init("#version 140");
		
		// PLACE HOLDER CODE
		Application& app = Application::Get();
		ImGui_ImplGlfw_InitForOpenGL(app.GetWindow().GetWindow(), true);
	}

	void ImguiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2();
		Application& app = Application::Get();

		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		bool show_window = true;
		ImGui::ShowDemoWindow(&show_window);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImguiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}