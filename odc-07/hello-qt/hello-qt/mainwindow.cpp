#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ON_HIDE "Schowam sie"
#define ON_SHOW "Pokaze sie"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // ukrycie label oraz ustawienie odpowiedniego tekstu na buttonie
  ui->label_hello->setVisible(false);
  ui->button_clickme->setText(ON_SHOW);

  // polaczenie sygnalu "release" z odpowiednim slotem
  connect(ui->button_clickme, SIGNAL(released()), this, SLOT(onButtonClickmeReleased()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onButtonClickmeReleased()
{
  /* update buttona i labela na klikniecie */
  bool visible = ui->label_hello->isVisible();
  ui->button_clickme->setText(visible ? ON_SHOW : ON_HIDE);
  ui->label_hello->setVisible(!visible);
}
