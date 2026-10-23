#include "models/shapes/dot.hpp"
#include "models/shapes/line.hpp"
#include "models/shapes/oval.hpp"
#include "models/shapes/rectangle.hpp"
#include "utils/logger.hpp"
#include "ui/windows/myEditor.hpp"
#include <QApplication>

int argc = 0;
static QApplication app(argc, nullptr);

int main(int argc, char** argv) {
  myEditorInstance.registerShape<DotShape>();
  myEditorInstance.registerShape<LineShape>();
  myEditorInstance.registerShape<OvalShape>();
  myEditorInstance.registerShape<RectangleShape>();

  myEditorInstance.show();

  Logger::info("window initiation");
  return app.exec();
}
