#ifndef SUPERFASTTRAIN_H
#define SUPERFASTTRAIN_H

#include "models/Train.h"

class SuperfastTrain : public Train {
private:
    double superfastSurcharge;

public:
    SuperfastTrain(int num, const std::string& name, const std::string& src,
                   const std::string& dest, int seats, double fare, double surcharge = 15.0);

    double calculateFare() const override;
    std::string getTrainType() const override;
};

#endif // SUPERFASTTRAIN_H
