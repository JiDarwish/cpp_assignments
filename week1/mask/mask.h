
#ifndef MASK_H
#define MASK_H
typedef unsigned char Byte;
typedef unsigned int Uint;

Byte makeMask(Uint pos);
Byte setMask( Byte source, Byte mask );
Byte unsetMask( Byte source, Byte mask );
bool checkMask(Byte source, Byte mask);

#endif /* end of include guard: MASK_H */

