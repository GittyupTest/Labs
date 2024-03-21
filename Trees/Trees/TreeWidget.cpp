#include <QGraphicsScene>

#include "TreeNodeGraphicsItem.h"

#include "TreeWidget.h"
#include "ui_TreeWidget.h"

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget),
    m_scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(m_scene);
    TreeNodeGraphicsItem *item = new TreeNodeGraphicsItem("Some not so long\ntwo-line text");
    QFont font = item->font();
    font.setPointSize(28);
    item->setFont(font);
    m_scene->addItem(item);

    item = new TreeNodeGraphicsItem("Some not so long\ntwo-line text");
    font = item->font();
    font.setPixelSize(28);
    item->setFont(font);
    item->setPos(500, 0);
    m_scene->addItem(item);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}

void TreeWidget::show()
{
    QWidget::show();
    _updateSceneRect();
}

void TreeWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    _updateSceneRect();
}

void TreeWidget::_updateSceneRect()
{
    m_scene->setSceneRect(0, 0,
//        ui->graphicsView->viewport()->width(),
//        ui->graphicsView->viewport()->height()
        qMax(int(m_scene->width()), ui->graphicsView->viewport()->width()),
        qMax(int(m_scene->height()), ui->graphicsView->viewport()->height())
    );
}






