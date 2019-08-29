//
//  MINECRAFT
//  OpenGL + GLFW
//
//  Created by Auzi Asfarian on 20/08/19.
//  Copyright © 2019 Auzi Asfarian. All rights reserved.
//
#define GLFW_SILENCE_DEPRECATION true
#include <GLFW/glfw3.h>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

/*
 * RECTANGLE CLASS
 * This class contains the logic and atribut for each rectangle in the scene.
 * Modify this class to adjust the behavior of the rectangle.
 */
class Rectangle{
public:
    // Main attributes
    double x=200, y=200;
    double prevY = 0;
    int red = 255, green = 255, blue = 255;
    int size = 20;
    double acceleration = 0;

    // State
    int isSelected = GL_FALSE;
    int isDragged = GL_FALSE;
    int isWillDrop = GL_FALSE;
    
    // Drawing Function
    void display()
    {
        if(isWillDrop == GL_TRUE && isDragged == GL_FALSE){
            if (y < prevY)
                y+=acceleration;
                acceleration++;
            if(y >= prevY){
                isWillDrop = GL_FALSE;
                acceleration = 0;
            }
        }
        glBegin(GL_POLYGON);
            glColor3ub(red, green, blue);
            glVertex2f(-size + x,  size + y);
            glVertex2f( size + x,  size + y);
            glVertex2f( size + x, -size + y);
            glVertex2f(-size + x, -size + y);
        glEnd();
    }
    
    void update(){
        
    }
    
    void doIfPicked(double xpos, double ypos){
        if(((xpos < size + x) && (xpos > -size + x)) &&
           ((ypos < size + y) && (ypos > -size + y))){
            red = 0; green = 255; blue = 0;
            isSelected = GL_TRUE;
            if(isDragged == GL_TRUE){
                x = xpos;
                y = ypos;
            }
        }
        else{
            red = green = blue = 255;
            isSelected = GL_FALSE;
        }
    }
    
    void doIfKeyPressed(int key, int action){
        if (key == GLFW_KEY_UP && action == GLFW_REPEAT)
            y-=10;
        if (key == GLFW_KEY_DOWN && action == GLFW_REPEAT)
            y+=10;
        if (key == GLFW_KEY_LEFT && action == GLFW_REPEAT)
            x-=10;
        if (key == GLFW_KEY_RIGHT && action == GLFW_REPEAT)
            x+=10;
    }
    
    void doIfMouseClicked(int button, int action, double posx, double posy){
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
            if(isSelected == GL_TRUE){
                if(isDragged == GL_TRUE)
                    isDragged = GL_FALSE;
                else{
                    isDragged  = GL_TRUE;
                    prevY = y;
                    isWillDrop = GL_TRUE;
                }
            }
        }
        if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
            size--;
    }
};

/*
 * RECTANGLE OBJECT ARRAY
 * This array will contains all rectangle objects in application.
 * Primary function is to manage operation to all rectangle in the scene.
 * Currently limited to 100.
 */
class RectangleList{
public:
    list<Rectangle> objects;
    int x;
    void insert(Rectangle obj){
        objects.push_back(obj);
    }
    
    void display(){
        if(!objects.empty()){
            list <Rectangle> :: iterator it;
            for(it = objects.begin(); it != objects.end(); ++it)
                (*it).display();
        }
    }
    
    void handleKeyCallbacks(int key, int action){
        if(!objects.empty()){
            list <Rectangle> :: iterator it;
            for(it = objects.begin(); it != objects.end(); ++it)
                (*it).doIfKeyPressed(key, action);
        }
    }
    
    void handleCursorPositionCallback(double xpos, double ypos){
        if(!objects.empty()){
            list <Rectangle> :: iterator it;
            for(it = objects.begin(); it != objects.end(); ++it)
                (*it).doIfPicked(xpos, ypos);
        }
    }
    
    void handleMouseButtonCallback(int button, int action, double posx, double posy){
        if(!objects.empty()){
            list <Rectangle> :: iterator it;
            for(it = objects.begin(); it != objects.end(); ++it)
                (*it).doIfMouseClicked(button, action, posx, posy);
        }
    }
};
RectangleList objectList;

/*
 * CALLBACKS FUNCTIONS
 */
static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    objectList.handleKeyCallbacks(key, action);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    objectList.handleCursorPositionCallback(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    double posx, posy;
    glfwGetCursorPos(window, &posx, &posy);
    objectList.handleMouseButtonCallback(button, action, posx, posy);
}

/*
 * MAIN FUNCTION
 */

int main(void) {
    /* Creating Windows */
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(400, 400, "Interaction", NULL, NULL);
    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Registering Callbacks */
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    /* Object List Preparation */
    Rectangle rect;
    objectList.insert(rect);

    /* MAIN LOOP */
    while (!glfwWindowShouldClose(window)){
        /* Preparing Frame Creation */
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 400, 400 , 0 , 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        /* Object Drawing*/
        objectList.display();
        
        /* Handling Frame Changes */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    /* Destroying Windows */
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
