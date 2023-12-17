#include <QVBoxLayout>
#include <QLabel>

#include "MapWidget.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->layout()->addWidget(new MapWidget({}, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

