/****************************************************
/* 7Bot class for Arduino platform
/* Author: Jerry Peng
/* Date: 26 April 2016
/* 
/* Version 1.00
/* www.7bot.cc
/*  
/* Description: 
/* 
/*
/***************************************************/

#ifndef _PVECTOR_H
#define _PVECTOR_H

#include "Arduino.h"


class PVector {
  public:
    /* Global Variables */
    double x, y, z;


    // constructor
    PVector(); //Empty constructor
    PVector(double _x, double _y, double _z); //x,y,z position vector
    // function
    void add(PVector p);  //Updates existing p vector
    void normalize();     //Finds the normalized vector
    double dot(PVector p); //Finds the dot product
    double dist(PVector p); //Distance

  private:

};

#endif

