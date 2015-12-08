#include "hasher.h"

Hasher::~Hasher() {

}

/*
Hasher::Hasher(QByteArray &, Algorithm) generates hash
from given input with given algorithm-method
*/
Hasher::Hasher(const QByteArray &data, Algorithm method)
    : QCryptographicHash(method)
{
   QByteArray result = this->hash(data, method);
   this->output = result.toHex();
}
