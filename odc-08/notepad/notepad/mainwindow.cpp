#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->actionOtw_rz, SIGNAL(triggered(bool)), this, SLOT(onActionOpen()));
  connect(ui->actionZapisz, SIGNAL(triggered(bool)), this, SLOT(onActionSave()));
  connect(ui->actionZapisz_jako, SIGNAL(triggered(bool)), this, SLOT(onActionSaveAs()));
  connect(ui->actionWyjd, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

  connect(ui->actionZawijanie_wierszy, SIGNAL(triggered(bool)), this, SLOT(onActionWrap(bool)));
  connect(ui->actionAutor, SIGNAL(triggered(bool)), this, SLOT(onActionAbout()));
  connect(ui->actionStrona, SIGNAL(triggered(bool)), this, SLOT(onActionWebsite()));
  connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(onActionExit()));
  connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(onPlainTextModified()));

  connect(ui->actionKopiuj, SIGNAL(triggered(bool)), this, SLOT(onActionCopy()));
  connect(ui->actionWytnij, SIGNAL(triggered(bool)), this, SLOT(onActionCut()));
  connect(ui->actionWklej, SIGNAL(triggered(bool)), this, SLOT(onActionPaste()));
  connect(ui->actionCzcionka, SIGNAL(triggered(bool)), this, SLOT(onActionFontChange()));

  _text_is_modified = false;
  _clipboard = qApp->clipboard();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onActionOpen()
{
  QString path = QFileDialog::getOpenFileName(this,
                                              tr("Wybierz plik do otwarcia"),
                                              QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
                                              "Pliki tekstowe (*.txt *.log)");
  if(path.isEmpty())
    return; // skip opening file

  _opened_file_path = path;

  // read file:
  QFile file(path);
  if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QMessageBox::critical(this,
                          tr("Błąd: nie można otworzyć pliku!"),
                          tr("Plik: ") + path + tr(" nie istnieje lub nie masz odpowiednich uprawnień do jego otwacia!"));
    return; // skip on error
  }

  QTextStream tstream(&file);
  ui->plainTextEdit->document()->setPlainText(tstream.readAll());

  file.close();
}

void MainWindow::onActionSave()
{
  if(_opened_file_path.isEmpty())
  {
    return onActionSaveAs();
  }

  savePlainTextToFile(_opened_file_path);
}

void MainWindow::onActionSaveAs()
{
  QString path = QFileDialog::getSaveFileName(this,
                                              tr("Zapisz plik..."),
                                              QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
                                              "Pliki tekstowe (*.txt *.log)");
  if(path.isEmpty())
    return; // skip writing file

  _opened_file_path = path; // update path

  // write file:
  QFile file(path);
  if(file.exists())
  {
    int response = QMessageBox::question(this,
                                         tr("Plik istnieje"),
                                         tr("Plik o podanej ścieżce istnieje. Kontynuwać?"),
                                         QMessageBox::StandardButton::Yes,
                                         QMessageBox::StandardButton::No);
    if(response != QMessageBox::StandardButton::Yes)
      return; // cancel saving file
  }
  savePlainTextToFile(path);
}

void MainWindow::onActionExit()
{
  if(!_text_is_modified)
    return;

  int response = QMessageBox::question(this,
                                       tr("Zamykanie programu..."),
                                       tr("Czy chcesz zapisać plik?"),
                                       QMessageBox::Yes,
                                       QMessageBox::No);
  if(response == QMessageBox::Yes)
    onActionSave();
}

void MainWindow::onActionCopy()
{
  _clipboard->setText(ui->plainTextEdit->textCursor().selectedText());
}

void MainWindow::onActionPaste()
{
  QString text = ui->plainTextEdit->toPlainText();
  int begin = ui->plainTextEdit->textCursor().position();
  text.insert(begin, _clipboard->text());
  ui->plainTextEdit->document()->setPlainText(text);
}

void MainWindow::onActionCut()
{
  QString text = ui->plainTextEdit->toPlainText();
  int begin = ui->plainTextEdit->textCursor().position();
  int end = ui->plainTextEdit->textCursor().selectionEnd();

  _clipboard->setText(ui->plainTextEdit->textCursor().selectedText());
  text.remove(begin, end - begin);
  ui->plainTextEdit->document()->setPlainText(text);
}

void MainWindow::onActionWrap(bool triggered)
{
  ui->plainTextEdit->setWordWrapMode(triggered
                                     ? QTextOption::WordWrap
                                     : QTextOption::NoWrap);
}

void MainWindow::onActionFontChange()
{
  bool ok;
  QFont font = QFontDialog::getFont(&ok, ui->plainTextEdit->font(), this);

  if(ok)
  {
    ui->plainTextEdit->setFont(font);
  }
}

void MainWindow::onActionAbout()
{
  QMessageBox::about(this,
                     tr("O programie (autorze)"),
                     tr("Demo notatnika napisane w celu ukazania możliwości QT.\n"
                        "Napisane dla forum Pasji Informatyki\n\n"
                        "Autor: shead"));
}

void MainWindow::onActionWebsite()
{
  QDesktopServices::openUrl(QUrl("https://github.com/CodersCommunity/CodeReview-CPP-Obiektowy"));
}

void MainWindow::onPlainTextModified()
{
  _text_is_modified = true;
}

void MainWindow::savePlainTextToFile(QString path)
{
  QFile file(path);
  if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
  {
    QMessageBox::critical(this,
                          tr("Błąd: Nie można zapisać pliku!"),
                          tr("Nie można zapisać pliku do podanej ścieżki. Upewnij się że masz odpowiednie uprawnienia."));
    return; // skip...
  }
  QTextStream tstream(&file);
  tstream << ui->plainTextEdit->toPlainText() << "\n";

  file.close();
  _text_is_modified = false;
}
