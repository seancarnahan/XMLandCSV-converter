
#include "XMLReader.h"
#include "XMLWriter.h"
#include "XMLEntity.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include <fstream>



int main (int argc, char* argv[]) {
  //get the name of the file

  const std::vector<std::string> HEADERS = {
    "SEAT", //The seat number of the student
    "SID", //The student ID
    "SURNAME", //The last name of the student
    "PREFNAME", //The student’s preferred first name
    "LEVEL", //The student’s level UG for undergrad, etc.
    "UNITS", //The number of units the student received
    "CLASS", //The student’s class standing
    "MAJOR", //The student’s major code
    "GRADE", //The grade the student received in the course
    "STATUS", //The student’s registration status
    "EMAIL"}; //The student’s e-mail address

  std::string CSV_ENDING(".csv");
  std::string XML_ENDING(".xml");

  if (argc < 2) {
    std::cerr << "Syntax Error: Main <path to file>\n";
    return 1;
  }
  std::string filename(argv[1]);
  if (filename.size() < 5) {
    std::cerr << "Input Error: file must end with .xml or .csv\n";
    return 1;
  }

  //determine if csv of xml based on the name of the file
  if (std::equal(CSV_ENDING.rbegin(), CSV_ENDING.rend(), filename.rbegin())) {

    //get the subj, crse, sec from the name of the file
    //TODO: need to do error checking here
    int lastpos = 0;
    int pos = filename.find("_", lastpos);
    int len = pos - lastpos;
    std::string subj = filename.substr(lastpos, len);
    lastpos = pos+1;
    pos = filename.find("_", lastpos);
    len = pos - lastpos;
    std::string crse = filename.substr(lastpos, len);
    lastpos = pos+1;
    pos = filename.find(".", lastpos+1);
    len = pos - lastpos;
    std::string sec = filename.substr(lastpos, len);

    //initialize things
    std::ifstream input(filename);
    std::ofstream output(filename + ".otherxt");
    CCSVReader reader(input);
    CXMLWriter xml(output);
    std::vector<std::string> row;

    //write the courseEntity using xml writer
    SXMLEntity courseEntity;
    courseEntity.DType = SXMLEntity::EType::StartElement;
    courseEntity.DNameData = "COURSE";
    courseEntity.SetAttribute("SUBJ", subj);
    courseEntity.SetAttribute("CRSE", crse);
    courseEntity.SetAttribute("SEC", sec);
    xml.WriteEntity(courseEntity);

    //read first row to get the names of fields
    row.clear();
    reader.ReadRow(row);
    std::vector<std::string> headers = row;

    //write out the student data
    while (reader.ReadRow(row)) {
      SXMLEntity studentEntity;
      studentEntity.DType = SXMLEntity::EType::CompleteElement;
      studentEntity.DNameData = "STUDENT";
      for (int i = 0; i < headers.size(); i++) {
	studentEntity.SetAttribute(headers[i], row[i]);
      }
      xml.WriteEntity(studentEntity);
      row.clear();
    }

    //end the course
    SXMLEntity endEntity;
    endEntity.DType = SXMLEntity::EType::EndElement;
    endEntity.DNameData = "COURSE";
    xml.WriteEntity(endEntity);

    //finish off the streams
    xml.Flush();
    reader.End();
    input.close();
    std::cout << "\n";

  } else if (std::equal(XML_ENDING.rbegin(), XML_ENDING.rend(), filename.rbegin())) {
    std::ifstream input(filename);
    CXMLReader reader(input);
    CCSVWriter csv(std::cout);

    //first entity should be the course
    SXMLEntity courseEntity;
    if (!reader.ReadEntity(courseEntity)) {
      std::cerr << "Invalid file: no COURSE entity\n";
    }

    //write out the file name?
    std::cerr << "COURSE: " << courseEntity.AttributeValue("SUBJ") << " "
	      << courseEntity.AttributeValue("CRSE")
	      << " " << courseEntity.AttributeValue("SEC") << "\n";

    //write the headers
    csv.WriteRow(HEADERS);

    //write out all of the students
    SXMLEntity studentEntity;
    while (reader.ReadEntity(studentEntity)) {
      std::vector<std::string> values;
      for (auto header : HEADERS) {
	if (studentEntity.AttributeExists(header)) {
	  values.push_back(studentEntity.AttributeValue(header));
	} else {
	  values.push_back("");
	}
      }
      csv.WriteRow(values);
    }

    reader.End();
    input.close();
    std::cout << "\n";

  } else {
    std::cerr << "Input Error: file must end with .xml or .csv\n";
    return 1;
  }

  return 0;

}
