#ifndef HASHER_H
#define HASHER_H

#include <QString>
#include <QCryptographicHash>

class Hasher : public QCryptographicHash
{
public:
    Hasher(const QByteArray &data, Algorithm method); /* Constructor */
    ~Hasher(); /* Destructor */

    QString name, output;
private:

};

#endif // HASHER_H
