/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TAnaDB.hh
 * Author: rafopar
 *
 * Created on February 18, 2018, 3:23 PM
 */

#ifndef TANADB_HH
#define TANADB_HH

#include "TString.h"
#include "TSQLServer.h"
#include "TSQLResult.h"
#include "TSQLRow.h"

#include <iostream>

class TAnaDB {
public:
    TAnaDB(std::string, std::string, std::string, std::string);
    // TAnaDB(const TAnaDB& orig);
    virtual ~TAnaDB();
private:

    TSQLServer *fServer;
    TString fUser;


};

#endif /* TANADB_HH */

