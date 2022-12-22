#include "deflectionpointdialog.h"
#include "ui_deflectionpointdialog.h"
#include<QMessageBox>
deflectionpointdialog::deflectionpointdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deflectionpointdialog)
{
    setWindowTitle(QString::fromLocal8Bit("选取基准点传感器"));
    setWindowIcon(QIcon(":/main/cqjtu.jpg"));
    setWindowFlag(Qt::WindowStaysOnTopHint);//窗口置顶
    ui->setupUi(this);
    BG.addButton(ui->radioButton,1);
    BG.addButton(ui->radioButton_2,2);
    BG.addButton(ui->radioButton_3,3);
    BG.addButton(ui->radioButton_4,4);
    BG.addButton(ui->radioButton_5,5);
    BG.addButton(ui->radioButton_6,6);
    BG.addButton(ui->radioButton_7,7);
    BG.addButton(ui->radioButton_8,8);
    BG.addButton(ui->radioButton_9,9);
    BG.addButton(ui->radioButton_10,10);
    BG.addButton(ui->radioButton_11,11);
    BG.addButton(ui->radioButton_12,12);
    BG.addButton(ui->radioButton_13,13);
    BG.addButton(ui->radioButton_14,14);
    connect(ui->pushButton,&QPushButton::clicked,this,[=]
    {
        int b=-1;
        b=BG.checkedId();
        if(b==-1)
        {
            QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未选取基准点传感器！"));
            return ;
        }
        emit sendsingals(b);
        QMessageBox::information(this,"good",QString::fromLocal8Bit("选取成功！"));
        this->hide();
    });
}

deflectionpointdialog::~deflectionpointdialog()
{
    delete ui;
}
