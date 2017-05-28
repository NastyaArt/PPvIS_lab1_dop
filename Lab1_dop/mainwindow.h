#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QErrorMessage>
#include <QList>
#include <windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int numOfChBoxes=1;

    QGroupBox *group;
    QGroupBox *group1;
    QGroupBox *groupChBoxes;
    QLineEdit *line;
    QPushButton *but1;
    QPushButton *but2;
    QList<QCheckBox*> *boxes;

    bool isNumber(QString s);

private slots:
    void TextChanged(QString str);
    void PushButton1();
    void PushButton2();
};

#endif // MAINWINDOW_H
