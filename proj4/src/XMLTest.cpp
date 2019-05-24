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

  //write the entity using xml writer
  xml.WriteEntity(entity);

  //flush the stream
  xml.Flush();

  EXPECT_EQ(ss.str(), "<COURSE SUBJ=\"ECS\" CRSE=\"34\">");
  



}

