#include "XMLEntity.h"
#include "XMLWriter.h"




/**
<course SUBJ="" CRSE="" SEC=""> //StartElement
<student SEAT="" SURNAME="" SID=""/>
</course>
 */

// Constructor for XML writer, CXMLWriter should have a
// std::ostream & as part of it
CXMLWriter::CXMLWriter(std::ostream &os) : out(os) {
}

// Destructor for XML writer
CXMLWriter::~CXMLWriter() {
  //close the output stream
}

// Outputs all end elements for those that have been started
bool CXMLWriter::Flush() {
  //flush the output stream
  out.flush();
  return true;
}

// Writes out the entity to the output stream
bool CXMLWriter::WriteEntity(const SXMLEntity &entity) {

  //if start element - output <(entity.DNameData)
  if (entity.DType == SXMLEntity::EType::StartElement) {

    //output
    out << "<"+entity.DNameData;
    for (auto attr : entity.DAttributes) {
      out << " "+std::get<0>(attr)+"=\""+std::get<1>(attr)+"\"";
    }
    out << ">";

  } else if(entity.DType == SXMLEntity::EType::EndElement) {

    //output
    out << "</"+entity.DNameData;
    out << ">";

  } else if (entity.DType == SXMLEntity::EType::CharData) {

    return false;

  } else if (entity.DType == SXMLEntity::EType::CompleteElement) {

    out << "<"+entity.DNameData;
    for (auto attr : entity.DAttributes) {
      out << " "+std::get<0>(attr)+"=\""+std::get<1>(attr)+"\"";
    }
    out << "/>";
  }

  return true;

}
