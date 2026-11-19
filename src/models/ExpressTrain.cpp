#include "models/ExpressTrain.h"

ExpressTrain::ExpressTrain(int num, const std::string& name, const std::string& src,
                           const std::string& dest, int seats, double fare)
    : Train(num, name, src, dest, seats, fare) {}

double ExpressTrain::calculateFare() const {
    return baseFare;
}

std::string ExpressTrain::getTrainType() const {
    return "Express";
}
