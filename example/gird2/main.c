#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <stdio.h>

int r, g, b, a;
void color(int _r, int _g, int _b, int _a) {
	glColor4f(_r == 0 ? 0 : _r/255.0, _g == 0 ? 0 : _g/255.0, _b == 0 ? 0 : _b/255.0, _a == 0 ? 0 : _a/255.0);
}
void vertex(float x, float y) {
	glVertex3f(x, y, 0);
}

float modf(float v, float v2) {
	return v-((int)(v/v2))*v2;
}
void meshLine(int x, int y, int w, int h, float interval, float localY) {

	// 计算小网格颜色比例
	float ratio = localY == 0 ? 1 : 1-modf(localY/interval, 1.0);
	
	// TODO printf("Y=%f, Ratio=%f\r\n", localY, ratio);
	
	// 这里我tm懒得算到底咋写了，你随便改吧，间隔和布局都不对，但是你应该能看懂关键的东西
	int j = 0;
	for(int i = x; i<h; i++) {
		if(i%10 == 0) {
			if(j%5 == 0) {
				color(255, 255, 255, 255);
			} else {
				color(32+((int)(ratio*200)), 32+((int)(ratio*200)), 32+((int)(ratio*150)), 255);
			}
			j++;
			glBegin(GL_LINES);
			glPointSize(2);
			vertex(x, y+(i));
			vertex(x+w, y+(i));
			glEnd();
		}
	}
	j = 0;
	for(int i = y; i<w; i++) {
		if(i%10 == 0) {
			if(j%5 == 0) {
				color(255, 255, 255, 255);
			} else {
				color(32+((int)(ratio*200)), 32+((int)(ratio*200)), 32+((int)(ratio*150)), 255);
			}
			j++;
			glBegin(GL_LINES);
			glPointSize(2);
			vertex(x+(i), y);
			vertex(x+(i), y+h);
			glEnd();
		}
	}
	
}

int main(int argc, char** argv) {
	printf("Init glfw.");
	if(!glfwInit()) {
		printf("Bad init glfw.");
	}
	
	GLFWwindow*window = glfwCreateWindow(800, 600, "Mesh line", 0, 0);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glOrtho(0, 800, 600, 0, 0, 1);

	while(!glfwWindowShouldClose(window)) {
		float localY = modf(glfwGetTime()*3, 10);
		meshLine(200, 150, 400, 300, 10, localY);
		glfwSwapBuffers(window);
		glfwWaitEventsTimeout(0.01);
	}
	return 0;
}
