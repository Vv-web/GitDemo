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
    void slotstrain();//应变监测点传感器单个删除
    void slotsstrainall();//应变监测点传感器全部删除
    void slotsdeflection();//挠度监测点传感器单个删除
    void slotsdeflectionall();//挠度监测点传感器全部删除
    void slotsdisplace();//位移传感器单个删除
    void slotsdisplaceall();//位移传感器全部删除
protected:
    void closeEvent(QCloseEvent *event);//窗口右上角关闭按钮重载
private:
    Ui::deletedialog *ui;
};

#endif // DELETEDIALOG_H
