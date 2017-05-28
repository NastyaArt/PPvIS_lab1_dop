#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    group = new QGroupBox();
    line = new QLineEdit;
    but1 = new QPushButton("Создать");
    but1->setDefault(true);
    but1->setEnabled(false);


   but2 = new QPushButton("Пуск");

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(line);
    lay->addWidget(but1);

    group->setLayout(lay);

    setCentralWidget(group);

    connect(line, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
    connect(but1, SIGNAL(clicked(bool)), this, SLOT(PushButton1()));
    connect(but2, SIGNAL(clicked(bool)), this, SLOT(PushButton2()));

}

bool MainWindow::isNumber(QString s){
    for (int a = 0; a < s.length(); a++){
    // Если в строке есть не цифровые символы, то это не число
         if (s[a] != 45){ // Проверка на знак минус
              if ((s[a] < 48) || (s[a] > 57))  return false;
         }

    }
    // Если в строке только цифровые символы значит это число
    return true;
}

void MainWindow::TextChanged(QString str)
{
    but1->setEnabled(!str.isEmpty());
}

void MainWindow::PushButton1()
{
    if (!isNumber(line->text())){
        line->clear();
        (new QErrorMessage(this))->showMessage("Введите число от 1 до 10!");
    }
    else{
        numOfChBoxes=line->text().toInt();
        if (numOfChBoxes>10 || numOfChBoxes<1)
            (new QErrorMessage(this))->showMessage("Введите число от 1 до 10!");
        else{
            line->clear();
            line->setEnabled(false);
            but1->setEnabled(false);
        }
    }


    groupChBoxes = new QGroupBox;
    QHBoxLayout *lay = new QHBoxLayout;
    boxes = new QList<QCheckBox*>;

    for (int i = 0; i < numOfChBoxes; ++i) {
        QCheckBox* checkbox = new QCheckBox();
        boxes->append(checkbox);
        lay->addWidget(boxes->at(i));
    }

    QVBoxLayout *lay1 = new QVBoxLayout;
    lay1->addLayout(lay);
    lay1->addWidget(but2);

    groupChBoxes->setLayout(lay1);
    setCentralWidget(groupChBoxes);
}

void MainWindow::PushButton2()
{
    for (int i = 0; i < numOfChBoxes; ++i) {
        boxes->at(i)->setChecked(true);
      //  Sleep(500);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
