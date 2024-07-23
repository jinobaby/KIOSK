#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "implementation.h"
#include <stdlib.h>
#include <time.h>
float computeSubtotal(MenuItem orderedItems[], int orderCount);
float calculateTip(float subtotal, int tipOption);
float calculateTipCustom(float subtotal, int tipOption, float customTip);
