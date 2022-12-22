#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include<QButtonGroup>
namespace Ui {
class deletedialog;
}

class deletedialog : public QDialog
{
    Q_OBJECT

public:
    explicit deletedialog(QWidget *parent = nullptr);
    ~deletedialog();
    QButtonGroup BG1;
    QButtonGroup BG2;
    QButtonGroup BG3;
signals:
    void sendstrain(int );
    void senddeflection(int);
    void senddisplace(int );
public slots:
    void slotstrain();//Ӧ����㴫��������ɾ��
    void slotsstrainall();//Ӧ����㴫����ȫ��ɾ��
    void slotsdeflection();//�Ӷȼ��㴫��������ɾ��
    void slotsdeflectionall();//�Ӷȼ��㴫����ȫ��ɾ��
    void slotsdisplace();//λ�ƴ���������ɾ��
    void slotsdisplaceall();//λ�ƴ�����ȫ��ɾ��
protected:
    void closeEvent(QCloseEvent *event);//�������Ͻǹرհ�ť����
private:
    Ui::deletedialog *ui;
};

#endif // DELETEDIALOG_H
