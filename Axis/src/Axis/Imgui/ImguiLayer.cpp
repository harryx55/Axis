#include "pch.h"
#include "ImguiLayer.h"

#include "imgui.h"

#include "backends/imgui_impl_opengl3.h"
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
	}

	void ImguiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImguiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImguiLayer::End()
	{
		ImGuiIO io = ImGui::GetIO();
		Application& app = Application::Get();

		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImguiLayer::OnImguiRender()
	{
		static bool show_window = true;
		ImGui::ShowDemoWindow(&show_window);
	}
}