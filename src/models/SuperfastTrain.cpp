#include "models/SuperfastTrain.h"

SuperfastTrain::SuperfastTrain(int num, const std::string& name, const std::string& src,
                               const std::string& dest, int seats, double fare, double surcharge)
    : Train(num, name, src, dest, seats, fare), superfastSurcharge(surcharge) {}

double SuperfastTrain::calculateFare() const {
    return baseFare + superfastSurcharge;
}

std::string SuperfastTrain::getTrainType() const {
    return "Superfast";
}
