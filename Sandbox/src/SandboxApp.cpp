#include "Axis.h"
#include "LayerStack.h"
#include "Layer.h"

class ExampleLayer : public Axis::ILayer
{
public:
	ExampleLayer()
		: ILayer("Example")
	{
		vertexArray.CreateVertexArray();

		float vertices[] =
		{
			-0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f,	0.0f, 1.0f, 0.0f
		};
		vertexBuffer.AttachBuffer(vertices, 20);

		uint32_t indices[] =
		{
			0, 1, 2, 2, 3, 0
		};
		indexBuffer.AttachBuffer(indices, 6);

		vertexArray.AttachAttribs( {0, 2, 5, 0} );
		vertexArray.AttachAttribs( {1, 3, 5, 2} );

		const char* vertexSrc = R"(
			#version 140
			in vec3 aPos;
			in vec3 aColor;
			
			out vec3 color;
			void main()
			{
				gl_Position = vec4(aPos, 1.0);
				color = aColor;
			})";

		const char* fragmentSrc = R"(
			#version 140
			out vec4 fragColor;
			in vec3 color;

			void main()
			{
				fragColor = vec4(0.6, 0.5, 0.4, 1.0) * vec4(color, 1.0);
			})";

		shader = new Axis::OpenGLShaders(vertexSrc, fragmentSrc);
		camera.InitCamera(-128, 128, -72, 72);
	}

	void OnAttach() override
	{
	}

	void OnUpdate(Axis::Timestep timestep) override
	{
		vertexArray.Bind();

		Axis::RenderCommand::Clear({ 0.4f, 0.5f, 0.6f, 1.0f }, Axis::BUFFER_BIT::COLOR_BUFFER_BIT);
		Axis::Renderer::BeginScene(camera);

		shader->bind();

		Axis::Renderer::Submit(shader, indexBuffer);
		// AX_DEBUG_INFO("{0} ms", timestep.GetMilliSeconds());
	}

	void OnRender() override
	{
	}

	void OnImguiRender() override
	{
		//Axis::ImguiLayer::
	}

	void OnDetach() override
	{
	}

private:
	Axis::OpenGLVertexArray vertexArray;
	Axis::OpenGLVertexBuffer vertexBuffer;
	Axis::OpenGLIndexBuffer indexBuffer;
	
	Axis::OpenGLShaders* shader;
	Axis::OrthographicCamera camera;
};

class Sandbox : public Axis::Application
{
public:
	Sandbox()
	{
		PushOverlay(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};


Axis::Application* Axis::CreateApplication()
{
	return new Sandbox();
}
