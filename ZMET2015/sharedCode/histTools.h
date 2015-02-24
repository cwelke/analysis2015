#include "TH1.h"

#ifndef HISTTOOLS_H
#define HISTTOOLS_H

void fillUnderOverFlow(TH1F * &h1, float value, float weight);
void fillUnderOverFlow(TH1D * &h1, double value, float weight);
void saveHist(const std::string filename, const std::string pat="*");

#endif
