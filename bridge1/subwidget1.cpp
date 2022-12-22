#include "subwidget1.h"
#include "ui_subwidget1.h"
#include<QPainter>
#include<QFileDialog>
#include<QDebug>
#include<QFile>
#include<QMessageBox>
#include<QString>
subwidget1::subwidget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget1)
{
    ui->setupUi(this);
    //���ô���ͼ��
    setWindowIcon(QIcon(":/main/cqjtu.jpg"));
    //����14���Ӷȼ���
    for(int i=0;i<14;i++)
    {
        DeflectionPoint de;
        defl.push_back(de);
    }
    //����2��λ�Ƽ���
    for(int i=0;i<2;i++)
    {
        DisplacementPoint d;
        disp.push_back(d);
    }
    //����10��Ӧ�����
    for(int i=0;i<10;i++)
    {
        StrainPoint s;
        stra.push_back(s);
    }
    //�޸�tablewidget��һ�п��
    ui->tableWidget->setColumnWidth(0,140);
    setWindowTitle(QString::fromLocal8Bit("����������ݲɼ�ϵͳ"));
    //��ȡ�������ļ��е�����
   this->getStrainfileDate();
    this->getDeflectionfileDate();
    this->getDisplacementfileDate();
    //���ݱ��水ť
    connect(ui->pushButton_5,&QPushButton::clicked,this,[=]
    {
        l=1;
        //Ӧ�����д���ļ�
        QFile fileYb1("./StrainsensorDate.txt"); //Ӧ�䴫����������Ϣд���ļ�
        fileYb1.open(QIODevice::WriteOnly);
        QString all;
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        for(int x=1;i!=stra.end();i++,x++)
        {
            if(!i->s.getSensorname().isEmpty())   //���δ���ô������ļ����򲻻�д�봫�������ݣ���x���ֱ�д������ĸ�����Ĵ�����
            {
             QString c=QString("%1/%2").arg(x).arg(i->s.getSensorname());
             QString n=QString::number(i->s.getCencterwl(),10,5);
            all=QString("%1 %2 %3 %4 %5 %6 %7\n").arg(c).arg(i->s.getNumber()).arg(i->s.getModel()).arg(n).arg(i->s.getSpecification()).arg(i->s.getManudate()).arg(i->s.getManufacture());
            fileYb1.write(all.toUtf8());
            }
        }
        fileYb1.close();
        QFile fileYb2("./StrainpointDate.txt");   //Ӧ�䴫�����������д���ļ�
        fileYb2.open(QIODevice::WriteOnly);
        i=stra.begin();
        QList<monitroing>::iterator j;
        for(;i!=stra.end();i++)
        {
            j=i->s.monitr.begin();
            for(;j!=i->s.monitr.end();j++)  //д��һ������ļ������
            {
                QString m,n;
                m=QString::number(j->getMonitruNum(),10,5);
                n=QString::number(j->getFinalData(),10,5);
                all=QString("%1 %2 %3 %4 %5\n").arg(j->getDate()).arg(j->getTime()).arg(m).arg(n).arg(j->getFinaldateUnit());
                fileYb2.write(all.toUtf8());
            }
            if((i+1)!=stra.end())   //д��һ������ļ�����ݺ���next����һ������ָ���
            {
                QString k=QString("next\n");
                fileYb2.write(k.toUtf8());
            }
        }
        fileYb2.close();
        //�Ӷȼ���д���ļ�
        QFile fileNd1("./DeflectionsensorDate.txt");
        fileNd1.open(QIODevice::WriteOnly);
        QList<DeflectionPoint>::iterator y;
        y=defl.begin();
        for(int x=1;y!=defl.end();y++,x++)
        {
            if(!y->de.getSensorname().isEmpty())//���δ���ô������ļ����򲻻�д�봫�������ݣ���x���ֱ�д������ĸ�����Ĵ�����
            {
                QString c=QString("%1/%2").arg(x).arg(y->de.getSensorname());
                all=QString("%1 %2 %3 %4 %5 %6\n").arg(c).arg(y->de.getNumber()).arg(y->de.getModel()).arg(y->de.getSpecification()).arg(y->de.getManudate()).arg(y->de.getManufacture());
                fileNd1.write(all.toUtf8());
            }
        }
        fileNd1.close();
        QFile fileNd2("./DeflectionpointDate.txt");
        fileNd2.open(QIODevice::WriteOnly);
        y=defl.begin();
        for(;y!=defl.end();y++)
        {
            j=y->de.monitr.begin();
            for(;j!=y->de.monitr.end();j++)   //д��һ������ļ������
            {
                QString m,n;
                m=QString::number(j->getMonitruNum(),10,2);
                n=QString::number(j->getFinalData(),10,2);
                all=QString("%1 %2 %3 %4 %5 %6\n").arg(j->getDate()).arg(j->getTime()).arg(m).arg(j->getUnit()).arg(n).arg(j->getFinaldateUnit());
                fileNd2.write(all.toUtf8());
            }
            if((y+1)!=defl.end())   //д��һ������ļ�����ݺ���next����һ������ָ���
            {
                QString k=QString("next\n");
                fileNd2.write(k.toUtf8());
            }
        }
        fileNd2.close();
        //λ�Ƽ���д�ļ�
        QFile fileWy1("./DisplacementsensorDate.txt");
        fileWy1.open(QIODevice::WriteOnly);
        QList<DisplacementPoint>::iterator u;
        u=disp.begin();
        for(int x=1;u!=disp.end();u++,x++)
        {
            if(!u->d.getSensorname().isEmpty())   //���δ���ô������ļ����򲻻�д�봫�������ݣ���x���ֱ�д������ĸ�����Ĵ�����
            {
             QString c=QString("%1/%2").arg(x).arg(u->d.getSensorname());
             QString n=QString::number(u->d.getFirstmonit(),10,3);
            all=QString("%1 %2 %3 %4 %5 %6 %7 %8\n").arg(c).arg(u->d.getNumber()).arg(u->d.getModel()).arg(n).arg(u->d.getFirstunit()).arg(u->d.getSpecification()).arg(u->d.getManudate()).arg(u->d.getManufacture());
            fileWy1.write(all.toUtf8());
            }
        }
        fileWy1.close();
        QFile fileWy2("./DisplacementpointDate.txt");
        fileWy2.open(QIODevice::WriteOnly);
        u=disp.begin();
        for(;u!=disp.end();u++)
        {
            j=u->d.monitr.begin();
            for(;j!=u->d.monitr.end();j++)   //д��һ������ļ������
            {
                QString m,n;
                m=QString::number(j->getMonitruNum(),10,3);
                n=QString::number(j->getFinalData(),10,3);
                all=QString("%1 %2 %3 %4 %5 %6\n").arg(j->getDate()).arg(j->getTime()).arg(m).arg(j->getUnit()).arg(n).arg(j->getFinaldateUnit());
                fileWy2.write(all.toUtf8());
            }
            if((u+1)!=disp.end())   //д��һ������ļ�����ݺ���next����һ������ָ���
            {
                QString k=QString("next\n");
                fileWy2.write(k.toUtf8());
            }
        }
        fileWy2.close();
        QMessageBox::information(this,QString::fromLocal8Bit("���ݱ���ɹ�"),QString::fromLocal8Bit("���ݱ���ɹ�!!!"));
    });

    //��ȡӦ��������ݰ�ť
    connect(ui->pushButton_8,&QPushButton::clicked,this,&subwidget1::getStrainFromFile);
    //��ȡ�Ӷȼ������ݰ�ť
    connect(ui->pushButton_13,&QPushButton::clicked,this,&subwidget1::getDeflectionFromFile);
    //��ȡλ�Ƽ������ݰ�ť
    connect(ui->pushButton_14,&QPushButton::clicked,this,&subwidget1::getDisplacementFromFile);
    //�������ݲ�ѯ��ť����
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->groupBox_3 ->hide();
    ui->groupBox_4->hide();
    ui->tableWidget->hide();
    ui->tableWidget_2->hide();
    ui->tableWidget_3->hide();

    //��ʾ���������ݲ�ѯ�İ�ť
    connect(ui->pushButton_6,&QPushButton::clicked,this,[=]
    {
        ui->groupBox_3->show();
        ui->pushButton_9->show();
        ui->pushButton_10->show();
        ui->pushButton_11->show();
        ui->pushButton_12->show();
        ui->groupBox_4->show();
        ui->groupBox_5->hide();
        ui->groupBox_9->hide();
        ui->groupBox_8->hide();
        ui->groupBox_7->hide();

    });
    //�Ա��ť�Ĳ���,��ʾ�������ݱ��
    //Ӧ�����
    connect(ui->pushButton_9,&QPushButton::clicked,this,[=]
    {
        QString m,c;//m������ƴ�Ӽ�����ݵ������պ�ʱ�䣬c�Ǽ��ֵdoubleתΪQString����ڱ��
        int k=0,n=0;//k��������ÿ������ļ������������ڼ�����ÿ����һ��ѭ����n++����ʾ��񴴽�һ��
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        QList<monitroing>::iterator j;
        double y;
        j=i->s.monitr.begin();
        while((j+k)!=stra.begin()->s.monitr.end()) //�����������Ϊ�գ��򲻽���ѭ�������������ݣ������ѭ��������ڱ����
        {
            n++;
            ui->tableWidget->setRowCount(n);//����񴴽���
            m=QString("%1 %2").arg((j+k)->getDate(),(j+k)->getTime());qDebug()<<m;
            ui->tableWidget->setItem(n-1,0,new QTableWidgetItem(m));
            //��һ���������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,1,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,2,new QTableWidgetItem(c));qDebug()<<"okok";
            i++;qDebug()<<"okok";
            j=i->s.monitr.begin();qDebug()<<"okok";
            //�ڶ����������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);qDebug()<<"okok";
            ui->tableWidget->setItem(n-1,3,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,4,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //�������������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,5,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,6,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //���ĸ��������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,7,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,8,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //������������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,9,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,10,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //�������������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,11,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,12,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //���߸��������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,13,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,14,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //�ڰ˸��������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,15,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,16,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //�ھŸ��������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,17,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,18,new QTableWidgetItem(c));
            i++;
            j=i->s.monitr.begin();
            //��ʮ���������ݼ��ϵ�Ԫ��
            c=QString::number((j+k)->getMonitruNum(),10,5);
            ui->tableWidget->setItem(n-1,19,new QTableWidgetItem(c));qDebug()<<c;
            y=1000*((j+k)->getMonitruNum()-i->s.getCencterwl())+8*0.5;
            (j+k)->setFinalData(y);
            c=QString::number((j+k)->getFinalData(),10,5);qDebug()<<c;
            ui->tableWidget->setItem(n-1,20,new QTableWidgetItem(c));
            k++;
            i=stra.begin();
            j=i->s.monitr.begin();
        }
        ui->tableWidget_2->hide();qDebug()<<"1";
        ui->tableWidget_3->hide();qDebug()<<"2";
        ui->tableWidget->show();qDebug()<<"3";
    });
    //�Ӷȼ���
    connect(ui->pushButton_10,&QPushButton::clicked,this,[=]  //ѡȡ��׼�㴫�����Ի�����ʾ
    {
        deflectionDlg.show();
    });
    connect(&deflectionDlg,&deflectionpointdialog::sendsingals,this,&subwidget1::getDeflectiondialog);
    //λ�Ƽ���
    connect(ui->pushButton_11,&QPushButton::clicked,this,[=]
    {

        QString c;//c�Ǽ��ֵdoubleתΪQString����ڱ��
        int k=0,g=0,n=0;//k,g��������ÿ������ļ������������ڼ�����ÿ����һ��ѭ����n++����ʾ��񴴽�һ��
        int x=1;
        double y;
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        QList<monitroing>::iterator j;
        j=i->d.monitr.begin();
        while((j+k)!=disp.begin()->d.monitr.end())
        {
            n++;
            i=disp.begin();
            j=i->d.monitr.begin();
            ui->tableWidget_3->setRowCount(n);//����񴴽���
            if(x==1) //x=1 �����һ�������������� x=0����ڶ���������������
           {
             ui->tableWidget_3->setItem(n-1,0,new QTableWidgetItem((j+k)->getDate()));
             ui->tableWidget_3->setItem(n-1,1,new QTableWidgetItem((j+k)->getTime()));
             ui->tableWidget_3->setItem(n-1,2,new QTableWidgetItem(i->d.getNumber()));
             c=QString::number((j+k)->getMonitruNum(),10,3);
             ui->tableWidget_3->setItem(n-1,3,new QTableWidgetItem(c));
             ui->tableWidget_3->setItem(n-1,4,new QTableWidgetItem((j+k)->getUnit()));
             y=(j+k)->getMonitruNum()-i->d.getFirstmonit();
             (j+k)->setFinalData(y);
             c=QString::number((j+k)->getFinalData(),10,3);qDebug()<<c;
             ui->tableWidget_3->setItem(n-1,5,new QTableWidgetItem(c));
             ui->tableWidget_3->setItem(n-1,6,new QTableWidgetItem((j+k)->getFinaldateUnit()));
             k++;
             x=0;
           }
            else
            {
                i++;
                j=i->d.monitr.begin();
                ui->tableWidget_3->setItem(n-1,0,new QTableWidgetItem((j+g)->getDate()));
                ui->tableWidget_3->setItem(n-1,1,new QTableWidgetItem((j+g)->getTime()));
                ui->tableWidget_3->setItem(n-1,2,new QTableWidgetItem(i->d.getNumber()));
                c=QString::number((j+g)->getMonitruNum(),10,3);
                ui->tableWidget_3->setItem(n-1,3,new QTableWidgetItem(c));
                y=(j+g)->getMonitruNum()-i->d.getFirstmonit();
                (j+g)->setFinalData(y);
                ui->tableWidget_3->setItem(n-1,4,new QTableWidgetItem((j+g)->getUnit()));
                c=QString::number((j+g)->getFinalData(),10,3);qDebug()<<c;
                ui->tableWidget_3->setItem(n-1,5,new QTableWidgetItem(c));
                ui->tableWidget_3->setItem(n-1,6,new QTableWidgetItem((j+g)->getFinaldateUnit()));
                g++;
                x=1;
            }
        }
        ui->tableWidget->hide();qDebug()<<"3";
        ui->tableWidget_2->hide();qDebug()<<"3";
        ui->tableWidget_3->show();qDebug()<<"3";
    });
    //�رռ������ݱ��
    connect(ui->pushButton_12,&QPushButton::clicked,this,[=]
    {
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->groupBox_3 ->hide();
        ui->tableWidget->hide();
        ui->tableWidget_2->hide();
        ui->tableWidget_3->hide();
    });
    //ʹ�ñ�����ݲ����޸�
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);


    //���������Ӳ���
    connect(ui->pushButton,&QPushButton::clicked,this,[=]
    {
       sensdialog.show();
    });
    connect(&sensdialog,&sensorDialog::sendstrain,this,&subwidget1::getStrainsensor);//Ӧ�䴫�������Ӳ���
    connect(&sensdialog,&sensorDialog::sendDeflect,this,&subwidget1::getDeflectionsensor);//�Ӷȴ��������Ӳ���
    connect(&sensdialog,&sensorDialog::sendDisplace,this,&subwidget1::getDisplacesensor);//λ�ƴ��������Ӳ���


    //�������޸Ĳ���
    //���ش������޸Ľ���
    ui->groupBox_5->hide();
    //����޸İ�ť ��ʾ�������޸Ľ���
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=]
    {
        ui->groupBox_5->show();
        ui->groupBox_3->hide();
        ui->groupBox_4->hide();
        ui->groupBox_9->hide();
        ui->groupBox_3->hide();
        ui->groupBox_4->hide();
    });
    connect(ui->pushButton_18,&QPushButton::clicked,this,[=]
    {
        ui->groupBox_5->hide();
    });
    //���ش������޸Ĺ����е�Ӧ��groupbox���Ӷ�groupbox��λ��groupbox
    ui->groupBox_6->hide();
    ui->groupBox_7->hide();
    ui->groupBox_8->hide();
    //ѡ��Ҫ�޸ĵĴ��������ͺ�  ��ʾgroupbox
    connect(ui->pushButton_15,&QPushButton::clicked,this,[=]
    {
        int b=-1;
        b=BGyb1.checkedId();
        if(b!=-1)
            BGyb1.button(b)->setCheckable(true);
        ui->groupBox_6->show();
        ui->pushButton_18->hide();
        ui->groupBox_7->hide();
        ui->groupBox_8->hide();
    });


    //Ӧ�䴫�����޸�
    BGyb1.addButton(ui->radioButtonyb1,1);
    BGyb1.addButton(ui->radioButtonyb2,2);
    BGyb1.addButton(ui->radioButtonyb3,3);
    BGyb1.addButton(ui->radioButtonyb4,4);
    BGyb1.addButton(ui->radioButtonyb5,5);
    BGyb1.addButton(ui->radioButtonyb6,6);
    BGyb1.addButton(ui->radioButtonyb7,7);
    BGyb1.addButton(ui->radioButtonyb8,8);
    BGyb1.addButton(ui->radioButtonyb9,9);
    BGyb1.addButton(ui->radioButtonyb10,10);
    ui->lineEdit_8->setEnabled(false);
    ui->lineEdit_9->setEnabled(false);
    ui->lineEdit_10->setEnabled(false);
    ui->lineEdit_11->setEnabled(false);
    ui->lineEdit_12->setEnabled(false);
    ui->lineEdit_13->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_14->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->lineEdit_2->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->lineEdit_4->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->lineEdit_7->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->lineEdit_3->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->lineEdit_6->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->lineEdit_5->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    connect(ui->pushButton_19,&QPushButton::clicked,this,[=]    //������ť
    {

        a=BGyb1.checkedId();
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        QString s;
        i=stra.begin();
        a--;
        i=i+a;
        if(i->s.getSensorname().isEmpty())
        {
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü���δ���ô�����������"));
            q=-1;
            return ;
        }
        ui->lineEdit_8->setText(i->s.getSensorname());
        ui->lineEdit_9->setText(i->s.getNumber());
        ui->lineEdit_10->setText(i->s.getModel());
        s=QString::number(i->s.getCencterwl(),10,5);
        if(s!=QString("0.00000"))
        ui->lineEdit_11->setText(s);
        ui->lineEdit_12->setText(i->s.getSpecification());
        ui->lineEdit_13->setText(i->s.getManudate());
        ui->lineEdit->setText(i->s.getManufacture());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����ɹ�������"));

    });
    connect(ui->pushButton_20,&QPushButton::clicked,this,[=]   //ȷ���޸�����
    {
       if(a==-1)
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
           return ;
       }
       QList<StrainPoint>::iterator i;
       i=stra.begin();
       i=i+a;
       if(!ui->lineEdit_14->text().isEmpty())
       {
           i->s.setSensorname(ui->lineEdit_14->text());
           ui->lineEdit_14->clear();
           ui->lineEdit_8->setText(i->s.getSensorname());
           QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
       }
       else
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
           return ;
       }

    });
    connect(ui->pushButton_21,&QPushButton::clicked,this,[=]  //ȷ���޸ı��
    {
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+a;
        if(!ui->lineEdit_2->text().isEmpty())
        {
        i->s.setNumber(ui->lineEdit_2->text());
        ui->lineEdit_2->clear();
        ui->lineEdit_9->setText(i->s.getNumber());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->pushButton_22,&QPushButton::clicked,this,[=]   //ȷ���޸��ͺ�
    {
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+a;
        if(!ui->lineEdit_4->text().isEmpty())
        {
        i->s.setModel(ui->lineEdit_4->text());
        ui->lineEdit_4->clear();
        ui->lineEdit_10->setText(i->s.getModel());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->pushButton_23,&QPushButton::clicked,this,[=]   //ȷ���޸����Ĳ���
    {
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+a;
        double c;
        QString s;
        if(!ui->lineEdit_7->text().isEmpty())
        {
        c=ui->lineEdit_7->text().toDouble();
        i->s.setCencterwl(c);
        ui->lineEdit_11->setText(ui->lineEdit_7->text());
        ui->lineEdit_7->clear();
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->pushButton_24,&QPushButton::clicked,this,[=]   //ȷ���޸Ĺ��
    {
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+a;
        if(!ui->lineEdit_3->text().isEmpty())
        {
        i->s.setSpecification(ui->lineEdit_3->text());
        ui->lineEdit_3->clear();
        ui->lineEdit_12->setText(i->s.getSpecification());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->pushButton_25,&QPushButton::clicked,this,[=]   //ȷ���޸���������
    {
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+a;
        if(!ui->lineEdit_6->text().isEmpty())
        {
        i->s.setManudate(ui->lineEdit_6->text());
        ui->lineEdit_6->clear();
        ui->lineEdit_13->setText(i->s.getManudate());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->pushButton_26,&QPushButton::clicked,this,[=]   //ȷ���޸�������
    {
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+a;
        if(!ui->lineEdit_5->text().isEmpty())
        {
        i->s.setManufacture(ui->lineEdit_5->text());
        ui->lineEdit_5->clear();
        ui->lineEdit->setText(i->s.getManufacture());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->pushButton_27,&QPushButton::clicked,this,[=]    //ȷ���޸�ȫ��
    {
        if(a==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ���������������㴫���������ڣ�����"));
            return ;
        }
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+a;
        if(!ui->lineEdit_14->text().isEmpty())    //�޸�����
        {
            i->s.setSensorname(ui->lineEdit_14->text());
            ui->lineEdit_14->clear();
            ui->lineEdit_8->setText(i->s.getSensorname());
        }
        if(!ui->lineEdit_2->text().isEmpty())     //�޸ı��
        {
        i->s.setNumber(ui->lineEdit_2->text());
        ui->lineEdit_2->clear();
        ui->lineEdit_9->setText(i->s.getNumber());
        }
        if(!ui->lineEdit_4->text().isEmpty())    //�޸��ͺ�
        {
        i->s.setModel(ui->lineEdit_4->text());
        ui->lineEdit_4->clear();
        ui->lineEdit_10->setText(i->s.getModel());
        }
        double c;
        QString s;
        if(!ui->lineEdit_7->text().isEmpty())    //�޸����Ĳ���
        {
        c=ui->lineEdit_7->text().toDouble();
        i->s.setCencterwl(c);
        ui->lineEdit_11->setText(ui->lineEdit_7->text());
        ui->lineEdit_7->clear();
        }
        if(!ui->lineEdit_3->text().isEmpty())    //�޸Ĺ��
        {
        i->s.setSpecification(ui->lineEdit_3->text());
        ui->lineEdit_3->clear();
        ui->lineEdit_12->setText(i->s.getSpecification());
        }
        if(!ui->lineEdit_6->text().isEmpty())  //�޸���������
        {
        i->s.setManudate(ui->lineEdit_6->text());
        ui->lineEdit_6->clear();
        ui->lineEdit_13->setText(i->s.getManudate());
        }
        if(!ui->lineEdit_5->text().isEmpty())    //�޸�������
        {
        i->s.setManufacture(ui->lineEdit_5->text());
        ui->lineEdit_5->clear();
        ui->lineEdit->setText(i->s.getManufacture());
        }
    QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ���������δ����Ĳ����޸ģ�"));

    });
    connect(ui->pushButton_28,&QPushButton::clicked,this,[=]    //ȡ����ť
    {
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_12->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit->clear();
        ui->lineEdit_14->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_5->clear();
        int b=-1;
        b=BGyb1.checkedId();
        if(b!=-1)
            BGyb1.button(b)->setCheckable(false);
        a=-1;
        ui->groupBox_6->hide();
        ui->pushButton_18->show();
    });


    //�Ӷȴ������޸�
    BGnd1.addButton(ui->radioButtonND1,1);
    BGnd1.addButton(ui->radioButtonND2,2);
    BGnd1.addButton(ui->radioButtonND3,3);
    BGnd1.addButton(ui->radioButtonND4,4);
    BGnd1.addButton(ui->radioButtonND5,5);
    BGnd1.addButton(ui->radioButtonND6,6);
    BGnd1.addButton(ui->radioButtonND7,7);
    BGnd1.addButton(ui->radioButtonND8,8);
    BGnd1.addButton(ui->radioButtonND9,9);
    BGnd1.addButton(ui->radioButtonND10,10);
    BGnd1.addButton(ui->radioButtonND11,11);
    BGnd1.addButton(ui->radioButtonND12,12);
    BGnd1.addButton(ui->radioButtonND13,13);
    BGnd1.addButton(ui->radioButtonND14,14);
    //ѡ��Ҫ�޸ĵĴ��������ͺ�  ��ʾgroupbox
    connect(ui->pushButton_16,&QPushButton::clicked,this,[=]
    {
        int b=-1;
        b=BGnd1.checkedId();
        if(b!=-1)
            BGnd1.button(b)->setCheckable(true);
        ui->groupBox_7->show();
        ui->groupBox_6->hide();
        ui->groupBox_8->hide();
        ui->pushButton_18->hide();
    });
    ui->ND1lineEdit->setEnabled(false);
    ui->ND3lineEdit->setEnabled(false);
    ui->ND5lineEdit->setEnabled(false);
    ui->ND7lineEdit->setEnabled(false);
    ui->ND9lineEdit->setEnabled(false);
    ui->ND11lineEdit->setEnabled(false);
    ui->ND2lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->ND4lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->ND6lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->ND8lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->ND10lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    ui->ND12lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));    //��������ʾ
    connect(ui->ND1pushButton,&QPushButton::clicked,this,[=]    //������ť
    {
        q=BGnd1.checkedId();
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        q--;
        i=i+q;
        if(i->de.getSensorname().isEmpty())
        {
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü���δ���ô�����������"));
            q=-1;
            return ;
        }
        ui->ND1lineEdit->setText(i->de.getSensorname());
        ui->ND3lineEdit->setText(i->de.getNumber());
        ui->ND5lineEdit->setText(i->de.getModel());
        ui->ND7lineEdit->setText(i->de.getSpecification());
        ui->ND9lineEdit->setText(i->de.getManudate());
        ui->ND11lineEdit->setText(i->de.getManufacture());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����ɹ�������"));
    });
    connect(ui->ND2pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸�����
    {
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+q;
        if(!ui->ND2lineEdit->text().isEmpty())
        {
            i->de.setSensorname(ui->ND2lineEdit->text());
            ui->ND2lineEdit->clear();
            ui->ND1lineEdit->setText(i->de.getSensorname());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->ND3pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸ı��
    {
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+q;
        if(!ui->ND4lineEdit->text().isEmpty())
        {
            i->de.setNumber(ui->ND4lineEdit->text());
            ui->ND4lineEdit->clear();
            ui->ND3lineEdit->setText(i->de.getNumber());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->ND4pushButton,&QPushButton::clicked,this,[=]    //ȷ���޸��ͺ�
    {
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+q;
        if(!ui->ND6lineEdit->text().isEmpty())
        {
            i->de.setModel(ui->ND6lineEdit->text());
            ui->ND6lineEdit->clear();
            ui->ND5lineEdit->setText(i->de.getModel());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->ND5pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸Ĺ��
    {
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+q;
        if(!ui->ND8lineEdit->text().isEmpty())
        {
            i->de.setSpecification(ui->ND8lineEdit->text());
            ui->ND8lineEdit->clear();
            ui->ND7lineEdit->setText(i->de.getSpecification());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->ND6pushButton,&QPushButton::clicked,this,[=]   //ȷ���޸���������
    {
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+q;
        if(!ui->ND10lineEdit->text().isEmpty())
        {
            i->de.setManudate(ui->ND10lineEdit->text());
            ui->ND10lineEdit->clear();
            ui->ND9lineEdit->setText(i->de.getManudate());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->ND7pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸���������
    {
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+q;
        if(!ui->ND12lineEdit->text().isEmpty())
        {
            i->de.setManufacture(ui->ND12lineEdit->text());
            ui->ND12lineEdit->clear();
            ui->ND11lineEdit->setText(i->de.getManufacture());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
            return ;
        }
    });
    connect(ui->ND8pushButton,&QPushButton::clicked,this,[=]   //ȷ���޸�ȫ��
    {
        if(q==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡������δ�����������������㴫���������ڣ���"));
            return ;
        }
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+q;
        if(!ui->ND2lineEdit->text().isEmpty())   //����
        {
            i->de.setSensorname(ui->ND2lineEdit->text());
            ui->ND2lineEdit->clear();
            ui->ND1lineEdit->setText(i->de.getSensorname());
        }
        if(!ui->ND4lineEdit->text().isEmpty())   //���
        {
            i->de.setNumber(ui->ND4lineEdit->text());
            ui->ND4lineEdit->clear();
            ui->ND3lineEdit->setText(i->de.getNumber());
        }
        if(!ui->ND6lineEdit->text().isEmpty())   //�ͺ�
        {
            i->de.setModel(ui->ND6lineEdit->text());
            ui->ND6lineEdit->clear();
            ui->ND5lineEdit->setText(i->de.getModel());
        }
        if(!ui->ND8lineEdit->text().isEmpty())   //���
        {
            i->de.setSpecification(ui->ND8lineEdit->text());
            ui->ND8lineEdit->clear();
            ui->ND7lineEdit->setText(i->de.getSpecification());
        }
        if(!ui->ND10lineEdit->text().isEmpty())  //��������
        {
            i->de.setManudate(ui->ND10lineEdit->text());
            ui->ND10lineEdit->clear();
            ui->ND9lineEdit->setText(i->de.getManudate());
        }
        if(!ui->ND12lineEdit->text().isEmpty())  //��������
        {
            i->de.setManufacture(ui->ND12lineEdit->text());
            ui->ND12lineEdit->clear();
            ui->ND11lineEdit->setText(i->de.getManufacture());
        }
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ���������δ����Ĳ����޸ģ�"));
    });
    connect(ui->ND9pushButton,&QPushButton::clicked,this,[=]   //ȡ��
    {
        ui->ND1lineEdit->clear();
        ui->ND2lineEdit->clear();
        ui->ND3lineEdit->clear();
        ui->ND4lineEdit->clear();
        ui->ND5lineEdit->clear();
        ui->ND6lineEdit->clear();
        ui->ND7lineEdit->clear();
        ui->ND8lineEdit->clear();
        ui->ND9lineEdit->clear();
        ui->ND10lineEdit->clear();
        ui->ND11lineEdit->clear();
        ui->ND12lineEdit->clear();
        int b=-1;
        b=BGnd1.checkedId();
        if(b!=-1)
            BGnd1.button(b)->setCheckable(false);
        q=-1;
        ui->groupBox_7->hide();
        ui->pushButton_18->show();

    });


    //λ�ƴ������޸�
    connect(ui->pushButton_17,&QPushButton::clicked,this,[=]
    {
        int b=-1;
        b=BGyb1.checkedId();
        if(b!=-1)
        {
            BGwy1.button(b)->setCheckable(true);
        }
        ui->groupBox_8->show();
        ui->groupBox_7->hide();
        ui->groupBox_6->hide();
        ui->pushButton_18->hide();
    });
    BGwy1.addButton(ui->WY1radioButton,1);
    BGwy1.addButton(ui->WY2radioButton,2);
    ui->WY1lineEdit->setEnabled(false);
    ui->WY3lineEdit->setEnabled(false);
    ui->WY5lineEdit->setEnabled(false);
    ui->WY7lineEdit->setEnabled(false);
    ui->WY9lineEdit->setEnabled(false);
    ui->WY11lineEdit->setEnabled(false);
    ui->WY13lineEdit->setEnabled(false);
    ui->WY2lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));  //��������ʾ
    ui->WY4lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));  //��������ʾ
    ui->WY6lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));  //��������ʾ
    ui->WY8lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));  //��������ʾ
    ui->WY10lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));  //��������ʾ
    ui->WY12lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));  //��������ʾ
    ui->WY14lineEdit->setPlaceholderText(QString::fromLocal8Bit("�˴�����Ҫ�޸ĵ�����"));  //��������ʾ
    ui->WYlineEdit->setPlaceholderText(QString::fromLocal8Bit("��λ"));  //��������ʾ
    connect(ui->WY1pushButton,&QPushButton::clicked,this,[=]  //����
    {
        w=BGwy1.checkedId();
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        w--;
        i=i+w;
        if(i->d.getSensorname().isEmpty())
        {
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü���δ���ô�����������"));
            w=-1;
            return ;
        }
        ui->WY1lineEdit->setText(i->d.getSensorname());
        ui->WY3lineEdit->setText(i->d.getNumber());
        ui->WY5lineEdit->setText(i->d.getModel());
        QString s,m;
        m=QString::number(i->d.getFirstmonit(),10,3);
        if(!m.isEmpty())
        {
            s=QString("%1%2").arg(m).arg(i->d.getFirstunit());
            ui->WY7lineEdit->setText(s);
        }
        ui->WY9lineEdit->setText(i->d.getSpecification());
        ui->WY11lineEdit->setText(i->d.getManudate());
        ui->WY13lineEdit->setText(i->d.getManufacture());
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����ɹ�������"));
    });
    connect(ui->WY2pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸�����
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY2lineEdit->text().isEmpty())
        {
           i->d.setSensorname(ui->WY2lineEdit->text());
           ui->WY2lineEdit->clear();
           ui->WY1lineEdit->setText(i->d.getSensorname());
           QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
       }
       else
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
           return ;
       }
    });
    connect(ui->WY3pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸ı��
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY4lineEdit->text().isEmpty())
        {
           i->d.setNumber(ui->WY4lineEdit->text());
           ui->WY4lineEdit->clear();
           ui->WY3lineEdit->setText(i->d.getNumber());
           QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
       }
       else
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
           return ;
       }
    });
    connect(ui->WY4pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸��ͺ�
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY6lineEdit->text().isEmpty())
        {
           i->d.setModel(ui->WY6lineEdit->text());
           ui->WY6lineEdit->clear();
           ui->WY5lineEdit->setText(i->d.getModel());
           QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
       }
       else
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
           return ;
       }
    });
    connect(ui->WY5pushButton,&QPushButton::clicked,this,[=]   //ȷ���޸��������ʼֵ
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY8lineEdit->text().isEmpty())
        {
            double c;
            c=ui->WY8lineEdit->text().toDouble();
           i->d.setFirstmonit(c);
           ui->WY8lineEdit->clear();
       }
        QString s,m;
       if(!ui->WYlineEdit->text().isEmpty())
       {
           i->d.setFirstunit(ui->WYlineEdit->text());
           ui->WYlineEdit->clear();
       }
       s=QString::number(i->d.getFirstmonit(),10,3);
       m=QString("%1%2").arg(s).arg(i->d.getFirstunit());
       ui->WY7lineEdit->setText(m);
       QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));

    });
    connect(ui->WY6pushButton,&QPushButton::clicked,this,[=] //ȷ���޸Ĺ��
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY10lineEdit->text().isEmpty())
        {
           i->d.setSpecification(ui->WY10lineEdit->text());
           ui->WY10lineEdit->clear();
           ui->WY9lineEdit->setText(i->d.getSpecification());
           QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
       }
       else
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
           return ;
       }
    });
    connect(ui->WY7pushButton,&QPushButton::clicked,this,[=]  //ȷ���޸���������
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY12lineEdit->text().isEmpty())
        {
           i->d.setManudate(ui->WY12lineEdit->text());
           ui->WY12lineEdit->clear();
           ui->WY11lineEdit->setText(i->d.getManudate());
           QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
       }
       else
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
           return ;
       }
    });
    connect(ui->WY8pushButton,&QPushButton::clicked,this,[=]   //ȷ���޸�������
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY14lineEdit->text().isEmpty())
        {
           i->d.setManufacture(ui->WY14lineEdit->text());
           ui->WY14lineEdit->clear();
           ui->WY13lineEdit->setText(i->d.getManufacture());
           QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ�������"));
       }
       else
       {
           QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("��������Ϊ�գ�����"));
           return ;
       }
    });
    connect(ui->WY9pushButton,&QPushButton::clicked,this,[=] //ȷ���޸�ȫ��
    {
        if(w==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�ļ��㣡����"));
            return ;
        }
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+w;
        if(!ui->WY2lineEdit->text().isEmpty())  //�޸�����
        {
           i->d.setSensorname(ui->WY2lineEdit->text());
           ui->WY2lineEdit->clear();
           ui->WY1lineEdit->setText(i->d.getSensorname());
       }
        if(!ui->WY4lineEdit->text().isEmpty())  //���
        {
           i->d.setNumber(ui->WY4lineEdit->text());
           ui->WY4lineEdit->clear();
           ui->WY3lineEdit->setText(i->d.getNumber());
       }
        if(!ui->WY6lineEdit->text().isEmpty())  //�ͺ�
        {
           i->d.setModel(ui->WY6lineEdit->text());
           ui->WY6lineEdit->clear();
           ui->WY5lineEdit->setText(i->d.getModel());
        }
        if(!ui->WY8lineEdit->text().isEmpty()) //�������ʼֵ
        {
            double c;
            c=ui->WY8lineEdit->text().toDouble();
           i->d.setFirstmonit(c);
           ui->WY8lineEdit->clear();
       }
        QString s,m;
       if(!ui->WYlineEdit->text().isEmpty())  //��λ
       {
           i->d.setFirstunit(ui->WYlineEdit->text());
           ui->WYlineEdit->clear();
       }
       s=QString::number(i->d.getFirstmonit(),10,3);
       m=QString("%1%2").arg(s).arg(i->d.getFirstunit());
       ui->WY7lineEdit->setText(m);
       if(!ui->WY10lineEdit->text().isEmpty())    //���
       {
          i->d.setSpecification(ui->WY10lineEdit->text());
          ui->WY10lineEdit->clear();
          ui->WY9lineEdit->setText(i->d.getSpecification());
       }
       if(!ui->WY12lineEdit->text().isEmpty())  //��������
       {
          i->d.setManudate(ui->WY12lineEdit->text());
          ui->WY12lineEdit->clear();
          ui->WY11lineEdit->setText(i->d.getManudate());
       }
       if(!ui->WY14lineEdit->text().isEmpty())  //������
       {
          i->d.setManufacture(ui->WY14lineEdit->text());
          ui->WY14lineEdit->clear();
          ui->WY13lineEdit->setText(i->d.getManufacture());
      }
       QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�޸ĳɹ���������δ����Ĳ����޸ģ�"));
    });
    connect(ui->WY10pushButton,&QPushButton::clicked,this,[=]  //ȡ��
    {
        ui->WYlineEdit->clear();
        ui->WY1lineEdit->clear();
        ui->WY2lineEdit->clear();
        ui->WY3lineEdit->clear();
        ui->WY4lineEdit->clear();
        ui->WY5lineEdit->clear();
        ui->WY6lineEdit->clear();
        ui->WY7lineEdit->clear();
        ui->WY8lineEdit->clear();
        ui->WY9lineEdit->clear();
        ui->WY10lineEdit->clear();
        ui->WY11lineEdit->clear();
        ui->WY12lineEdit->clear();
        ui->WY13lineEdit->clear();
        ui->WY14lineEdit->clear();
        int b=-1;
        b=BGyb1.checkedId();
        if(b!=-1)
            BGyb1.button(b)->setCheckable(false);
        w=-1;
        ui->groupBox_8->hide();
        ui->pushButton_18->show();

    });


    //������ɾ������
    connect(ui->pushButton_3,&QPushButton::clicked,this,[=]
    {
        deletesensor.show();
    });
    connect(&deletesensor,&deletedialog::sendstrain,this,&subwidget1::getDeletestrain); //Ӧ�䴫����ɾ������
    connect(&deletesensor,&deletedialog::senddeflection,this,&subwidget1::getDeletedeflection);//�Ӷȴ�����ɾ������
    connect(&deletesensor,&deletedialog::senddisplace,this,&subwidget1::getDeletedisplace);//λ�ƴ�����ɾ������

    //��������ѯ����
    ui->groupBox_9->hide();
    connect(ui->pushButton_4,&QPushButton::clicked,this,[=]  //��ѯ��ť����ʾ��ѯgroupbox
    {
        ui->groupBox_9->show();
        ui->groupBox_3->hide();
        ui->groupBox_4->hide();
        ui->groupBox_5->hide();
    });
    ui->groupBoxYB->hide();
    ui->groupBoxND->hide();
    ui->groupBoxWY->hide();
    //Ӧ�䴫����
    BGyb2.addButton(ui->YB1radioButton,1);
    BGyb2.addButton(ui->YB2radioButton,2);
    BGyb2.addButton(ui->YB3radioButton,3);
    BGyb2.addButton(ui->YB4radioButton,4);
    BGyb2.addButton(ui->YB5radioButton,5);
    BGyb2.addButton(ui->YB6radioButton,6);
    BGyb2.addButton(ui->YB7radioButton,7);
    BGyb2.addButton(ui->YB8radioButton,8);
    BGyb2.addButton(ui->YB9radioButton,9);
    BGyb2.addButton(ui->YB10radioButton,10);
    ui->YB1lineEdit->setEnabled(false);
    ui->YB2lineEdit->setEnabled(false);
    ui->YB3lineEdit->setEnabled(false);
    ui->YB4lineEdit->setEnabled(false);
    ui->YB5lineEdit->setEnabled(false);
    ui->YB6lineEdit->setEnabled(false);
    ui->YB7lineEdit->setEnabled(false);
    connect(ui->pushButton_29,&QPushButton::clicked,this,[=]   //Ӧ�䴫������ѯgroupbox��ʾ
    {
        int b=-1;
        b=BGyb2.checkedId();
        if(b!=-1)
                BGyb2.button(b)->setCheckable(true);
        ui->groupBoxYB->show();
        ui->groupBoxND->hide();
        ui->groupBoxWY->hide();
        e=-1;
    });
    connect(ui->YB1pushButton,&QPushButton::clicked,this,[=] //Ӧ�䴫������ѯ��ť
    {
        e=BGyb2.checkedId();
        if(e==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�Ĵ�����������"));
            return ;
        }
        e--;
        QList<StrainPoint>::iterator i;
        i=stra.begin();
        i=i+e;
        if(!i->s.getSensorname().isEmpty())
        {
            ui->YB1lineEdit->setText(i->s.getSensorname());
            ui->YB2lineEdit->setText(i->s.getNumber());
            ui->YB3lineEdit->setText(i->s.getModel());
            ui->YB4lineEdit->setText(QString::number(i->s.getCencterwl(),10,5));
            ui->YB5lineEdit->setText(i->s.getSpecification());
            ui->YB6lineEdit->setText(i->s.getManudate());
            ui->YB7lineEdit->setText(i->s.getManufacture());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ѯ�ɹ�������"));
            e=-1;
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�ü���δ���ô�����������"));
            e=-1;
            return ;
        }
    });
    connect(ui->YB2pushButton,&QPushButton::clicked,this,[=]  //�رհ�ť
    {
        int b=-1;
        b=BGyb2.checkedId();
        if(b!=-1)
            BGyb2.button(b)->setCheckable(false);
        ui->YB1lineEdit->clear();
        ui->YB2lineEdit->clear();
        ui->YB3lineEdit->clear();
        ui->YB4lineEdit->clear();
        ui->YB5lineEdit->clear();
        ui->YB6lineEdit->clear();
        ui->YB7lineEdit->clear();
        ui->groupBoxYB->hide();
        e=-1;

    });


    //�Ӷȴ�����
    BGnd2.addButton(ui->nD1radioButton,1);
    BGnd2.addButton(ui->nD2radioButton,2);
    BGnd2.addButton(ui->nD3radioButton,3);
    BGnd2.addButton(ui->nD4radioButton,4);
    BGnd2.addButton(ui->nD5radioButton,5);
    BGnd2.addButton(ui->nD6radioButton,6);
    BGnd2.addButton(ui->nD7radioButton,7);
    BGnd2.addButton(ui->nD8radioButton,8);
    BGnd2.addButton(ui->nD9radioButton,9);
    BGnd2.addButton(ui->nD10radioButton,10);
    BGnd2.addButton(ui->nD11radioButton,11);
    BGnd2.addButton(ui->nD12radioButton,12);
    BGnd2.addButton(ui->nD13radioButton,13);
    BGnd2.addButton(ui->nD14radioButton,14);
    ui->nD1lineEdit->setEnabled(false);
    ui->nD2lineEdit->setEnabled(false);
    ui->nD3lineEdit->setEnabled(false);
    ui->nD4lineEdit->setEnabled(false);
    ui->nD5lineEdit->setEnabled(false);
    ui->nD6lineEdit->setEnabled(false);
    connect(ui->pushButton_30,&QPushButton::clicked,this,[=]   //�Ӷȴ�������ѯgroupbox��ʾ
    {
        int b=-1;
        b=BGnd2.checkedId();
        if(b!=-1)
                BGnd2.button(b)->setCheckable(true);
        ui->groupBoxND->show();
        ui->groupBoxYB->hide();
        ui->groupBoxWY->hide();
        f=-1;
    });
    connect(ui->nD1pushButton,&QPushButton::clicked,this,[=]  //�Ӷȴ�������ѯ��ť
    {
        f=BGnd2.checkedId();
        if(f==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�Ĵ�����������"));
            return ;
        }
        f--;
        QList<DeflectionPoint>::iterator i;
        i=defl.begin();
        i=i+f;
        if(!i->de.getSensorname().isEmpty())
        {
            ui->nD1lineEdit->setText(i->de.getSensorname());
            ui->nD2lineEdit->setText(i->de.getNumber());
            ui->nD3lineEdit->setText(i->de.getModel());
            ui->nD4lineEdit->setText(i->de.getSpecification());
            ui->nD5lineEdit->setText(i->de.getManudate());
            ui->nD6lineEdit->setText(i->de.getManufacture());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ѯ�ɹ�������"));
            f=-1;
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�ü���δ���ô�����������"));
            f=-1;
            return ;
        }
    });
    connect(ui->nD2pushButton,&QPushButton::clicked,this,[=]  //�Ӷȴ�������ѯ�رհ�ť
    {
        int b=-1;
        b=BGnd2.checkedId();
        if(b!=-1)
            BGnd2.button(b)->setCheckable(false);
        ui->nD1lineEdit->clear();
        ui->nD2lineEdit->clear();
        ui->nD3lineEdit->clear();
        ui->nD4lineEdit->clear();
        ui->nD5lineEdit->clear();
        ui->nD6lineEdit->clear();
        ui->groupBoxND->hide();
        f=-1;
    });


    //λ�ƴ�����
    BGwy2.addButton(ui->wy1radioButton,1);
    BGwy2.addButton(ui->wy2radioButton,2);
    ui->wy1lineEdit->setEnabled(false);
    ui->wy2lineEdit->setEnabled(false);
    ui->wy3lineEdit->setEnabled(false);
    ui->wy4lineEdit->setEnabled(false);
    ui->wy5lineEdit->setEnabled(false);
    ui->wy6lineEdit->setEnabled(false);
    ui->wy7lineEdit->setEnabled(false);
    connect(ui->pushButton_31,&QPushButton::clicked,this,[=]  //λ�ƴ�������ѯgroupbox��ʾ
    {
        int b=-1;
        b=BGwy2.checkedId();
        if(b!=-1)
                BGwy2.button(b)->setCheckable(true);
        ui->groupBoxND->hide();
        ui->groupBoxYB->hide();
        ui->groupBoxWY->show();
        r=-1;

    });
    connect(ui->wy1pushButton,&QPushButton::clicked,this,[=]   //λ�ƴ�������ѯ��ť
    {
        r=BGwy2.checkedId();
        if(r==-1)
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("δѡ��Ҫ��ѯ�Ĵ�����������"));
            return ;
        }
        r--;
        QList<DisplacementPoint>::iterator i;
        i=disp.begin();
        i=i+r;
        if(!i->d.getSensorname().isEmpty())
        {
            ui->wy1lineEdit->setText(i->d.getSensorname());
            ui->wy2lineEdit->setText(i->d.getNumber());
            ui->wy3lineEdit->setText(i->d.getModel());
            QString s;
            s=QString("%1%2").arg(i->d.getFirstmonit()).arg(i->d.getFirstunit());
            ui->wy4lineEdit->setText(s);
            ui->wy5lineEdit->setText(i->d.getManudate());
            ui->wy6lineEdit->setText(i->d.getManufacture());
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ѯ�ɹ�������"));
            r=-1;
        }
        else
        {
            QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�ü���δ���ô�����������"));
            r=-1;
            return ;
        }
    });
    connect(ui->wy2pushButton,&QPushButton::clicked,this,[=]   //λ�ƴ�������ѯ �رհ�ť
    {
        int b=-1;
        b=BGwy2.checkedId();
        if(b!=-1)
            BGwy2.button(b)->setCheckable(false);
        ui->wy1lineEdit->clear();
        ui->wy2lineEdit->clear();
        ui->wy3lineEdit->clear();
        ui->wy4lineEdit->clear();
        ui->wy5lineEdit->clear();
        ui->wy6lineEdit->clear();
        ui->groupBoxWY->hide();
        r=-1;

    });

    connect(ui->pushButton_32,&QPushButton::clicked,this,[=]    //��������ѯ���ܹرհ�ť
    {
        ui->groupBoxND->hide();
        ui->groupBoxWY->hide();
        ui->groupBoxYB->hide();
        ui->groupBox_9->hide();
    });

}



subwidget1::~subwidget1()
{
    delete ui;
}

void subwidget1::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/sub1/123.jpg"));
}
void subwidget1::getStrainFromFile()   //Ӧ����������ļ���ȡ�ۺ���
{
    QList<StrainPoint>::iterator i;
    monitroing m;
    int n=0;
    double c,y;
    QString L,a;
    QString filename=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("��ȡӦ���������"),"C:\\");
    if(filename.isEmpty()==true)
        {
            QMessageBox::warning(this,"warn",QString::fromLocal8Bit("�ļ���ʧ�ܣ�"));
            return ;
        }
    QFile file(filename);
    bool isOK=file.open(QFile::ReadOnly);
    if(isOK==false)
        {
            QMessageBox::critical(this,"ERROR",QString::fromLocal8Bit("�ļ���ʧ�ܣ�"));
            return ;
        }
    i=stra.begin();
    //�����һ�����㴫����δ���� �򾯸�
    if(i->s.getSensorname().isEmpty()||(i+1)->s.getSensorname().isEmpty()||(i+2)->s.getSensorname().isEmpty()||(i+3)->s.getSensorname().isEmpty()\
      ||(i+4)->s.getSensorname().isEmpty()||(i+5)->s.getSensorname().isEmpty()||(i+6)->s.getSensorname().isEmpty()||(i+7)->s.getSensorname().isEmpty()\
        ||(i+8)->s.getSensorname().isEmpty()||(i+9)->s.getSensorname().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("�ļ����ݶ�ȡʧ�ܣ������������м������ô�����������"));
        return ;
    }
    while(!file.atEnd())
    {
        i=stra.begin();
        L=file.readLine();qDebug()<<L;
        L=L.simplified();qDebug()<<L;
        n++;
        ui->tableWidget->setRowCount(n);//����񴴽���
         //��ȡ���ʱ��
         a=L.section(" ",0,0);
         qDebug()<<a;
         m.setDate(a);qDebug()<<a;
         a=L.section(" ",1,1);
         m.setTime(a);qDebug()<<a;
         //��һ������
         a=L.section(" ",2,2);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //�ڶ�������
         a=L.section(" ",3,3);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //����������
         a=L.section(" ",4,4);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //���ĸ�����
         a=L.section(" ",5,5);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //���������
         a=L.section(" ",6,6);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //����������
         a=L.section(" ",7,7);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //���߸�����
         a=L.section(" ",8,8);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //�ڰ˸�����
         a=L.section(" ",9,9);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //�ھŸ�����
         a=L.section(" ",10,10);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������
         i++;//ָ����һ������
         //��ʮ������
         a=L.section(" ",11,11);qDebug()<<a;
         c=a.toDouble();
         m.setMonitrNum(c);
         y=1000*(c-i->s.getCencterwl())+8*0.5;//�����Ӧ��
         m.setFinalData(y);
         m.setFinaldateUnit(QString("�̦�"));
         i->s.monitr.push_back(m);//��������ݷ���������

    }
   file.close();
   QMessageBox::information(this,QString::fromLocal8Bit("�ļ���ȡ�ɹ�"),QString::fromLocal8Bit("�ļ���ȡ�ɹ�������"));
}
void subwidget1::getDisplacementFromFile()   //λ�Ƽ��������ļ���ȡ�ۺ���
{
    QString L;
    QList<DisplacementPoint>::iterator i;
    monitroing m;
    QString a; int k=1;
    double c;
    i=disp.begin();
    QString filename=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("��ȡλ�Ƽ�������"),"C:\\");
    if(filename.isEmpty()==true)
        {
            QMessageBox::warning(this,"warn",QString::fromLocal8Bit("�ļ���ʧ�ܣ�"));
            return ;
        }
    QFile file(filename);
    bool isOK=file.open(QFile::ReadOnly);
    if(isOK==false)
        {
            QMessageBox::critical(this,"ERROR",QString::fromLocal8Bit("�ļ���ʧ�ܣ�"));
            return ;
        }
      //�����һ�����㴫����δ���� �򾯸�
    if(i->d.getSensorname().isEmpty()||(i+1)->d.getSensorname().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("�ļ����ݶ�ȡʧ�ܣ������������м������ô�����������"));
        return ;
    }
    i=disp.begin();
    while (!file.atEnd())
    {
        L=file.readLine();
        L=L.simplified();
        if(k==1) //k=1��ȡ�����д����������� k=0��ȡż���д�����������
        {
        //��ȡ�������������
        i=disp.begin();
        a=L.section(" ",0,0);
        m.setDate(a);
        qDebug()<<a;
        //��ȡ������ݵ�ʱ��
        a=L.section(" ",1,1);
        m.setTime(a);
        qDebug()<<a;
        //��ȡ������ݵĴ��������
        a=L.section(" ",2,2);
        i->d.setNumber(a);
        qDebug()<<a;
        //��ȡ������ݵļ��ֵ
        a=L.section(" ",3,3);
        c=a.toDouble();
        m.setMonitrNum(c);
        c=c-i->d.getFirstmonit();
        m.setFinalData(c);
        m.setFinaldateUnit(i->d.getFirstunit());
        qDebug()<<a;
        //��ȡ������ݵļ��ֵ��λ
        a=L.section(" ",4,4);
        m.setUnit(a);
        qDebug()<<a;
        //�����ݷ�������
        i->d.monitr.push_back(m);
        k=0;
        }
      else
      {

                    i=disp.begin();
                    i++;
                   //��ȡ�������������
                    a=L.section(" ",0,0);
                    m.setDate(a);
                    qDebug()<<a;
                    //��ȡ������ݵ�ʱ��
                    a=L.section(" ",1,1);
                    m.setTime(a);
                    qDebug()<<a;
                    //��ȡ������ݵĴ��������
                    a=L.section(" ",2,2);
                    i->d.setNumber(a);
                    qDebug()<<a;
                    //��ȡ������ݵļ��ֵ
                    a=L.section(" ",3,3);
                    c=a.toDouble();
                    m.setMonitrNum(c);
                    c=c-i->d.getFirstmonit();
                    m.setFinalData(c);
                    m.setFinaldateUnit(i->d.getFirstunit());
                    qDebug()<<a;
                    //��ȡ������ݵļ��ֵ��λ
                    a=L.section(" ",4,4);
                    m.setUnit(a);
                    qDebug()<<a;
                    //�����ݷ�������
                    i->d.monitr.push_back(m);
                    k=1;
        }

    }
    file.close();
     QMessageBox::information(this,QString::fromLocal8Bit("�ļ���ȡ�ɹ�"),QString::fromLocal8Bit("�ļ���ȡ�ɹ�������"));
}
void subwidget1::getDeflectionFromFile()   //�Ӷȼ��������ļ���ȡ�ۺ���
{
    QList<DeflectionPoint>::iterator i;
    i=defl.begin();
    monitroing m;
    int k=0;
    QString L,a;
    double c;
    QString filename=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("��ȡ�Ӷȼ�������"),"C:\\");
    if(filename.isEmpty()==true)
        {
            QMessageBox::warning(this,"warn",QString::fromLocal8Bit("�ļ���ʧ�ܣ�"));
            return ;
        }
    qDebug()<<"111";
    QFile file(filename);
    bool isOK=file.open(QFile::ReadOnly);
    if(isOK==false)
        {
            QMessageBox::critical(this,"ERROR",QString::fromLocal8Bit("�ļ���ʧ�ܣ�"));
            return ;
        }
    //�����һ������δ���ô��������򾯸�
    if(i->de.getSensorname().isEmpty()||(i+1)->de.getSensorname().isEmpty()||(i+2)->de.getSensorname().isEmpty()||(i+3)->de.getSensorname().isEmpty()\
       ||(i+8)->de.getSensorname().isEmpty()||(i+9)->de.getSensorname().isEmpty()||(i+10)->de.getSensorname().isEmpty()||(i+11)->de.getSensorname().isEmpty()\
            ||(i+4)->de.getSensorname().isEmpty()||(i+5)->de.getSensorname().isEmpty()||(i+6)->de.getSensorname().isEmpty()||(i+7)->de.getSensorname().isEmpty()\
            ||(i+12)->de.getSensorname().isEmpty()||(i+13)->de.getSensorname().isEmpty())
    {
        QMessageBox::warning(this,"warn",QString::fromLocal8Bit("�ļ����ݶ�ȡʧ�ܣ������������м������ô�����������"));
        return ;
    }
      while(!file.atEnd())
      {

          L=file.readLine();
          L=L.simplified();
          a=L.section(" ",0,0);
          m.setDate(a);
          qDebug()<<a;
          a=L.section(" ",1,1);
          m.setTime(a);
          qDebug()<<a;
          a=L.section(" ",2,2);
          (i+k)->de.setNumber(a);
          qDebug()<<a;
          a=L.section(" ",3,3);
          c=a.toDouble();
          m.setMonitrNum(c);
          qDebug()<<a;
          a=L.section(" ",4,4);
          m.setUnit(a);
          qDebug()<<a;
          (i+k)->de.monitr.push_back(m);
          k++;
          if(k==14)
              k=0;
      }

    file.close();
     QMessageBox::information(this,QString::fromLocal8Bit("�ļ���ȡ�ɹ�"),QString::fromLocal8Bit("�ļ���ȡ�ɹ�������"));
}
void subwidget1::getStrainsensor(StrainSensor a)
{

   QList<StrainPoint>::iterator i;
   i=stra.begin();
    int n;
    QString L;
    L=a.getManufacture().section("/",0,0);qDebug()<<L;
    n=a.getManufacture().section("/",1,1).toInt();
    a.setManufacture(L);
    n--;
    i=i+n;
    if(!i->s.getSensorname().isEmpty())
    {


        if(QMessageBox::Yes==QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü��㴫�����Ѵ��ڣ��Ƿ񸲸ǣ�"),QMessageBox::Yes,QMessageBox::No))
        {
                i->s.setCencterwl(a.getCencterwl());
                i->s.setManudate(a.getManudate());
                i->s.setManufacture(a.getManufacture());
                i->s.setModel(a.getModel());
                i->s.setSensorname(a.getSensorname());
                i->s.setSpecification(a.getSpecification());
                i->s.setNumber(a.getNumber());
                QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ӳɹ�!"));
        }


    }
    else
    {
    i->s.setCencterwl(a.getCencterwl());
    i->s.setManudate(a.getManudate());
    i->s.setManufacture(a.getManufacture());
    i->s.setModel(a.getModel());
    i->s.setSensorname(a.getSensorname());
    i->s.setSpecification(a.getSpecification());
    i->s.setNumber(a.getNumber());
    QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ӳɹ�!"));
    }
    qDebug()<<i->s.getSensorname();
    qDebug()<<i->s.getNumber();
    qDebug()<<i->s.getModel();
    qDebug()<<i->s.getCencterwl();
    qDebug()<<i->s.getSpecification();
    qDebug()<<i->s.getManudate();
    qDebug()<<i->s.getManufacture();
}
void subwidget1::getDeflectionsensor(DeflectionSensor a)
{
    QList<DeflectionPoint>::iterator i;
    i=defl.begin();
    int n;
    QString L;
    L=a.getManufacture().section("/",0,0);qDebug()<<L;
    n=a.getManufacture().section("/",1,1).toInt();
    a.setManufacture(L);
    n--;
    i=i+n;
    if(!i->de.getSensorname().isEmpty())
    {
         if(QMessageBox::Yes==QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü��㴫�����Ѵ��ڣ��Ƿ񸲸ǣ�"),QMessageBox::Yes,QMessageBox::No))
         {
             i->de.setManudate(a.getManudate());
             i->de.setManufacture(a.getManudate());
             i->de.setModel(a.getModel());
             i->de.setNumber(a.getNumber());
             i->de.setSensorname(a.getSensorname());
             i->de.setSpecification(a.getSpecification());
             QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ӳɹ�!"));
         }
    }
    else
    {
    i->de.setManudate(a.getManudate());
    i->de.setManufacture(a.getManudate());
    i->de.setModel(a.getModel());
    i->de.setNumber(a.getNumber());
    i->de.setSensorname(a.getSensorname());
    i->de.setSpecification(a.getSpecification());
    QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ӳɹ�!"));
    }
    qDebug()<<i->de.getSensorname();
    qDebug()<<i->de.getNumber();
    qDebug()<<i->de.getModel();
    qDebug()<<i->de.getSpecification();
    qDebug()<<i->de.getManudate();
    qDebug()<<i->de.getManufacture();
}
void subwidget1::getDisplacesensor(DisplacementSensor a)
{
    QList<DisplacementPoint>::iterator i;
    i=disp.begin();
    int n;
    QString L;
    L=a.getManufacture().section("/",0,0);qDebug()<<L;
    n=a.getManufacture().section("/",1,1).toInt();
    a.setManufacture(L);
    n--;
    i=i+n;
    if(!i->d.getSensorname().isEmpty())
    {
        if(QMessageBox::Yes==QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü��㴫�����Ѵ��ڣ��Ƿ񸲸ǣ�"),QMessageBox::Yes,QMessageBox::No))
        {
            i->d.setFirstmonit(a.getFirstmonit());
            i->d.setFirstunit(a.getFirstunit());
            i->d.setManudate(a.getManudate());
            i->d.setManufacture(a.getManufacture());
            i->d.setModel(a.getModel());
            i->d.setNumber(a.getNumber());
            i->d.setSensorname(a.getSensorname());
            i->d.setSpecification(a.getSpecification());
            QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ӳɹ�!"));
        }
    }
    else
    {
    i->d.setFirstmonit(a.getFirstmonit());
    i->d.setFirstunit(a.getFirstunit());
    i->d.setManudate(a.getManudate());
    i->d.setManufacture(a.getManufacture());
    i->d.setModel(a.getModel());
    i->d.setNumber(a.getNumber());
    i->d.setSensorname(a.getSensorname());
    i->d.setSpecification(a.getSpecification());
    QMessageBox::information(&sensdialog,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ӳɹ�!"));
    }
    qDebug()<<i->d.getSensorname();
    qDebug()<<i->d.getNumber();
    qDebug()<<i->d.getModel();
    qDebug()<<i->d.getFirstmonit();
    qDebug()<<i->d.getFirstunit();
    qDebug()<<i->d.getSpecification();
    qDebug()<<i->d.getManudate();
    qDebug()<<i->d.getManufacture();

}
void subwidget1::getDeletestrain(int k)
{
    k--;
    QList<StrainPoint>::iterator i;
    i=stra.begin();
    StrainSensor s;
    if(k!=-1)
    {
        i=i+k;
        if(!i->s.getSensorname().isEmpty())
        {
            if(QMessageBox::Yes==QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�Ƿ�Ҫɾ���ü��㴫������"),QMessageBox::Yes,QMessageBox::No))
            {      i->s=s;
                      QMessageBox::information(&deletesensor,"��ʾ",QString::fromLocal8Bit("�ü��㴫������ɾ����"));
            }
            else
                return ;
        }
        else
        {
            QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü���δ���ô�������"));
            return ;
        }

    }
    else
    {
        for(;i!=stra.end();i++)
            i->s=s;
        QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����Ѵ��ڵ�Ӧ�䴫������ɾ����"));
    }
}
void subwidget1::getDeletedeflection(int k)
{
    k--;
    QList<DeflectionPoint>::iterator i;
    i=defl.begin();
    DeflectionSensor d;
    if(k!=-1)
    {
        i=i+k;
        if(!i->de.getSensorname().isEmpty())
        {
            if(QMessageBox::Yes==QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�Ƿ�Ҫɾ���ü��㴫������"),QMessageBox::Yes,QMessageBox::No))
            {      i->de=d;
                      QMessageBox::information(&deletesensor,"��ʾ",QString::fromLocal8Bit("�ü��㴫������ɾ����"));
            }
            else
                return ;
        }
        else
        {
            QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü���δ���ô�������"));
            return ;
        }
    }
   else
        {
            for(;i!=defl.end();i++)
                i->de=d;
             QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����Ѵ��ڵ��Ӷȴ�������ɾ����"));
        }
}
void subwidget1::getDeletedisplace(int k)
{
    k--;
    QList<DisplacementPoint>::iterator i;
    i=disp.begin();
    DisplacementSensor d;
    if(k!=-1)
    {
        i=i+k;
        if(!i->d.getSensorname().isEmpty())
        {
            if(QMessageBox::Yes==QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�Ƿ�Ҫɾ���ü��㴫������"),QMessageBox::Yes,QMessageBox::No))
            {      i->d=d;
                      QMessageBox::information(&deletesensor,"��ʾ",QString::fromLocal8Bit("�ü��㴫������ɾ����"));
            }
            else
                return ;
        }
        else
        {
            QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�ü���δ���ô�������"));
            return ;
        }
    }
    else
         {
             for(;i!=disp.end();i++)
                 i->d=d;
              QMessageBox::information(&deletesensor,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����Ѵ��ڵ�λ�ƴ�������ɾ����"));
         }
}
void subwidget1::getDeflectiondialog(int z)
{
    z--;
    QString c;//c�Ǽ��ֵdoubleתΪQString����ڱ��
    int k=0,g=0,n=0;//k,g��������ÿ������ļ������������ڼ�����ÿ����һ��ѭ����n++����ʾ��񴴽�һ��
    QList<DeflectionPoint>::iterator i;
    i=defl.begin();
    QList<monitroing>::iterator j;
    j=i->de.monitr.begin();
    i=defl.begin();
    double p;
    while((j+k)!=defl.begin()->de.monitr.end())
    {
        n++;
        i=defl.begin();
        j=(i+g)->de.monitr.begin();
        ui->tableWidget_2->setRowCount(n);
        if(g==z)
            p=(j+k)->getMonitruNum();
        (j+k)->setFinalData((p-(j+k)->getMonitruNum())/100);
        (j+k)->setFinaldateUnit("cm");
        ui->tableWidget_2->setItem(n-1,0,new QTableWidgetItem((j+k)->getDate()));qDebug()<<"1";
        ui->tableWidget_2->setItem(n-1,1,new QTableWidgetItem((j+k)->getTime()));qDebug()<<"2";
        ui->tableWidget_2->setItem(n-1,2,new QTableWidgetItem(i->de.getNumber()));qDebug()<<"3";
        c=QString::number((j+k)->getMonitruNum(),10,2);qDebug()<<"4";
        ui->tableWidget_2->setItem(n-1,3,new QTableWidgetItem(c));qDebug()<<"5"; qDebug()<<c;
        ui->tableWidget_2->setItem(n-1,4,new QTableWidgetItem((j+k)->getUnit()));qDebug()<<"6";
        c=QString::number((j+k)->getFinalData(),10,4);
        ui->tableWidget_2->setItem(n-1,5,new QTableWidgetItem(c));
        ui->tableWidget_2->setItem(n-1,6,new QTableWidgetItem((j+k)->getFinaldateUnit()));
        g++;qDebug()<<"7";
        if(g==14)
        {
            g=0;qDebug()<<"8";
            k++;qDebug()<<"9";
            i=defl.begin();
            j=i->de.monitr.begin();

        }
    }
    ui->tableWidget->hide();qDebug()<<"10";
    ui->tableWidget_3->hide();qDebug()<<"11";
    ui->tableWidget_2->show();qDebug()<<"12";
}
void subwidget1::closeEvent(QCloseEvent *event)//�������Ͻǹرհ�ť����
{
    if(l==0)
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("����"),QString::fromLocal8Bit("����δ����!!!!   �뱣�����ݺ��˳�!!!!"));
        event->ignore();
    }
    else
    {
       QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����ѱ���!,�˳��ɹ�����"));
       close();
    }
}
void subwidget1::getStrainfileDate()
{
    QFile fileYb1("./StrainsensorDate.txt");
    fileYb1.open(QIODevice::ReadOnly);
    QString line;
    QList<StrainPoint>::iterator i;
    i=stra.begin();
    while(!fileYb1.atEnd())
    {
        line=fileYb1.readLine();
        line=line.simplified();
        QString m,n;
        int l;
        m=line.section(" ",0,0);
        n=m.section("/",0,0);
        l=n.toInt();
        n=m.section("/",1,1);
        (i+l-1)->s.setSensorname(n);
        m=line.section(" ",1,1);
        (i+l-1)->s.setNumber(m);
        m=line.section(" ",2,2);
        (i+l-1)->s.setModel(m);
        m=line.section(" ",3,3);
        double c=m.toDouble();
        (i+l-1)->s.setCencterwl(c);
        m=line.section(" ",4,4);
        (i+l-1)->s.setSpecification(m);
        m=line.section(" ",5,5);
        (i+l-1)->s.setManudate(m);
        m=line.section(" ",6,6);
        (i+l-1)->s.setManufacture(m);
    }
    fileYb1.close();
    QFile file2Yb("./StrainpointDate.txt");
    file2Yb.open(QIODevice::ReadOnly);
    i=stra.begin();
    monitroing j;
    while(!file2Yb.atEnd())
    {
        line=file2Yb.readLine();
        QString m;
        double c;
        line=line.simplified();
        if(line==QString("next"))
         {
            i++;qDebug()<<line;
            continue;
        }

        m=line.section(" ",0,0);
        j.setDate(m);
        m=line.section(" ",1,1);
        j.setTime(m);
        m=line.section(" ",2,2);
        c=m.toDouble();
        j.setMonitrNum(c);
        m=line.section(" ",3,3);
        c=m.toDouble();
        j.setFinalData(c);
        m=line.section(" ",4,4);
        j.setFinaldateUnit(m);
        i->s.monitr.push_back(j);
   }
    file2Yb.close();
}
void subwidget1::getDeflectionfileDate()
{
    QFile fileNd1("./DeflectionsensorDate.txt");
    fileNd1.open(QIODevice::ReadOnly);
    QString line;
    QList<DeflectionPoint>::iterator i;
    i=defl.begin();
    while(!fileNd1.atEnd())
    {
        line=fileNd1.readLine();
        line=line.simplified();
        QString m,n;
        int l;
        m=line.section(" ",0,0);
        n=m.section("/",0,0);
        l=n.toInt();
        n=m.section("/",1,1);
        (i+l-1)->de.setSensorname(n);
        m=line.section(" ",1,1);
        (i+l-1)->de.setNumber(m);
        m=line.section(" ",2,2);
        (i+l-1)->de.setModel(m);
        m=line.section(" ",3,3);
        (i+l-1)->de.setSpecification(m);
        m=line.section(" ",4,4);
        (i+l-1)->de.setManudate(m);
        m=line.section(" ",5,5);
        (i+l-1)->de.setManufacture(m);
    }
    fileNd1.close();
    QFile fileNd2("./DeflectionpointDate.txt");
    fileNd2.open(QIODevice::ReadOnly);
    i=defl.begin();
    monitroing j;
    while(!fileNd2.atEnd())
    {
        line=fileNd2.readLine();
        QString m;
        double c;
        line=line.simplified();
        if(line==QString("next"))
         {
            i++;qDebug()<<line;
            continue;
        }
        m=line.section(" ",0,0);
        j.setDate(m);
        m=line.section(" ",1,1);
        j.setTime(m);
        m=line.section(" ",2,2);
        c=m.toDouble();
        j.setMonitrNum(c);
        m=line.section(" ",3,3);
        j.setUnit(m);
        m=line.section(" ",4,4);
        c=m.toDouble();
        j.setFinalData(c);
        m=line.section(" ",5,5);
        j.setFinaldateUnit(m);
        i->de.monitr.push_back(j);
   }
    fileNd2.close();
}
void subwidget1::getDisplacementfileDate()
{
    QFile fileWy1("./DisplacementsensorDate.txt");
    fileWy1.open(QIODevice::ReadOnly);
    QList<DisplacementPoint>::iterator i;
    QString line;
    i=disp.begin();
    while(!fileWy1.atEnd())
    {
        line=fileWy1.readLine();
        line=line.simplified();
        QString m,n;
        int l;
        m=line.section(" ",0,0);
        n=m.section("/",0,0);
        l=n.toInt();
        n=m.section("/",1,1);
        (i+l-1)->d.setSensorname(n);
        m=line.section(" ",1,1);
        (i+l-1)->d.setNumber(m);
        m=line.section(" ",2,2);
        (i+l-1)->d.setModel(m);
        m=line.section(" ",3,3);
        double c=m.toDouble();
        (i+l-1)->d.setFirstmonit(c);
        m=line.section(" ",4,4);
        (i+l-1)->d.setFirstunit(m);
        m=line.section(" ",5,5);
        (i+l-1)->d.setSpecification(m);
        m=line.section(" ",6,6);
        (i+l-1)->d.setManudate(m);
        m=line.section(" ",7,7);
        (i+l-1)->d.setManufacture(m);
    }
    fileWy1.close();
    QFile fileWy2("./DisplacementpointDate.txt");
    fileWy2.open(QIODevice::ReadOnly);
    i=disp.begin();
    monitroing j;
    while(!fileWy2.atEnd())
    {
        line=fileWy2.readLine();
        QString m;
        double c;
        line=line.simplified();
        if(line==QString("next"))
         {
            i++;qDebug()<<line;
            continue;
        }
        m=line.section(" ",0,0);
        j.setDate(m);
        m=line.section(" ",1,1);
        j.setTime(m);
        m=line.section(" ",2,2);
        c=m.toDouble();
        j.setMonitrNum(c);
        m=line.section(" ",3,3);
        j.setUnit(m);
        m=line.section(" ",4,4);
        c=m.toDouble();
        j.setFinalData(c);
        m=line.section(" ",5,5);
        j.setFinaldateUnit(m);
        i->d.monitr.push_back(j);
   }
    fileWy2.close();
}
