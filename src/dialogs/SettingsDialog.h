#pragma once

#include <core/ApplicationSettings.h>
#include <QDialog>
#include <QSettings>
#include <memory>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    ApplicationSettings applicationSetings() const;
    void setApplicationSetings(const ApplicationSettings &applicationSetings);

protected:
    void changeEvent(QEvent *e);

private slots:
    void loadSettings();
    void saveSettings();

private:
    Ui::SettingsDialog *ui;
    QSettings settings_;
    ApplicationSettings applicationSetings_;
};
