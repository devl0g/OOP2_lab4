#include "models/shapes/dot.hpp"
#include "models/shapes/line.hpp"
#include "models/shapes/oval.hpp"
#include "models/shapes/rectangle.hpp"
#include "utils/logger.hpp"
#include "ui/windows/myEditor.hpp"
#include <QApplication>
#include <memory>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  std::unique_ptr<MyEditor> myEditorInstance { std::make_unique<MyEditor>() };

  myEditorInstance->registerShape<DotShape>();
  myEditorInstance->registerShape<LineShape>();
  myEditorInstance->registerShape<OvalShape>();
  myEditorInstance->registerShape<RectangleShape>();

  myEditorInstance->show();

  Logger::info("window initiation");
  return app.exec();
}
