#include "mainwidget.h"
#include "ui_mainwidget.h"
#include<QPainter>

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("����������ݲɼ�ϵͳ"));
    connect(ui->pushButton,&QPushButton::clicked,this,[=]
    {
        hide();
        sub1.show();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=]
    {
        close();
    });
    //���ô���ͼ��
    setWindowIcon(QIcon(":/main/cqjtu.jpg"));

}

mainWidget::~mainWidget()
{
    delete ui;
}

void mainWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/main/2.jpg"));
}
