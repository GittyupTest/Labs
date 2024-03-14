#include "TreeWidget.h"
#include "ui_TreeWidget.h"

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget)
{
    ui->setupUi(this);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}
