
/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#include <Arduino.h>
#include "BlockSensors.h"

void BlockSensors::initBlockSensors(int totalSensor) {
  if (totalSensor > 0)
    _totalSensor = totalSensor;
  this->_irSensorBlocks = new IrSensor[_totalSensor];
  for (int i = 0; i < _totalSensor; i++) {
    this->_irSensorBlocks[i].setStartAndEndBlockSensorPin(0, 0);
  }
}

void BlockSensors::setBlockSensorPins(int blockNo, int startBlockSensorPin, int endBlockSensorPin) {
  _irSensorBlocks[blockNo - 1].setStartAndEndBlockSensorPin(startBlockSensorPin, endBlockSensorPin);
}

bool BlockSensors::isSensorBlockOccupied(int blockNo) {
  return _irSensorBlocks[blockNo - 1].isBlockOccupied();
}
