#ifndef VIEWRESULTS_H
#define VIEWRESULTS_H

#include <QDialog>

namespace Ui {
class viewResults;
}

class viewResults : public QDialog
{
    Q_OBJECT

public:
    explicit viewResults(std::vector<double> data, QWidget *parent = nullptr);
    ~viewResults();

private:
    Ui::viewResults *ui;
};

#endif // VIEWRESULTS_H
