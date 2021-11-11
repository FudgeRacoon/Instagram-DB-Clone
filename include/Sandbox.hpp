#ifndef SANDBOX_HPP
#define SANDBOX_HPP

#include <stdio.h>

#include <core/Application.hpp>
#include <input/InputManager.hpp>
using namespace re;

class Sandbox : public Application
{
public:
    Sandbox(const ApplicationProps& props) : 
        Application(props) {}

public:
    void OnStart() override
    {
        // Create ImGui context
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;

        // Enable keyboard input
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_window->GetWindowHandle(), true);
        ImGui_ImplOpenGL3_Init("#version 330 core");
    }

    void OnEvent(Event* event) override
    {
        switch(event->GetEventType())
        {
            case WINDOW_CLOSED  : OnWindowClose((WindowClosedEvent*)event); break;
            case WINDOW_RESIZED : OnWindowResize((WindowResizedEvent*)event); break;
        }
    }

    void OnUpdate() override
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void OnShutDown() override
    {
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
};

#endif