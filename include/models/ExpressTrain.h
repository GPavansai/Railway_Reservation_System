#ifndef EXPRESSTRAIN_H
#define EXPRESSTRAIN_H

#include "models/Train.h"

class ExpressTrain : public Train {
public:
    ExpressTrain(int num, const std::string& name, const std::string& src,
                 const std::string& dest, int seats, double fare);

    double calculateFare() const override;
    std::string getTrainType() const override;
};

#endif // EXPRESSTRAIN_H
