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

#include "ForceFilter.h"

//Initialize all elements to 0
ForceFilter::ForceFilter() {
    for(int i=0; i<forceFilterSize; i++){
        filerElements[i] = 0;
    }
}

//Returns the average of all the ints in the filter array
//Filter size for ForceFilter array is 30
int ForceFilter::filter(int dataIn) {
    int sum = 0;


    //Inputs new data into array. Last element of array gets overwritten.
    for(int i=forceFilterSize-1; i>0; i--){
        filerElements[i] = filerElements[i-1];
        sum += filerElements[i];
    }
    filerElements[0] = dataIn;
    sum += filerElements[0];

    /*
    Sum now holds total sum. Would be more time efficient just to include this as an attribute of
    ForceFilter tbh and just update the size every time a new element is added
    */
    //TODO: Add 'sum' as an attribute of all force objects to make filter() more time efficient


    //Returns average
    return (int)( sum / forceFilterSize );
    
}
