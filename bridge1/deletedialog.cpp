#include "deletedialog.h"
#include "ui_deletedialog.h"
#include<QMessageBox>
#include<QDebug>
deletedialog::deletedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletedialog)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/main/cqjtu.jpg"));
    setWindowTitle(QString::fromLocal8Bit("删除"));
    ui->groupBox->hide();
    ui->groupBox_1->hide();
    ui->groupBox_2->hide();
    BG1.addButton(ui->yb1radioButton,1);
    BG1.addButton(ui->yb2radioButton,2);
    BG1.addButton(ui->yb3radioButton,3);
    BG1.addButton(ui->yb4radioButton,4);
    BG1.addButton(ui->yb5radioButton,5);
    BG1.addButton(ui->yb6radioButton,6);
    BG1.addButton(ui->yb7radioButton,7);
    BG1.addButton(ui->yb8radioButton,8);
    BG1.addButton(ui->yb9radioButton,9);
    BG1.addButton(ui->yb10radioButton,10);
    connect(ui->pushButton,&QPushButton::clicked,this,[=]  //应变检测点删除显示
    {
        int b=-1;
        b=BG1.checkedId();
        if(b!=-1)
            BG1.button(b)->setCheckable(true);
        ui->groupBox->show();
        ui->groupBox_1->hide();
        ui->groupBox_2->hide();

    });
    connect(ui->yb1pushButton,&QPushButton::clicked,this,&deletedialog::slotstrain);
    connect(ui->yb2pushButton,&QPushButton::clicked,this,&deletedialog::slotsstrainall);
    connect(ui->yb3pushButton,&QPushButton::clicked,this,[=] //应变取消
    {
        int b=-1;
        b=BG1.checkedId();
        if(b!=-1)
            BG1.button(b)->setCheckable(false);
        ui->groupBox->hide();

    });

    BG2.addButton(ui->nd1radioButton,1);
    BG2.addButton(ui->nd2radioButton,2);
    BG2.addButton(ui->nd3radioButton,3);
    BG2.addButton(ui->nd4radioButton,4);
    BG2.addButton(ui->nd5radioButton,5);
    BG2.addButton(ui->nd6radioButton,6);
    BG2.addButton(ui->nd7radioButton,7);
    BG2.addButton(ui->nd8radioButton,8);
    BG2.addButton(ui->nd9radioButton,9);
    BG2.addButton(ui->nd10radioButton,10);
    BG2.addButton(ui->nd11radioButton,11);
    BG2.addButton(ui->nd12radioButton,12);
    BG2.addButton(ui->nd13radioButton,13);
    BG2.addButton(ui->nd14radioButton,14);
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=]  //挠度监测点显示
    {
        int b=-1;
        b=BG2.checkedId();
        if(b!=-1)
            BG2.button(b)->setCheckable(true);
        ui->groupBox_1->show();
        ui->groupBox->hide();
        ui->groupBox_2->hide();
    });
    connect(ui->nd1pushButton,&QPushButton::clicked,this,&deletedialog::slotsdeflection);
    connect(ui->nd2pushButton,&QPushButton::clicked,this,&deletedialog::slotsdeflectionall);
    connect(ui->nd3pushButton,&QPushButton::clicked,this,[=]  //挠度取消
    {
        int b=-1;
        b=BG2.checkedId();
        if(b!=-1)
            BG2.button(b)->setCheckable(false);
        ui->groupBox_1->hide();
    });

    BG3.addButton(ui->wy1radioButton,1);
    BG3.addButton(ui->wy2radioButton,2);
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=]   //位移监测点显示
    {
        int b=-1;
        b=BG3.checkedId();
        if(b!=-1)
            BG3.button(b)->setCheckable(true);
        ui->groupBox_2->show();
        ui->groupBox->hide();
        ui->groupBox_1->hide();
    });
    connect(ui->wy1pushButton,&QPushButton::clicked,this,&deletedialog::slotsdisplace);
    connect(ui->wy2pushButton,&QPushButton::clicked,this,&deletedialog::slotsdisplaceall);
    connect(ui->wy3pushButton,&QPushButton::clicked,this,[=]  //取消
    {
        int b=-1;
        b=BG3.checkedId();
        if(b!=-1)
            BG3.button(b)->setCheckable(false);
        ui->groupBox_2->hide();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,this,[=]  //关闭按钮
    {
        ui->groupBox->hide();
        ui->groupBox_1->hide();
        ui->groupBox_2->hide();
        this->close();

    });
    setWindowFlag(Qt::WindowStaysOnTopHint);//窗口置顶

}

deletedialog::~deletedialog()
{
    delete ui;
}
void deletedialog::slotstrain()
{
    int a=-1;
    a=BG1.checkedId();
    if(a==-1)
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未选取监测点！"));
        return ;
    }

        emit sendstrain(a);

}
void deletedialog::slotsstrainall()
{
    int a=0;
    if(QMessageBox::Yes==QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("是否要删除所有应变传感器？"),QMessageBox::Yes,QMessageBox::No))
    {
        emit sendstrain(a);
    }
    else
    {
        return ;
    }
}
void deletedialog::slotsdeflection()
{
    int b=-1;
    b=this->BG2.checkedId();
    if(b==-1)
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未选取监测点！"));
        return ;
    }
    emit senddeflection(b);
}
void deletedialog::slotsdeflectionall()
{
    int a=0;
    if(QMessageBox::Yes==QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("是否要删除所有挠度传感器？"),QMessageBox::Yes,QMessageBox::No))
    {
        emit senddeflection(a);
    }
    else
    {
        return ;
    }
}
void deletedialog::slotsdisplace()
{
    int b=-1;
    b=this->BG3.checkedId();
    if(b==-1)
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未选取监测点！"));
        return ;
    }
    emit senddisplace(b);
}
void deletedialog::slotsdisplaceall()
{
    int a=0;
    if(QMessageBox::Yes==QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("是否要删除所有位移传感器？"),QMessageBox::Yes,QMessageBox::No))
    {
        emit senddisplace(a);
    }
    else
    {
        return ;
    }
}
void deletedialog::closeEvent(QCloseEvent *event)
{
    ui->groupBox->hide();
    ui->groupBox_1->hide();
    ui->groupBox_2->hide();
    this->close();

}
