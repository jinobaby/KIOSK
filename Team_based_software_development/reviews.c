#include "reviews.h"

// Initialize the reviews array
void initializeReviews(float reviews[MAX_ITEMS][MAX_REVIEWERS]) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        for (int j = 0; j < MAX_REVIEWERS; ++j) {
            reviews[i][j] = -1.0; // Initialize to -1 to indicate no review
        }
    }
}


void addReview(float reviews[MAX_ITEMS][MAX_REVIEWERS], int itemIndex, float score) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        for (int j = 0; j < MAX_REVIEWERS; ++j) {
            reviews[i][j] = score; // Initialize to -1 to indicate no review
        }
    }

}
