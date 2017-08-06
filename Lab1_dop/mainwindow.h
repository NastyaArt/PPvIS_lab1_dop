#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QList>
#include <QTimer>
#include <QMessageBox>
#include <QLabel>

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

    int numOfChBoxes;
    const int maxNum=20;
    int check=0;
    const int mtime=100;

    QLabel *label;
    QGroupBox *group;
    QGroupBox *group1;
    QGroupBox *groupChBoxes;
    QLineEdit *line;
    QPushButton *but1;
    QPushButton *but2;
    QList<QCheckBox*> *boxes;

    bool isNumber(QString s);

    QTimer timerCheck;
    QTimer timerUnCheck;

private slots:
    void TextChanged(QString str);
    void PushButton1();
    void PushButton2();

    void ToCheckBoxes();
    void ToUnCheckBoxes();

};

#endif // MAINWINDOW_H
