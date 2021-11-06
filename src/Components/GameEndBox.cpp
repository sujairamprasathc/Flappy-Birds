#include "GameEndBox.h"
#include <GL/gl.h>
#include <SDL2/SDL_ttf.h>
#include <string>

GameEndBox::GameEndBox(unsigned score) { this->score = score; }

SDL_Texture *renderText(const std::string &message, const std::string &fontFile,
                        SDL_Color color, int fontSize, SDL_Renderer *renderer) {
  // Open the font
  TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
  if (font == nullptr) {
    return nullptr;
  }
  // We need to first render to a surface as that's what TTF_RenderText
  // returns, then load that surface into a texture
  SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
  if (surf == nullptr) {
    TTF_CloseFont(font);
    return nullptr;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
  if (texture == nullptr) {
  }
  // Clean up the surface and font
  SDL_FreeSurface(surf);
  TTF_CloseFont(font);
  return texture;
}

void GameEndBox::drawAlertBox() {
  const float red = 0.4;
  const float green = 1.0;
  const float blue = 1.0;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  glBegin(GL_POLYGON);
  glVertex2f(-0.4, -0.4);  // NOLINT
  glVertex2f(0.4, -0.4);   // NOLINT
  glVertex2f(0.4, 0.4);    // NOLINT
  glVertex2f(-0.4, 0.4);   // NOLINT
  glEnd();

  glColor4f(0.0, 0.0, 0.0, 0.0);  // NOLINT

  glBegin(GL_LINE_LOOP);
  glVertex2f(-0.35, -0.35);  // NOLINT
  glVertex2f(0.35, -0.35);   // NOLINT
  glVertex2f(0.35, 0.35);    // NOLINT
  glVertex2f(-0.35, 0.35);   // NOLINT
  glEnd();
  // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
}

void GameEndBox::draw() const {
  drawAlertBox();

  glColor4f(1.0, 0.4, 0.65, 1.0);                // NOLINT
  glRasterPos2f(-0.225, 0.05);                   // NOLINT
  const unsigned char gameOver[] = "GAME OVER";  // NOLINT

  glColor4f(0.6, 0.1, 0.1, 1.0);                   // NOLINT
  glRasterPos2f(-0.3, -0.05);                      // NOLINT
  const unsigned char yourScore[] = "YOUR SCORE";  // NOLINT

  std::string scoreText = std::to_string(score);
  for (int i = 0; i < scoreText.size(); i++) {
  }
}
