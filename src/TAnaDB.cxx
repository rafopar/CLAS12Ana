/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TAnaDB.cxx
 * Author: rafopar
 * 
 * Created on February 18, 2018, 3:23 PM
 */

#include "TAnaDB.hh"
#include <iostream>

using namespace std;

// This class will help to add and read entries into the DB
// Mostly db entries will be analysis related

TAnaDB::TAnaDB(string db, string host, string user, string passwd) {
    
    TString connect("mysql://");
    connect += host; connect+= "/";
    connect += db;
    
    fUser = user;
    
   fServer = TSQLServer::Connect(connect.Data(), fUser.Data() , passwd.c_str());
   
   fServer->Dump();
}

//TAnaDB::TAnaDB(const TAnaDB& orig) {
//}

TAnaDB::~TAnaDB() {
}

