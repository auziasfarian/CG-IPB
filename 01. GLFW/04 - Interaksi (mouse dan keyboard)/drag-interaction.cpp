//
//  main.c
//  openGL
//
//  Created by Auzi Asfarian on 20/08/19.
//  Copyright © 2019 Auzi Asfarian. All rights reserved.
//
#define GLFW_SILENCE_DEPRECATION true
#define TRUE 1
#define FALSE 0
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

class Rectangle{
public:
    double x=200, y=200;
    double prevY = 0;
    int red = 255, green = 255, blue = 255;
    int size = 20;

    int isSelected = FALSE;
    int isDragged = FALSE;
    int isWillDrop = FALSE;
    double acceleration = 0;
    
    void display()
    {
        if(isWillDrop == TRUE && isDragged == FALSE){
            if (y < prevY)
                y+=acceleration;
                acceleration++;
            if(y >= prevY){
                isWillDrop = FALSE;
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
    
    void doIfPicked(double xpos, double ypos){
        if(((xpos < size + x) && (xpos > -size + x)) &&
           ((ypos < size + y) && (ypos > -size + y))){
            red = 0; green = 255; blue = 0;
            isSelected = TRUE;
            if(isDragged == TRUE){
                x = xpos;
                y = ypos;
            }
        }
        else{
            red = green = blue = 255;
            isSelected = FALSE;
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
            if(isSelected == true){
                if(isDragged == true)
                    isDragged = false;
                else{
                    isDragged  = true;
                    prevY = y;
                    isWillDrop = TRUE;
                }
            }
        }
        if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
            size--;
    }
};


Rectangle rect;

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    rect.doIfKeyPressed(key, action);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    rect.doIfPicked(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    double posx, posy;
    glfwGetCursorPos(window, &posx, &posy);
    rect.doIfMouseClicked(button, action, posx, posy);
}

double angle = 0;
int increment = 1;

int main(void) {
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(400, 400, "Interaction", NULL, NULL);
    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    
    while (!glfwWindowShouldClose(window)){
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
        
        rect.display();
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
