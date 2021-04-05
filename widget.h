#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Widget *ui;

    int mouseX;
    int mouseY;
    int absX;
    int absY;
    int justOneCount;

    void mouseMoveEvent(QMouseEvent *mouse);
    void mouseReleaseEvent(QMouseEvent *);

    QString mamService{"MAM"};
    QString masService{"MAS"};
};
#endif // WIDGET_H
