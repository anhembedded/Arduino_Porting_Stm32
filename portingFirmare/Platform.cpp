//
// Created by pcx on 3/23/2022.
//

#include "Platform.hpp"


// HARDWARE SERIAL



//PF_GPIO_T& PF_GPIO_T::operator=(const PF_GPIO_T &var) = default;

bool PF_GPIO_T::operator==(const PF_GPIO_T &var) const
{
    return ((this->pin == var.pin) && (this->port == var.port));
}

bool PF_GPIO_T::operator!=(const PF_GPIO_T &var) const {
    return ((this->pin == var.pin) || (this->port == var.port));
}



 