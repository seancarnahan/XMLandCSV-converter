//
//  XMLTest.cpp
//
//
//  Created by Aly Kapasi on 5/22/19.
//

#include <gtest/gtest.h>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include "XMLWriter.h"
#include "XMLEntity.h"

TEST(XMLTest, WriteStartElement){

  //stream backed by string
  std::stringstream ss;

  //create xml writer with stream
  CXMLWriter xml(ss);


  //create the entity
  SXMLEntity entity;
  entity.DType = SXMLEntity::EType::StartElement;
  entity.DNameData = "COURSE";
  entity.SetAttribute("SUBJ", "ECS");
  entity.SetAttribute("CRSE", "34");
  entity.SetAttribute("SEC", "36");

  //write the entity using xml writer
  EXPECT_TRUE(xml.WriteEntity(entity));

  //flush the stream
  xml.Flush();

  EXPECT_EQ(ss.str(), "<COURSE SUBJ=\"ECS\" CRSE=\"34\" SEC=\"36\">");

}

TEST(XMLTest, WriteEndElement) {
  //stream backed by string
  std::stringstream ss;

  //create xml writer with stream
  CXMLWriter xml(ss);


  //create the entity
  SXMLEntity entity;

  entity.DType = SXMLEntity::EType::EndElement;
  entity.DNameData = "COURSE";
  entity.SetAttribute("SUBJ", "ECS");
  entity.SetAttribute("CRSE", "34");
  entity.SetAttribute("SEC", "36");

  EXPECT_TRUE(xml.WriteEntity(entity));
  xml.Flush();

  EXPECT_EQ(ss.str(), "</COURSE>");
}

TEST(XMLTest, WriteCharData) {
  //stream backed by string
  std::stringstream ss;

  //create xml writer with stream
  CXMLWriter xml(ss);


  //create the entity
  SXMLEntity entity;
  entity.DType = SXMLEntity::EType::CharData;
  EXPECT_FALSE(xml.WriteEntity(entity));
  xml.Flush();
  EXPECT_EQ(ss.str(), "");
}

TEST(XMLTest, WriteCompleteElement) {
  //stream backed by string
  std::stringstream ss;

  //create xml writer with stream
  CXMLWriter xml(ss);


  //create the entity
  SXMLEntity entity;
  entity.DType = SXMLEntity::EType::CompleteElement;
  entity.DNameData = "STUDENT";
  entity.SetAttribute("SEAT", "4");
  entity.SetAttribute("SID", "111111111");
  entity.SetAttribute("SURNAME", "Meef");
  entity.SetAttribute("PREFNAME", "Beef");

  EXPECT_TRUE(xml.WriteEntity(entity));
  xml.Flush();

  EXPECT_EQ(ss.str(), "<STUDENT SEAT=\"4\" SID=\"111111111\" SURNAME=\"Meef\" PREFNAME=\"Beef\"/>");
}
