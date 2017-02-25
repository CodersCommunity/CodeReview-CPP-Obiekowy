#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog> // for dialogs: open file, save file, ...
#include <QStandardPaths> // home user folder
#include <QMessageBox> // msg boxes
#include <QFile> // files
#include <QTextStream> // text streams
#include <QDesktopServices> // open link in browser
#include <QFontDialog> // change font dialog
#include <QClipboard> // clipboard managment

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void onActionOpen();
  void onActionSave();
  void onActionSaveAs();
  void onActionExit();

  void onActionWrap(bool);
  void onActionAbout();
  void onActionWebsite();

  void onActionCopy();
  void onActionPaste();
  void onActionCut();

  void onActionFontChange();
  void onPlainTextModified();


private:
  Ui::MainWindow *ui;
  QString _opened_file_path;
  bool _text_is_modified;
  QClipboard* _clipboard;

  void savePlainTextToFile(QString path);
};

#endif // MAINWINDOW_H
