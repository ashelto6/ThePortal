#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QWidget>

namespace Ui {
class Template;
}

class Template : public QWidget
{
    Q_OBJECT

public:
    explicit Template(QWidget *parent = nullptr);
    ~Template();

private:
    Ui::Template *ui;
};

#endif // TEMPLATE_H
