
#include "XMLReader.h"
#include "XMLWriter.h"
#include "XMLEntity.h"
#include "CSVReader.h"
#include "CSVWriter.h"


int main (int argc, char* argv[]) {
  //get the name of the file


  //determine if csv of xml based on the name of the file

  // //open a stream to the file
  // std::istream input; // TODO open it

  // //if this is CVS -> read as CSV
  // if () {
  //   CCSVReader reader(input);
  //   CXMLWriter xml(std::cout);

  //   //get the subj, crse, sec from the name of the file
  //   SXMLEntity courseEntity;
  //   courseEntity.DType = SXMLEntity::EType::StartElement;
  //   courseEntity.DNameData = "COURSE";
  //   courseEntity.SetAttribute("SUBJ", "");
  //   courseEntity.SetAttribute("CRSE", "");
  //   courseEntity.SetAttribute("SEC", "");

  //   //write the courseEntity using xml writer
  //   xml.WriteEntity(courseEntity);
    
  //   std::vector<std::string> row;

  //   //read first row to get the names of fields
  //   reader.ReadRow(row);
  //   std::vector<std::string> headers = row;

  //   while (reader.ReadRow(row)) {
  //     SXMLEntity studentEntity;
  //     studentEntity.DType = SXMLEntity::EType::CompleteElement;
  //     studentEntity.DNameData = "STUDENT";
  //     for (int i = 0; i < headers.size(); i++) {
  // 	 studentEntity.SetAttribute(headers[i], row[i]);
  //     }
  //     xml.WriteEntity(studentEntity);
  //   }

  //   SXMLEntity endEntity;
  //   endEntity.DType = SXMLEntity::EType::EndElement;
  //   endEntity.DNameData = "COURSE";
  //   xml.WriteEntity(endEntity);
    
    
  //   //flush the stream
  //   xml.Flush();


  
  // } else {
  //   XMLReader reader(input);



  // }

  return 1;

}
