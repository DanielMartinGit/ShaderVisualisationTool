# ShaderVisualisationTool

# Goal 
* The goal of this project is to create a simple application that allows the user to view the effects of a written shader on different objects such as Squares and Triangles. 
* This application will allow the user to choose what object is rendered, to load in shaders of different types (Vertex, Fragment, Compute) and then to render the object with the loaded shaders
* The hope is to also add support for writing shaders within the application with a simple text editor which will mean the user can write and test shaders without leaving the application.

# Libraries 
* Dear ImGui 
* GLFW
* OpenGL
* PFD (Portable-File-Dialogs)
* GLAD
* ImGuiColorTextEdit 

# Features
* Ability to select from different Primitives (Triangle, Square)
* Ability to indefinetely load different Vertex and Fragment shaders (other shader support such as Compute shaders planned)
* Console readout for errors and messages 
* Shader Editor (For editing shader files while in the application) with Syntax Highlight (Thanks to the ImGuiColorTextEdit library)

# How to use
* Clone project and open the GenerateProject.bat file
* Open the solution and build 
* Choose from the 2 primitive types (Square or Triangle)
* Load a Vertex and Fragment shader of your choice 
* Click the "Render" button to view the effects
* Using the Script Editor, click file and "Open Shader File"
* Edit your shader file and the go to "File, Save Shader"
* Click the "Render" button to view your changes

# Screenshots
![image](https://user-images.githubusercontent.com/19360613/161786338-d88c74a4-3263-43f3-9368-729c116fbe39.png)
![image](https://user-images.githubusercontent.com/19360613/161790628-617f73df-98c3-4360-b754-ed58d5146b1d.png)

