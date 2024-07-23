#pragma once

#define MAX_ITEMS 10
#define MAX_REVIEWERS 10

void initializeReviews(float reviews[MAX_ITEMS][MAX_REVIEWERS]);
void addReview(float reviews[MAX_ITEMS][MAX_REVIEWERS], int itemIndex, float score);