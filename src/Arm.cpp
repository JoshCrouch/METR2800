#include "Arm.h"
#include "Pins.h"

/*!
 *  @brief  Instantiates a new Arm, while taking the 
 *  @param  arm_number Number the arm is
 */
Arm::Arm(int arm_number) {
    switch (arm_number) {
        case 1:
            this->LS1 = LS11;
            this->LS2 = LS12;
            this->LS3 = LS13;
            this->LS4 = LS14;
        case 2:
            this->LS1 = LS21;
            this->LS2 = LS22;
            this->LS3 = LS23;
            this->LS4 = LS24;
        case 3:
            this->LS1 = LS31;
            this->LS2 = LS32;
            this->LS3 = LS33;
            this->LS4 = LS34;
        case 4:
            this->LS1 = LS41;
            this->LS2 = LS42;
            this->LS3 = LS43;
            this->LS4 = LS44;
        case 5:
            this->LS1 = LS51;
            this->LS2 = LS52;
            this->LS3 = LS53;
            this->LS4 = LS54;
        case 6:
            this->LS1 = LS61;
            this->LS2 = LS62;
            this->LS3 = LS63;
            this->LS4 = LS64;
    }
}