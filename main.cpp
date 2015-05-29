#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

float xc, yc;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_LEFT)  xc = xc-0.01;
    if (key == GLFW_KEY_RIGHT) xc = xc+0.01;
    if (key == GLFW_KEY_UP)    yc = yc+0.01;
    if (key == GLFW_KEY_DOWN)  yc = yc-0.01;
}

int main(void) {

    GLFWwindow* window;
    xc = yc = 0;

    /* Inicializa a biblioteca */
    if (!glfwInit()) return -1;

    /* Cria uma janela com contexto OpenGL */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);


    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Ativa o contexto OpenGL na janela */
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    glfwSwapInterval(1);

    /* Roda até que o usuário feche a janela */
    while (!glfwWindowShouldClose(window)) {

        /* Código de renderização OpenGL vai aqui */
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
            glColor3f(0, 0, 1); // Azul
            glVertex2f(xc-0.5f, yc-0.5f);
            glColor3f(0, 1, 0); // Azul
            glVertex2f(xc+0.0f, yc+0.5f);
            glColor3f(1, 0, 0); // Vermelho
            glVertex2f(xc+0.5f, yc-0.5f);
        glEnd();

        /* Troca o buffer de fundo com o buffer de exibição */
        glfwSwapBuffers(window);

        /* Captura e trata eventos do teclado */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
