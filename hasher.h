#ifndef HASHER_H
#define HASHER_H

#include <QString>
#include <QCryptographicHash>

/* Class Hasher provides methods to work with hashes */
class Hasher : public QCryptographicHash
{
public:
    Hasher(const QByteArray &data, Algorithm method); /* Constructor */
    ~Hasher(); /* Destructor */
    QString name, output;
};

#endif // HASHER_H
