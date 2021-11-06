#include "model.h"
#include "view.h"

void Model::subscribe(View* view) { this->observerList.push_back(view); }

void Model::notify() const {
  for (const auto& view : this->observerList) {
    view->render();
  }
}
