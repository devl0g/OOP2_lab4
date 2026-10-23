#include "myEditor.hpp"
#include "myEditor.hpp"
#include "../../utils/logger.hpp"
#include "../../config.hpp"
#include <QtWidgets/QMenuBar>
#include <string>

MyEditor myEditorInstance(nullptr);

MyEditor::MyEditor(QWidget* parent) noexcept : 
  QMainWindow(parent) {

  initUI();
}

MyEditor::~MyEditor() noexcept {
  Logger::info("window closed");
}

// UI

void MyEditor::initUI() noexcept {
  setWindowTitle(tr(WINDOW_TITLE));

  canvas = new ShapesCanvas(this);
  setCentralWidget(canvas);

  menuBar()->addMenu(tr("&Файл"));
  shapesMenu = menuBar()->addMenu(tr("&Об'єкти"));
  menuBar()->addMenu(tr("&Довідка"));

  shapesToolbar = new QToolBar("Об'єкти", this);
  addToolBar(shapesToolbar);

  connect(shapesMenu, &QMenu::triggered, this, &MyEditor::shapeSelected);
  connect(shapesToolbar, &QToolBar::actionTriggered, this, &MyEditor::shapeSelected);
}

void MyEditor::updateShapesMenu() noexcept {
  shapesMenu->clear();

  for (const auto& shape : registeredShapes) {
    auto action = shapesMenu->addAction(tr(shape->getShapeName()));
    action->setData(shape->getShapeID());
  }
}

void MyEditor::changeShape(uint8_t shapeID) {
  for (const auto& shape : registeredShapes) {
    if (shape->getShapeID() == shapeID) {
      selectedShapeID = shapeID;
      canvas->setDrawingShape(shape->createInstance());
      const auto newTitle = std::string("Обрано: ") + shape->getShapeName();
      setWindowTitle(tr(newTitle.c_str()));
    }
  }

  for (const auto& action : toolbarShapesButtons) {
    action.second->setChecked(false);
  }

  toolbarShapesButtons.at(shapeID)->setChecked(true);
}

// Slots

void MyEditor::shapeSelected(QAction* action) {
  const uint32_t data = action->data().toUInt();
  changeShape(data);
}
