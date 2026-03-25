#include <GLUT/glut.h>
#include<stdio.h>
#include<math.h>
#include <vector>
#include <algorithm>

float tx = -400, ty = 0;

// THUẬT TOÁN SCANLINE FILL
void scanlineFill(std::vector<std::pair<float,float>> vertices, float r, float g, float b) {
    float ymin = vertices[0].second, ymax = vertices[0].second;
    for (auto& v : vertices) {
        if (v.second < ymin) ymin = v.second;
        if (v.second > ymax) ymax = v.second;
    }
    int n = vertices.size();
    glColor3f(r, g, b);
    for (float y = ymin; y <= ymax; y += 0.5f) {
        std::vector<float> intersections;
        for (int i = 0; i < n; i++) {
            float x1 = vertices[i].first,       y1 = vertices[i].second;
            float x2 = vertices[(i+1)%n].first, y2 = vertices[(i+1)%n].second;
            if ((y1 <= y && y < y2) || (y2 <= y && y < y1)) {
                float x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
                intersections.push_back(x);
            }
        }
        std::sort(intersections.begin(), intersections.end());
        for (int i = 0; i + 1 < (int)intersections.size(); i += 2) {
            glBegin(GL_LINES);
            glVertex2f(intersections[i],   y);
            glVertex2f(intersections[i+1], y);
            glEnd();
        }
    }
}

std::vector<std::pair<float,float>> makeEllipse(float rx, float ry, float cx, float cy) {
    std::vector<std::pair<float,float>> pts;
    for (int i = 0; i < 360; i += 2) {
        float angle = i * 3.1416f / 180.0f;
        pts.push_back({ cx + rx * cos(angle), cy + ry * sin(angle) });
    }
    return pts;
}
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
glBegin(GL_POLYGON);
glVertex2f(cx, cy);
for (int i = 0; i <= 360; i++)

{  
float angle = i * 3.1416 / 180;
float x = rx * cos(angle);
float y = ry * sin(angle);
glVertex2f((x + cx), (y + cy));

}

glEnd();

}

void myround(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{

glBegin(GL_POLYGON);
glVertex2f(cx, cy);
for (int i = 0; i <= 360; i++)

{

float angle = i * 3.1416 / 180;
float x = rx * cos(angle);
float y = ry * sin(angle);
glVertex2f((x + cx), (y + cy));

}

glEnd();

}

void init(void)
{

glClearColor(0, 0.9, 0.9, 0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 500, 0, 500);

}

// road

void road()
{
glColor3ub(0, 128, 0);
glBegin(GL_POLYGON);
glVertex2d(0, 0);
glVertex2d(500, 0);
glVertex2d(500, 75);
glVertex2d(0, 75);
glEnd();

// car road

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(0, 0);
glVertex2d(500, 0);
glVertex2d(500, 55);
glVertex2d(0, 55);
glEnd();
glColor3ub(105, 105, 105);
glBegin(GL_POLYGON);
glVertex2d(0, 0);
glVertex2d(500, 0);
glVertex2d(500, 50);
glVertex2d(0, 50);
glEnd();
glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(15, 20);
glVertex2d(50, 20);
glVertex2d(50, 30);
glVertex2d(15, 30);
glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(65, 20);
glVertex2d(100, 20);
glVertex2d(100, 30);
glVertex2d(65, 30);
glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(115, 20);
glVertex2d(150, 20);
glVertex2d(150, 30);
glVertex2d(115, 30);
glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(165, 20);
glVertex2d(200, 20);
glVertex2d(200, 30);
glVertex2d(165, 30);

glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(215, 20);
glVertex2d(250, 20);
glVertex2d(250, 30);
glVertex2d(215, 30);

glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(265, 20);
glVertex2d(300, 20);
glVertex2d(300, 30);
glVertex2d(265, 30);

glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(315, 20);
glVertex2d(350, 20);
glVertex2d(350, 30);
glVertex2d(315, 30);

glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(365, 20);
glVertex2d(400, 20);
glVertex2d(400, 30);
glVertex2d(365, 30);

glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(415, 20);
glVertex2d(450, 20);
glVertex2d(450, 30);
glVertex2d(415, 30);

glEnd();

glColor3ub(255, 255, 255);
glBegin(GL_POLYGON);
glVertex2d(465, 20);
glVertex2d(500, 20);
glVertex2d(500, 30);
glVertex2d(465, 30);

glEnd();

}

void sun() 
{
    auto sunShape = makeEllipse(20, 30, 450, 450);
    scanlineFill(sunShape, 1.0f, 1.0f, 0.0f);  // Scanline Fill màu vàng
}

void tree()
{

// tree

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(75, 180);
glVertex2d(85, 180);
glVertex2d(85, 350);
glVertex2d(75, 350);

glEnd();

glColor3ub(0, 128, 0);
circle(30, 40, 85, 370);
circle(20, 30, 90, 340);
circle(20, 30, 65, 395);

// forward tree

glColor3ub(0, 100, 0);
circle(40, 50, 45, 360);
glColor3ub(0, 100, 0);
circle(30, 30, 60, 330);
circle(20, 30, 30, 300);
circle(20, 30, 60, 300);

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(40, 180);
glVertex2d(50, 180);
glVertex2d(50, 296);
glVertex2d(60, 320);
glVertex2d(55, 326);
glVertex2d(50, 300);
glVertex2d(50, 350);
glVertex2d(45, 350);
glVertex2d(45, 310);

glEnd();

}

void little_tree()
{

// tree

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(65, 60);
glVertex2d(75, 60);
glVertex2d(75, 100);
glVertex2d(65, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 65, 110);
circle(15, 20, 75, 110);
circle(15, 20, 70, 130);

// 1st tree

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(0, 60);
glVertex2d(10, 60);
glVertex2d(10, 100);
glVertex2d(0, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 0, 110);
circle(15, 20, 10, 110);
circle(15, 20, 5, 130);

// 3rd tree

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(125, 60);
glVertex2d(135, 60);
glVertex2d(135, 100);
glVertex2d(125, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 125, 110);
circle(15, 20, 135, 110);
circle(15, 20, 130, 130);

// 4th tree

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(190, 60);
glVertex2d(200, 60);
glVertex2d(200, 100);
glVertex2d(190, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 190, 110);
circle(15, 20, 200, 110);
circle(15, 20, 195, 130);

// tree 5

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(300, 60);
glVertex2d(310, 60);
glVertex2d(310, 100);
glVertex2d(300, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 300, 110);
circle(15, 20, 310, 110);
circle(15, 20, 305, 130);

// tree 6

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(365, 60);
glVertex2d(375, 60);
glVertex2d(375, 100);
glVertex2d(365, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 365, 110);
circle(15, 20, 375, 110);
circle(15, 20, 370, 130);

// tree 7

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(425, 60);
glVertex2d(435, 60);
glVertex2d(435, 100);
glVertex2d(425, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 425, 110);
circle(15, 20, 435, 110);
circle(15, 20, 430, 130);

// tree 8

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(490, 60);
glVertex2d(500, 60);
glVertex2d(500, 100);
glVertex2d(490, 100);

glEnd();

glColor3ub(0, 100, 0);
circle(15, 20, 490, 110);
circle(15, 20, 500, 110);
circle(15, 20, 495, 130);

}

void clouds()
{

// 1st cloud

glColor3ub(255, 255, 255);
myround(20, 30, 90, 460);
myround(15, 20, 110, 460);
myround(15, 20, 70, 460);
// 2nd cloud

myround(20, 30, 185, 430);
myround(15, 20, 205, 430);
myround(15, 20, 165, 430);

}

void car() 
{

glPushMatrix();
glTranslatef(tx, ty, 0);
glColor3ub(255, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(410, 40);
glVertex2d(490, 40);
glVertex2d(485, 70);
glVertex2d(410, 70);

glEnd();

glColor3ub(255, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(420, 70);
glVertex2d(475, 70);
glVertex2d(465, 100);
glVertex2d(430, 100);

glEnd();

// car window

glColor3ub(220, 220, 220);
glBegin(GL_POLYGON);
glVertex2d(425, 70);
glVertex2d(445, 70);
glVertex2d(445, 90);
glVertex2d(430, 90);

glEnd();

// car window

glColor3ub(220, 220, 220);
glBegin(GL_POLYGON);
glVertex2d(450, 70);
glVertex2d(470, 70);
glVertex2d(465, 90);
glVertex2d(450, 90);

glEnd();

// car wheel

glColor3ub(0, 0, 0);
circle(10, 14, 435, 40);
circle(10, 14, 465, 40);
glColor3ub(245, 245, 245);
circle(6, 10, 435, 40);
circle(6, 10, 465, 40);
glPopMatrix();

}

void roadLight()
{

glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(80, 50);
glVertex2d(85, 50);
glVertex2d(85, 180);
glVertex2d(80, 180);

glEnd();

glBegin(GL_POLYGON);
glVertex2d(65, 150);
glVertex2d(100, 150);
glVertex2d(100, 155);
glVertex2d(65, 155);

glEnd();

glColor3ub(255, 255, 255);
circle(10, 15, 83, 180);

}

void display(void)
{

glClear(GL_COLOR_BUFFER_BIT);

//Sky Color

glColor3ub(30, 144, 255);
glBegin(GL_POLYGON);
glVertex2d(0, 0);
glVertex2d(500, 0);
glVertex2d(500, 500);
glVertex2d(0, 500);

glEnd();

//Ground Color

glColor3ub(0, 255, 0);
glBegin(GL_POLYGON);
glVertex2d(0, 0);
glVertex2d(500, 0);
glVertex2d(500, 180);
glVertex2d(0, 180);

glEnd();

// little tree

little_tree();
road();

// sun

sun();

// clouds

clouds();

// tree

tree();

// road light

roadLight();


// car

car();


glFlush();
glutSwapBuffers();

}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
        tx -= 10;
    else if (key == GLUT_KEY_RIGHT)
        tx += 10;
    else if (key == GLUT_KEY_UP)
        ty += 10;
    else if (key == GLUT_KEY_DOWN)
        ty -= 10;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(900, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Car");
init();
glutDisplayFunc(display);
glutSpecialFunc(specialKeys);
glutMainLoop();

return 0;

}