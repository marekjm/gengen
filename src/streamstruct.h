//
// C++ Interface: streamstruct
//
// Description: contains the streams for code generation
//
//
// Author: Lorenzo Bettini <http://www.lorenzobettini.it>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef STREAMSTRUCT_H
#define STREAMSTRUCT_H

#include <iostream>

class StreamStruct
{
public:
  std::ostream *header_stream;
  std::ostream *source_stream;

  StreamStruct(std::ostream *header = 0, std::ostream *source = 0) :
      header_stream (header), source_stream (source) {}
};

#endif // STREAMSTRUCT_H
