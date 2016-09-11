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

#include "PressFilter.h"


PressFilter::PressFilter() {
    for(int i=0; i<pressFilterSize; i++) {
        filerElements[i] = 0;
    }
}


//Filter size for press filter is 9
int PressFilter::filter(int dataIn) {
    int sum = 0;
    for(int i = pressFilterSize - 1; i > 0; i--){
        filerElements[i] = filerElements[i - 1];
        //What does |= do?
        sum |= filerElements[i];
    }
    filerElements[0] = dataIn;
    sum |= filerElements[0]; 
    return sum;
}
