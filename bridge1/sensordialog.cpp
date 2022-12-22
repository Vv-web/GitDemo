#include "sensordialog.h"
#include "ui_sensordialog.h"
#include<QIcon>
#include<QDebug>
#include<QMessageBox>
sensorDialog::sensorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sensorDialog)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("增加"));
    setWindowIcon(QIcon(":/main/cqjtu.jpg"));
    ui->yingbian->hide();
    ui->naodu->hide();
    ui->weiyi->hide();
    //将 radiobutton加入buttongroup
    BG1=new QButtonGroup();
    BG1->addButton(ui->radioButton1,1);
    BG1->addButton(ui->radioButton2,2);
    BG1->addButton(ui->radioButton3,3);
    BG1->addButton(ui->radioButton4,4);
    BG1->addButton(ui->radioButton5,5);
    BG1->addButton(ui->radioButton6,6);
    BG1->addButton(ui->radioButton7,7);
    BG1->addButton(ui->radioButton8,8);
    BG1->addButton(ui->radioButton9,9);
    BG1->addButton(ui->radioButton10,10);
    BG2=new QButtonGroup();
    BG2->addButton(ui->radioButtonz1,1);
    BG2->addButton(ui->radioButtonz2,2);
    BG2->addButton(ui->radioButtonz3,3);
    BG2->addButton(ui->radioButtonz4,4);
    BG2->addButton(ui->radioButtonz5,5);
    BG2->addButton(ui->radioButtonz6,6);
    BG2->addButton(ui->radioButtonz7,7);
    BG2->addButton(ui->radioButtonz8,8);
    BG2->addButton(ui->radioButtonz9,9);
    BG2->addButton(ui->radioButtonz10,10);
    BG2->addButton(ui->radioButtonz11,11);
    BG2->addButton(ui->radioButtonz12,12);
    BG2->addButton(ui->radioButtonz13,13);
    BG2->addButton(ui->radioButtonz14,14);
    BG3=new QButtonGroup();
    BG3->addButton(ui->radioButtonA,1);
    BG3->addButton(ui->radioButtonB,2);
    //关闭按钮
    connect(ui->pushButton_12,&QPushButton::clicked,this,[=]
    {
        ui->groupBox->hide();

        this->hide();

    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=]  //显示应变监测点添加
    {
        int a=-1;
        a=BG1->checkedId();
        if(a!=-1)
            BG1->button(a)->setCheckable(true);
        ui->groupBox->show();
        ui->yingbian->show();
        ui->naodu->hide();
        ui->weiyi->hide();
        ui->pushButton_12->hide();
    });
    connect(ui->pushButton,&QPushButton::clicked,this,[=]  //显示挠度监测点添加
    {
        int a=-1;
        a=BG2->checkedId();
        if(a!=-1)
            BG2->button(a)->setCheckable(true);
        ui->groupBox->show();
        ui->yingbian->hide();
        ui->naodu->show();
       ui->weiyi->hide();
        ui->pushButton_12->hide();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=]  //显示位移监测点添加
    {
        int a=-1;
        a=BG3->checkedId();
        if(a!=-1)
            BG3->button(a)->setCheckable(true);
        ui->groupBox->show();
        ui->weiyi->show();
        ui->yingbian->hide();
        ui->naodu->hide();
         ui->pushButton_12->hide();

    });
    connect(ui->pushButton_4,&QPushButton::clicked,this,&sensorDialog::slotstrain);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&sensorDialog::slotsdeflect);
    connect(ui->pushButton_10,&QPushButton::clicked,this,&sensorDialog::slotsdisplace);

    connect(ui->pushButton_5,&QPushButton::clicked,this,[=]//取消添加应变检测点
    {
         int b=-1;
         b=BG1->checkedId();
         if(b!=-1)
             BG1->button(b)->setCheckable(false);
         ui->lineEdit->clear();
         ui->lineEdit_2->clear();
         ui->lineEdit_3->clear();
         ui->lineEdit_4->clear();
         ui->lineEdit_5->clear();
         ui->lineEdit_6->clear();
         ui->lineEdit_7->clear();
        ui->yingbian->hide();
        ui->pushButton_12->show();
    });
    connect(ui->pushButton_9,&QPushButton::clicked,this,[=]  //挠度传感器取消按钮
    {
        int b=-1;
        b=BG2->checkedId();
        if(b!=-1)
            BG2->button(b)->setCheckable(false);
        ui->lineEdit_15->clear();
        ui->lineEdit_20->clear();
        ui->lineEdit_21->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_16->clear();
        ui->lineEdit_19->clear();
        ui->naodu->hide();
        ui->pushButton_12->show();
    });
    connect(ui->pushButton_11,&QPushButton::clicked,this,[=]  //位移传感器取消按钮
    {
        int b=-1;
        b=BG3->checkedId();
        if(b!=-1)
            BG3->button(b)->setCheckable(false);
       ui->lineEdit_18->clear();
       ui->lineEdit_26->clear();
       ui->lineEdit_23->clear();
       ui->lineEdit_25->clear();
       ui->lineEdit_27->clear();
       ui->lineEdit_28->clear();
       ui->lineEdit_24->clear();
       ui->lineEdit_22->clear();
        ui->weiyi->hide();
        ui->pushButton_12->show();
    });
    ui->lineEdit_24->setPlaceholderText(QString::fromLocal8Bit("此处输入单位"));
    setWindowFlag(Qt::WindowStaysOnTopHint);//窗口置顶
}

sensorDialog::~sensorDialog()
{
    delete ui;
}
void sensorDialog::slotstrain()
{
    double c;
    int a=-1;
    a=BG1->checkedId();
    if(a==-1)
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未选取监测点！"));
        return ;
    }  

    QString m,n;
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入传感器名字！"));
        return ;
    }
    if(ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入传感器编号！"));
        return ;
    }
    if(ui->lineEdit_7->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入中心波长！"));
        return ;
    }
    m=QString::number(a,10);
    qDebug()<<m<<"jiancedian";
    c=ui->lineEdit_7->text().toDouble();//中心波长
    ui->lineEdit_7->clear();
    s.setCencterwl(c);
    s.setSensorname(ui->lineEdit->text());//名字
     ui->lineEdit->clear();
    s.setManudate(ui->lineEdit_6->text());//生产日期
     ui->lineEdit_6->clear();
     n=QString("%1/%2").arg(ui->lineEdit_5->text()).arg(m);qDebug()<<n;
    s.setManufacture(n);//生产商
     ui->lineEdit_5->clear();
    s.setModel(ui->lineEdit_4->text());//型号
     ui->lineEdit_4->clear();
    s.setSpecification(ui->lineEdit_3->text());//规格
     ui->lineEdit_3->clear();
    s.setNumber(ui->lineEdit_2->text());//编号
     ui->lineEdit_2->clear();
    emit sendstrain(s);
    ui->yingbian->hide();
    ui->pushButton_12->show();
    BG1->button(a)->setCheckable(false);
}
void sensorDialog::slotsdeflect()
{
    int a=-1;
    a=BG2->checkedId();
    if(a==-1)
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未选取监测点！"));
        return ;
    }

    QString m,n;
    if(ui->lineEdit_15->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入传感器名字！"));
        return ;
    }
    if(ui->lineEdit_16->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入传感器编号！"));
        return ;
    }
    m=QString::number(a);
    d.setSensorname(ui->lineEdit_15->text()); ui->lineEdit_15->clear();
    d.setManudate(ui->lineEdit_20->text()); ui->lineEdit_20->clear();
    n=QString("%1/%2").arg(ui->lineEdit_21->text()).arg(m); ui->lineEdit_21->clear();
    d.setManufacture(n);
    d.setModel(ui->lineEdit_17->text());ui->lineEdit_17->clear();
    d.setNumber(ui->lineEdit_16->text());ui->lineEdit_16->clear();
    d.setSpecification(ui->lineEdit_19->text());ui->lineEdit_19->clear();
    emit sendDeflect(d);
    ui->naodu->hide();
    ui->pushButton_12->show();
    BG2->button(a)->setCheckable(false);
}
void sensorDialog::slotsdisplace()
{
    int a=-1;double c;
    a=BG3->checkedId();
    if(a==-1)
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未选取监测点！"));
        return ;
    }
    if(ui->lineEdit_18->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入传感器名字！"));
        return ;
    }
    if(ui->lineEdit_22->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入传感器编号！"));
        return ;
    }
    if(ui->lineEdit_28->text().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("未输入伸缩缝初始值！"));
        return ;
    }
    QString n,m;
    m=QString::number(a);
    p.setSensorname(ui->lineEdit_18->text());ui->lineEdit_18->clear();
    p.setManudate(ui->lineEdit_26->text());ui->lineEdit_26->clear();
    p.setModel(ui->lineEdit_23->text());ui->lineEdit_23->clear();
    p.setSpecification(ui->lineEdit_25->text());ui->lineEdit_25->clear();
    n=QString("%1/%2").arg(ui->lineEdit_27->text()).arg(m);ui->lineEdit_27->clear();
    p.setManufacture(n);
    c=ui->lineEdit_28->text().toDouble();ui->lineEdit_28->clear();
    p.setFirstmonit(c);
    p.setFirstunit(ui->lineEdit_24->text());ui->lineEdit_24->clear();
    p.setNumber(ui->lineEdit_22->text());ui->lineEdit_22->clear();
    emit sendDisplace(p);
    ui->weiyi->hide();
    ui->pushButton_12->show();
    BG3->button(a)->setCheckable(false);
}
void sensorDialog::closeEvent(QCloseEvent *event)
{
    ui->groupBox->hide();
    this->hide();

}
