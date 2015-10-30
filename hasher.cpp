#include "hasher.h"

/* Destructor */
Hasher::~Hasher() {

}

/*
 * Constructor Hasher(QByteArray &, Algorithm) generates hash
 * from given input with given algorithm-method
*/
Hasher::Hasher(const QByteArray &data, Algorithm method)
    : QCryptographicHash(method)
{
   QByteArray result = this->hash(data, method);
   this->output = result.toHex();
}
