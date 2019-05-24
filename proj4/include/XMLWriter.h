#ifndef XMLWRITER_H
#define XMLWRITER_H

#include "XMLEntity.h"
#include <stack>
#include <iostream>

class CXMLWriter{
 private:
  std::ostream &out;
  
 public:
  CXMLWriter(std::ostream &os);
  ~CXMLWriter();
  
  bool Flush();
  bool WriteEntity(const SXMLEntity &entity);
};

#endif
                                      
