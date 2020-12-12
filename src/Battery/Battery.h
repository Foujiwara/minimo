/*
 Battery.h - Battery library
 Copyright (c) 2014 Roberto Lo Giacco.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as 
 published by the Free Software Foundation, either version 3 of the 
 License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BATTERY_H_
#define BATTERY_H_

#include <Arduino.h>

typedef uint8_t(*mapFn_t)(uint32_t, uint32_t, uint32_t);

class Battery {
	public:
		/**
		 * Creates an instance to monitor battery voltage and level.
		 * Initialization parameters depend on battery type and configuration.
		 *
		 * @param minVoltage is the voltage, expressed in millivolts, corresponding to an empty battery
		 * @param maxVoltage is the voltage, expressed in millivolts, corresponding to a full battery
		 */
		Battery(uint32_t minVoltage, uint32_t maxVoltage);

		/**
		 * Initializes the library by optionally setting additional parameters.
		 * To obtain the best results use a calibrated reference using the VoltageReference library or equivalent.
		 * 
		 * @param mapFunction is a pointer to the function used to map the battery voltage to the remaining capacity percentage (defaults to linear mapping)
		 */
		void begin(mapFn_t = 0);


		/**
		 * Returns the current battery level as a number between 0 and 100, with 0 indicating an empty battery and 100 a
		 * full battery.
		 */
		uint8_t level(uint32_t voltage);

	private:
		uint32_t minVoltage;
		uint32_t maxVoltage;
		mapFn_t mapFunction;
};

//
// Plots of the functions below available at
// https://www.desmos.com/calculator/x0esk5bsrk
//

/**
 * Symmetric sigmoidal approximation
 * https://www.desmos.com/calculator/7m9lu26vpy
 *
 * c - c / (1 + k*x/v)^3
 */
static inline uint8_t sigmoidal(uint32_t voltage, uint32_t minVoltage, uint32_t maxVoltage) {
	// slow
	// uint8_t result = 110 - (110 / (1 + pow(1.468 * (voltage - minVoltage)/(maxVoltage - minVoltage), 6)));

	// steep
	// uint8_t result = 102 - (102 / (1 + pow(1.621 * (voltage - minVoltage)/(maxVoltage - minVoltage), 8.1)));

	// normal
	uint8_t result = 105 - (105 / (1 + pow(1.724 * (voltage - minVoltage)/(maxVoltage - minVoltage), 5.5)));
	return result >= 100 ? 100 : result;
}

/**
 * Asymmetric sigmoidal approximation
 * https://www.desmos.com/calculator/oyhpsu8jnw
 *
 * c - c / [1 + (k*x/v)^4.5]^3
 */
static inline uint8_t asigmoidal(uint32_t voltage, uint32_t minVoltage, uint32_t maxVoltage) {
	uint8_t result = 101 - (101 / pow(1 + pow(1.33 * (voltage - minVoltage)/(maxVoltage - minVoltage) ,4.5), 3));
	return result >= 100 ? 100 : result;
}

/**
 * Linear mapping
 * https://www.desmos.com/calculator/sowyhttjta
 *
 * x * 100 / v
 */
static inline uint8_t linear(uint32_t voltage, uint32_t minVoltage, uint32_t maxVoltage) {
	return (unsigned long)(voltage - minVoltage) * 100 / (maxVoltage - minVoltage);
}
#endif // BATTERY_H_