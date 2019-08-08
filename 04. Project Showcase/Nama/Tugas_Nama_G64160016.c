#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void error_callback(int error, const char* description)
{
fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
GLFWwindow* window;
glfwSetErrorCallback(error_callback);
if (!glfwInit())
exit(EXIT_FAILURE);
window = glfwCreateWindow(800, 800, "G64160016", NULL, NULL);
if (!window)
{
glfwTerminate();
exit(EXIT_FAILURE);
}glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(244,94.7);
glColor3ub(255, 255, 255);
glVertex2f(240,94.7);
glColor3ub(255, 255, 255);
glVertex2f(240,624.5);
glColor3ub(255, 255, 255);
glVertex2f(244,624.5);
glEnd();

glfwMakeContextCurrent(window);
glfwSwapInterval(1);
glfwSetKeyCallback(window, key_callback);

int hehe=0,buff=0;

while (!glfwWindowShouldClose(window))
{
float ratio;
int width, height;
glfwGetFramebufferSize(window, &width, &height);
ratio = width / (float) height;
glViewport(0, 0, width, height);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 800, 800, 0, 1.f, -1.f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();


if(buff==0){
hehe++;
hehe=hehe%200;
}

buff++;
buff=buff%5;
//background
glBegin(GL_POLYGON);
glColor3ub(16, 152, 247);
glVertex2f(0,0);
glColor3ub(16, 152, 247);
glVertex2f(800,0);
glColor3ub(16, 152, 247);
glVertex2f(800,800);
glColor3ub(16, 152, 247);
glVertex2f(0,800);
glEnd();

//dalemansquare
glBegin(GL_POLYGON);
glColor3ub(16, 152, 247);
glVertex2f(243.008,94.712);
glColor3ub(16, 152, 247);
glVertex2f(655.748,94.712);
glColor3ub(16, 152, 247);
glVertex2f(655.748,624.474);
glColor3ub(16, 152, 247);
glVertex2f(243.008,624.474);
glEnd();

//line
glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(423,321);
glColor3ub(255, 255, 255);
glVertex2f(426,321);
glColor3ub(255, 255, 255);
glVertex2f(426,595);
glColor3ub(255, 255, 255);
glVertex2f(423,595);
glEnd();

//A
glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(466,445);
glColor3ub(255, 255, 255);
glVertex2f(480,445);
glColor3ub(255, 255, 255);
glVertex2f(526,352);
glColor3ub(255, 255, 255);
glVertex2f(526,327);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(526,352);
glColor3ub(255, 255, 255);
glVertex2f(526,327);
glColor3ub(255, 255, 255);
glVertex2f(585,445);
glColor3ub(255, 255, 255);
glVertex2f(572,445);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(553,407);
glColor3ub(255, 255, 255);
glVertex2f(548,396);
glColor3ub(255, 255, 255);
glVertex2f(504,396);
glColor3ub(255, 255, 255);
glVertex2f(499,407);
glEnd();

//I
glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(602.3,327);
glColor3ub(255, 255, 255);
glVertex2f(615.5,327);
glColor3ub(255, 255, 255);
glVertex2f(615.5,445);
glColor3ub(255, 255, 255);
glVertex2f(602.3,445);
glEnd();

//L
glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(476,470.5);
glColor3ub(255, 255, 255);
glVertex2f(488.3,470.5);
glColor3ub(255, 255, 255);
glVertex2f(488.3,588.6);
glColor3ub(255, 255, 255);
glVertex2f(476,588.6);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(488.3,588.6);
glColor3ub(255, 255, 255);
glVertex2f(535.6,588.6);
glColor3ub(255, 255, 255);
glVertex2f(535.6,577.2);
glColor3ub(255, 255, 255);
glVertex2f(488.3,577.2);
glEnd();

//F
glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(555.1,588.6);
glColor3ub(255, 255, 255);
glVertex2f(555.1,470.5);
glColor3ub(255, 255, 255);
glVertex2f(567.4,470.5);
glColor3ub(255, 255, 255);
glVertex2f(567.4,588.6);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(567.4,470.5);
glColor3ub(255, 255, 255);
glVertex2f(567.4,482);
glColor3ub(255, 255, 255);
glVertex2f(616.8,482);
glColor3ub(255, 255, 255);
glVertex2f(616.8,470.5);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(567.4,519.07);
glColor3ub(255, 255, 255);
glVertex2f(567.4,530.64);
glColor3ub(255, 255, 255);
glVertex2f(616.8,530.64);
glColor3ub(255, 255, 255);
glVertex2f(616.8,519.07);
glEnd();

//square1
glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(244,94.7);
glColor3ub(255, 255, 255);
glVertex2f(240,94.7);
glColor3ub(255, 255, 255);
glVertex2f(240,624.5);
glColor3ub(255, 255, 255);
glVertex2f(244,624.5);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(658,94.7);
glColor3ub(255, 255, 255);
glVertex2f(654,94.7);
glColor3ub(255, 255, 255);
glVertex2f(654,624.5);
glColor3ub(255, 255, 255);
glVertex2f(658,624.5);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(658,94.7);
glColor3ub(255, 255, 255);
glVertex2f(240,94.7);
glColor3ub(255, 255, 255);
glVertex2f(240,90.7);
glColor3ub(255, 255, 255);
glVertex2f(658,90.7);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(658,620.5);
glColor3ub(255, 255, 255);
glVertex2f(240,620.5);
glColor3ub(255, 255, 255);
glVertex2f(240,624.5);
glColor3ub(255, 255, 255);
glVertex2f(658,624.5);
glEnd();

//triangle

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);
glVertex2f(176.5,131);
glColor3ub(255, 255, 255);
glVertex2f(243,119);
glColor3ub(255, 255, 255);
glVertex2f(243,493.5);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);
glVertex2f(390,94.71);
glColor3ub(255, 255, 255);
glVertex2f(590,58.5);
glColor3ub(255, 255, 255);
glVertex2f(597,94.71);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);
glVertex2f(655.75,425.5);
glColor3ub(255, 255, 255);
glVertex2f(687.5,588.61);
glColor3ub(255, 255, 255);
glVertex2f(655.75,594.5);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);
glVertex2f(476.02,624.474);
glColor3ub(255, 255, 255);
glVertex2f(265,624.474);
glColor3ub(255, 255, 255);
glVertex2f(272,660);
glEnd();

//triangle2
glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);
glVertex2f(125,179.7);
glColor3ub(255, 255, 255);
glVertex2f(181.47,158.097);
glColor3ub(255, 255, 255);
glVertex2f(243.01,493.5);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(518.5,35);
glColor3ub(255, 255, 255);
glVertex2f(532,69);
glColor3ub(255, 255, 255);
glVertex2f(390,94.712);
glColor3ub(255, 255, 255);
glVertex2f(358,94.712);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(655.748,400);
glColor3ub(255, 255, 255);
glVertex2f(655.748,425.5);
glColor3ub(255, 255, 255);
glVertex2f(679.5,552);
glColor3ub(255, 255, 255);
glVertex2f(709,540.5);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255, 255, 255);
glVertex2f(304.157,654.4);
glColor3ub(255, 255, 255);
glVertex2f(314.5,684);
glColor3ub(255, 255, 255);
glVertex2f(476.02,624.474);
glEnd();

//terakhir
glBegin(GL_TRIANGLES);
glColor3ub(16, 152, 247);
glVertex2f(136.333,184.333);
glColor3ub(16, 152, 247);
glVertex2f(183.242,167.745);
glColor3ub(16, 152, 247);
glVertex2f(233.482,441.578);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(16, 152, 247);
glVertex2f(382.333,94.712);
glColor3ub(16, 152, 247);
glVertex2f(523.286,70.579 );
glColor3ub(16, 152, 247);
glVertex2f(513.667,45);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(16, 152, 247);
glVertex2f(678.579,542.781);
glColor3ub(16, 152, 247);
glVertex2f(698.167,535.333);
glColor3ub(16, 152, 247);
glVertex2f(657.333,426.5);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(16, 152, 247);
glVertex2f(311.95 ,653.043);
glColor3ub(16, 152, 247);
glVertex2f(319.667,674.167);
glColor3ub(16, 152, 247);
glVertex2f(432.833,632.833);
glEnd();

glfwSwapBuffers(window);
glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
exit(EXIT_SUCCESS);
}

