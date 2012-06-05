#ifndef NEWTONMETHODTHREAD_H
#define NEWTONMETHODTHREAD_H

#include <QThread>
#include "model.h"
#include "dialog.h"

class newtonMethodThread : public QThread
{
    Q_OBJECT

private:
    const Dialog *dialog;
public:

    explicit newtonMethodThread(const Dialog * dialog, QObject *parent = 0);
    void run();

signals:

    void done();

public slots:

};

#endif // NEWTONMETHODTHREAD_H

