#include "view.h"
#include <GL/gl.h>
#include <GL/glut.h>

ResultPageView::ResultPageView(unsigned score) : box(score) {}

void ResultPageView::render() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  box.draw();

  glutSwapBuffers();
}
