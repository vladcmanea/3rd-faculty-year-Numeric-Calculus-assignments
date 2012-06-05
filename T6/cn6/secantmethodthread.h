#ifndef SECANTMETHODTHREAD_H
#define SECANTMETHODTHREAD_H

#include <QThread>
#include "model.h"
#include "dialog.h"

class secantMethodThread : public QThread
{
    Q_OBJECT

private:
    const Dialog *dialog;
public:
    explicit secantMethodThread(const Dialog * dialog, QObject *parent = 0);
    void run();

signals:

    void done();

public slots:


};

#endif // SECANTMETHODTHREAD_H

