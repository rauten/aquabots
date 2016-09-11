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

#include "MedianFilter.h"



//Filter size for Median Filter is 39
//Initialize new array to hold all zeros
MedianFilter::MedianFilter() {
  for(int i = 0; i < filterSize; i++){
    filerElements[i] = 0;
  }
  
}


//Returns median element of sorted elements
int MedianFilter::filter(int dataIn) {
    // 1: input data. Last element in array gets overwritten. New element is in position 0
    for(int i = filterSize - 1; i > 0; i--){
        filerElements[i] = filerElements[i-1];
    }
    filerElements[0] = dataIn;
    
    // 2: copy data (copy the list into a new array)
    //float[] rankingElements = filerElements;  
    int rankingElements[filterSize]; 
    for(int i = 0; i < filterSize; i++){
        rankingElements[i] = filerElements[i];
    }
    
    // 3: ranking (sort the list)
    int temp;
    for(int k = 0; k < filterSize; k++){
        for(int j = k + 1; j < filterSize; j++){
            if(rankingElements[j] < rankingElements[k]) {
                temp = rankingElements[k];
                rankingElements[k] = rankingElements[j];
                rankingElements[j] = temp;
            }
        }
    }
    //Return median element in list
    return rankingElements[(filterSize - 1) / 2];
}
